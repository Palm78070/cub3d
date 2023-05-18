#include "cub3d.h"

int isLimit(float x, float y)
{
  // printf("check x %f\n", x);
  // printf("y before break %f\n", y);
  if (mstr.ray.isX == -1)
    return (0);
  else if (mstr.ray.isX)
  {
    // printf("check limit x %i\n", (int)x);
    // printf("check limitX %f\n", mstr.ray.lmtX);
    return ((int)x == mstr.ray.lmt.x);
  }
  else
    return ((int)y == mstr.ray.lmt.y);
}

void ft_pixel_put(int x, int y, int color)
{
  char *dst;

  if (x < 0 || x >= SC_W || y < 0 || y >= SC_H)
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
  if (mstr.ray.rayN == 9)
    printf("check step %i\n", step);
  while (step-- >= 0)
  {
    // if (mstr.ray.rayN == 9)
    //   printf("check x %f\n", x0);
    ft_pixel_put(x0, y0, mstr.color);
    x0 += Xinc;
    y0 += Yinc;
    if (mstr.ray.lmt.x != INFINITY && isLimit(x0, y0))
    {
      if (mstr.ray.isX)
        printf("hit side x\n");
      else
        printf("hit side y\n");
      // printf("last x %f\n", x0 - Xinc);
      printf("last x %f\n", x0);
      printf("last y %f\n", y0);
      // mstr.ray.lmtX = x0 -= Xinc;
      //  mstr.ray.lmtY = y0 -= Yinc;
      //  mstr.color = 0x90EE90;
      //  line(x0, mstr.ray.lmtY, x0, mstr.ray.posY);
      //  mstr.color = 0xFFFFFF;
      break;
    }
  }
  mstr.ray.lmt.x = x0;
  mstr.ray.lmt.y = y0;
}