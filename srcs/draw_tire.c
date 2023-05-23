#include "cub3d.h"

int isOutSide(t_point p)
{
 int isOutSide;

 isOutSide = (p.ix < mstr.mnMp.floor.ix || p.ix > mstr.mnMp.ceil.ix || p.iy < mstr.mnMp.floor.iy || p.iy > mstr.mnMp.ceil.iy);
 return (p.ix < 0 || p.iy < 0 || isOutSide);
}

void lineT(t_point p0, t_point p1)
{
 int step;
 float Xinc;
 float Yinc;

 if (abs(dn(p0.ix, p1.ix)) > abs(dn(p0.iy, p1.iy)))
  step = abs(dn(p0.ix, p1.ix));
 else
  step = abs(dn(p0.iy, p1.iy));
 Xinc = dn(p0.ix, p1.ix) / (float)step;
 Yinc = dn(p0.iy, p1.iy) / (float)step;
 while (step-- >= 0 && !(isOutSide(p0)))
 {
  ft_pixel_put(p0.ix, p0.iy, mstr.color);
  p0.ix += Xinc;
  p0.iy += Yinc;
 }
 mstr.ray.lmt.x = p0.ix;
 mstr.ray.lmt.y = p0.iy;
}

void draw_tire(t_point p, int tireX, int tireY)
{
 // printf("p.ix: %i p.iy: %i\n", p.ix, p.iy);
 lineT(p, (t_point){.ix = p.ix, .iy = p.iy + tireSz});
 lineT(p, (t_point){.ix = p.ix + tireSz, .iy = p.iy});
 ////////////////////test//////////////////////////
 (void)tireY;
 if (tireX != 0)
  lineT(p, (t_point){.ix = p.ix - tireSz, .iy = p.iy});
 //////////////////////////////////////////////////
 p.ix += tireSz;
 lineT(p, (t_point){.ix = p.ix, .iy = p.iy + tireSz});
 p.iy += tireSz;
 lineT(p, (t_point){.ix = p.ix - tireSz, .iy = p.iy});
 ////////////////////test//////////////////////////
 if (tireX < (int)ft_strlen(mstr.map.tmp[tireY]) - 2)
  lineT(p, (t_point){.ix = p.ix + tireSz, .iy = p.iy});
}

// void draw_wall(int x, int y)
void draw_wall(t_point p)
{
 // line(x, y, x + tireSz, y + tireSz);
 lineT(p, (t_point){.ix = p.ix + tireSz, p.iy + tireSz});
 // line(x + tireSz, y, x, y + tireSz);
 lineT((t_point){.ix = p.ix + tireSz, .iy = p.iy}, (t_point){.ix = p.ix, .iy = p.iy + tireSz});
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