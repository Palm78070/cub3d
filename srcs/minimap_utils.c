#include "cub3d.h"

static int free_mem(char **s, int indx)
{
  if (!s[indx])
  {
    while (indx > 0)
      free(s[indx--]);
    free(s);
    return (1);
  }
  return (0);
}

char **dup_map(void)
{
  int h;

  h = -1;
  char **map;

  map = (char **)malloc(sizeof(char *) * mstr.map.mapH);
  if (!map)
    ft_error("Error to malloc double array of map_tmp\n");
  while (++h < mstr.map.mapH)
  {
    map[h] = ft_strdup(mstr.map.map[h]);
    if (!map[h])
      free_mem(map, h);
  }
  return (map);
}

void re_init_map(void)
{
  int h;
  int w;

  h = -1;
  w = -1;
  while (++h < mstr.map.mapH)
  {
    w = -1;
    while (++w < (int)ft_strlen(mstr.map.map[h]) - 1)
    {
      if (is_keyword(mstr.map.map[h][w]))
        mstr.map.tmp[h][w] = '0';
      else
        mstr.map.tmp[h][w] = mstr.map.map[h][w];
    }
  }
}

int input_ok(int tireX, int tireY)
{
  if (mstr.map.tmp == NULL || mstr.map.mapW < 0 || mstr.map.mapH < 0)
    return (0);
  if (tireX < 0 || tireY < 0 || tireY > mstr.map.mapH - 1 || tireX > (int)ft_strlen(mstr.map.tmp[tireY]) - 2)
    return (0);
  return (1);
}

void fill_zone(int tireX, int tireY, int imgPosX, int imgPosY)
{
  int tireSz;
  char **map;

  tireSz = mstr.map.tireSz;
  map = mstr.map.tmp;
  if (!input_ok(tireX, tireY) || imgPosX < 0 || imgPosY < 0)
    return;
  if (map[tireY][tireX] == '2')
    return;
  if (map[tireY][tireX] == '1')
    draw_wall(imgPosX, imgPosY);
  map[tireY][tireX] = '2';
  draw_tire(imgPosX, imgPosY);
  // left
  if (input_ok(tireX - 1, tireY) && map[tireY][tireX - 1] != '2')
    fill_zone(tireX - 1, tireY, imgPosX - tireSz, imgPosY);
  // right
  if (input_ok(tireX + 1, tireY) && map[tireY][tireX + 1] != '2')
    fill_zone(tireX + 1, tireY, imgPosX + tireSz, imgPosY);
  // top
  if (input_ok(tireX, tireY - 1) && map[tireY - 1][tireX] != '2')
    fill_zone(tireX, tireY - 1, imgPosX, imgPosY - tireSz);
  // down
  if (input_ok(tireX, tireY + 1) && map[tireY + 1][tireX] != '2')
    fill_zone(tireX, tireY + 1, imgPosX, imgPosY + tireSz);
}

void flood_tire(void)
{
  int tireX;
  int tireY;

  tireX = mstr.vec.tireX;
  tireY = mstr.vec.tireY;
  if (mstr.map.tmp == NULL)
    mstr.map.tmp = dup_map();
  else
    re_init_map();
  if (!input_ok(tireX, tireY))
    return;
  fill_zone(tireX, tireY, mstr.vec.img_posX, mstr.vec.img_posY);
}