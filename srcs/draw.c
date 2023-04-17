#include "cub3d.h"

int isLimit(float x, float y)
{
 // printf("check x %f\n", x);
 if (mstr.vec.isX == -1)
  return (0);
 else if (mstr.vec.isX)
  return ((int)x == mstr.vec.lmtX);
 else
  return ((int)y == mstr.vec.lmtY);
}

void ft_pixel_put(int x, int y, int color)
{
 char *dst;

 if (x < 0 || x >= mstr.map.sc_w || y < 0 || y >= mstr.map.sc_h)
  return;
 dst = mstr.mlx.img_addr + (y * mstr.mlx.size_line) + (x * (mstr.mlx.bpp / 8));
 *(unsigned int *)dst = color;
}

int dn(int n0, int n1)
{
 return (n1 - n0);
}

void line(float x0, float y0, float x1, float y1)
{
 int step;
 float Xinc;
 float Yinc;

 if (abs(dn(x0, x1)) > abs(dn(y0, y1)))
  step = abs(dn(x0, x1));
 else
  step = abs(dn(y0, y1));
 Xinc = dn(x0, x1) / (float)step;
 Yinc = dn(y0, y1) / (float)step;
 while (step-- >= 0)
 {
  ft_pixel_put(x0, y0, mstr.color);
  x0 += Xinc;
  y0 += Yinc;
  if (isLimit(x0, y0))
   break;
 }
}