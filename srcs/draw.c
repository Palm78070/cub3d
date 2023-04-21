#include "cub3d.h"

int isLimit(float x, float y)
{
  // printf("check x %f\n", x);
  // printf("y before break %f\n", y);
  if (mstr.vec.isX == -1)
    return (0);
  else if (mstr.vec.isX)
  {
    // printf("check limit x %i\n", (int)x);
    // printf("check limitX %f\n", mstr.vec.lmtX);
    return ((int)x == mstr.vec.lmtX);
  }
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
  if (mstr.vec.rayN == 9)
    printf("check step %i\n", step);
  while (step-- >= 0)
  {
    // if (mstr.vec.rayN == 9)
    //   printf("check x %f\n", x0);
    ft_pixel_put(x0, y0, mstr.color);
    x0 += Xinc;
    y0 += Yinc;
    if (mstr.vec.lmtX != INFINITY && isLimit(x0, y0))
    {
      printf("last x %f\n", x0 - Xinc);
      mstr.vec.lmtX = x0 -= Xinc;
      // mstr.color = 0x90EE90;
      // line(x0, mstr.vec.lmtY, x0, mstr.vec.posY);
      // mstr.color = 0xFFFFFF;
      break;
    }
  }
}