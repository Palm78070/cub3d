#include "cub3d.h"

int lmt0(float n)
{
 return ((n > -0.25 && n <= 0) || (n >= 0.1 && n < 0.25));
}

void walkUp(void)
{
 int x;
 int y;

 x = mstr.ray.tire.ix;
 y = mstr.ray.tire.iy;
 if ((mstr.ray.dir.y >= -1 && mstr.ray.dir.y <= -0.25))
  y -= 1;
 if (mstr.ray.dir.y >= 0.25 && mstr.ray.dir.y <= 1)
  y += 1;
 if (mstr.ray.dir.x >= -1 && mstr.ray.dir.x <= -0.25)
  x -= 1;
 if (mstr.ray.dir.x >= 0.25 && mstr.ray.dir.x <= 1)
  x += 1;
 if (input_ok(x, y) && mstr.map.map[y][x] == '1')
  return;
 mstr.ray.tire.ix = x;
 mstr.ray.tire.iy = y;
 re_draw();
}

void walkDown(void)
{
 int x;
 int y;

 x = mstr.ray.tire.ix;
 y = mstr.ray.tire.iy;
 if ((mstr.ray.dir.y >= -1 && mstr.ray.dir.y <= -0.25))
  y += 1;
 if (mstr.ray.dir.y >= 0.25 && mstr.ray.dir.y <= 1)
  y -= 1;
 if (mstr.ray.dir.x >= -1 && mstr.ray.dir.x <= -0.25)
  x += 1;
 if (mstr.ray.dir.x >= 0.25 && mstr.ray.dir.x <= 1)
  x -= 1;
 if (input_ok(x, y) && mstr.map.map[y][x] == '1')
  return;
 mstr.ray.tire.ix = x;
 mstr.ray.tire.iy = y;
 re_draw();
}

void walkLeft(void)
{
 printf("????????In walkLeft??????????\n");
 int x;
 int y;
 float tmpDirX;

 x = mstr.ray.tire.ix;
 y = mstr.ray.tire.iy;
 tmpDirX = mstr.ray.dir.x;
 // nomalise();
 if ((mstr.ray.dir.y >= -1 && mstr.ray.dir.y <= -0.25) && (mstr.ray.dir.x >= -1 && mstr.ray.dir.x <= -0.25) && ++y) // Left Down
 {
  printf("//////////////Left Down////////////////\n");
  x -= 1;
 }
 else if ((mstr.ray.dir.y >= -1 && mstr.ray.dir.y <= -0.25) && (mstr.ray.dir.x >= 0.25 && mstr.ray.dir.x <= 1) && --y) // Left Up
 {
  printf("//////////////Left Up////////////////\n");
  x -= 1;
 }
 else if ((mstr.ray.dir.y >= 0.25 && mstr.ray.dir.y <= 1) && (mstr.ray.dir.x >= 0.25 && mstr.ray.dir.x <= 1) && --y) // Right up
 {
  printf("//////////////Right Up////////////////\n");
  x += 1;
 }
 else if ((mstr.ray.dir.y >= 0.25 && mstr.ray.dir.y <= 1) && (mstr.ray.dir.x >= -1 && mstr.ray.dir.x <= -0.25) && ++y) // Right down
 {
  printf("//////////////Right Down////////////////\n");
  x += 1;
 }
 else if (lmt0(mstr.ray.dir.x))
  x -= 1;
 else if (mstr.ray.dir.x != 0 && mstr.ray.dir.x < 0)
  y += 1;
 else if (mstr.ray.dir.x != 0 && mstr.ray.dir.x > 0)
  y -= 1;
 if (input_ok(x, y) && mstr.map.map[y][x] == '1')
  return;
 mstr.ray.tire.ix = x;
 mstr.ray.tire.iy = y;
 mstr.ray.dir.x = tmpDirX;
 re_draw();
}

void walkRight(void)
{
 int x;
 int y;
 float tmpDirX;

 x = mstr.ray.tire.ix;
 y = mstr.ray.tire.iy;
 tmpDirX = mstr.ray.dir.x;
 // nomalise();
 if ((mstr.ray.dir.y >= -1 && mstr.ray.dir.y <= -0.25) && (mstr.ray.dir.x >= -1 && mstr.ray.dir.x <= -0.25) && --y) // Right Up
  x += 1;
 else if ((mstr.ray.dir.y >= -1 && mstr.ray.dir.y <= -0.25) && (mstr.ray.dir.x >= 0.25 && mstr.ray.dir.x <= 1) && ++y) // Right Down
  x += 1;
 else if ((mstr.ray.dir.y >= 0.25 && mstr.ray.dir.y <= 1) && (mstr.ray.dir.x >= 0.25 && mstr.ray.dir.x <= 1) && ++y) // Left Down
  x -= 1;
 else if ((mstr.ray.dir.y >= 0.25 && mstr.ray.dir.y <= 1) && (mstr.ray.dir.x >= -1 && mstr.ray.dir.x <= -0.25) && --y) // Left Up
  x -= 1;
 else if (lmt0(mstr.ray.dir.x))
  x += 1;
 else if (mstr.ray.dir.x != 0 && mstr.ray.dir.x < 0)
  y -= 1;
 else if (mstr.ray.dir.x != 0 && mstr.ray.dir.x > 0)
  y += 1;
 if (input_ok(x, y) && mstr.map.map[y][x] == '1')
  return;
 mstr.ray.tire.ix = x;
 mstr.ray.tire.iy = y;
 mstr.ray.dir.x = tmpDirX;
 re_draw();
}