#include "cub3d.h"

void draw_tire(int x, int y)
{
 int tire_w;
 int tire_h;

 tire_w = mstr.map.tire_w;
 tire_h = mstr.map.tire_h;
 line(x, y, x, y + tire_h);
 line(x, y, x + tire_w, y);
 x += tire_w;
 line(x, y, x, y + tire_h);
 y += tire_h;
 line(x, y, x - tire_w, y);
}

void draw_minimap(int x, int y)
{
 int w;
 int h;

 w = -1;
 h = -1;
 while (++h < mstr.map.mapH)
 {
  w = -1;
  x = 0;
  while (++w < mstr.map.mapW)
  {
   if (mstr.map.map[h][w] && is_keyword(mstr.map.map[h][w]))
   {
    printf("found keyword %c\n", mstr.map.map[h][w]);
    printf("player pos x %i\n", x + mstr.map.tire_w);
    printf("player pos y %i\n", y + mstr.map.tire_h);
    mstr.vector.tireX = w;
    mstr.vector.tireY = h;
    mstr.vector.posX = x + (mstr.map.tire_w / 2);
    mstr.vector.posY = y + (mstr.map.tire_h / 2);
    line(x, y, (x + mstr.map.tire_w / 2), y + (mstr.map.tire_h / 2));
   }
   draw_tire(x, y);
   x += mstr.map.tire_w;
  }
  y += mstr.map.tire_h;
 }
 mlx_put_image_to_window(&mstr, mstr.mlx.win, mstr.mlx.img_ptr, 0, 0);
}