#include "cub3d.h"

int lmt0(float n)
{
 return ((n > -0.25 && n <= 0) || (n >= 0.1 && n < 0.25));
}

int blindSpot(int x, int y)
{
 // if (!input_ok(x - 1, y) && !input_ok(x, y - 1))
 //  return (mstr.map.map[y + 1][x] == '1' && mstr.map.map[y][x + 1] == '1');
 // if (!input_ok(x + 1, y) && !input_ok(x, y - 1))
 //  return (mstr.map.map[y + 1][x] == '1' && mstr.map.map[y][x - 1] == '1');
 // if (!input_ok(x - 1, y) && !input_ok(x, y + 1))
 //  return (mstr.map.map[y - 1][x] == '1' && mstr.map.map[y][x + 1] == '1');
 // if (!input_ok(x + 1, y) && !input_ok(x, y + 1))
 //  return (mstr.map.map[y - 1][x] == '1' && mstr.map.map[y][x - 1] == '1');
 printf("\n///////////////Blind spot///////////////////\n");
 int diagonal;
 int stepDirX;
 int stepDirY;

 diagonal = (mstr.ray.tire.ix != x && mstr.ray.tire.iy != y);
 if (!diagonal)
  return (0);
 stepDirX = x - mstr.ray.tire.ix;
 stepDirY = y - mstr.ray.tire.iy;
 printf("stepDirX: %i stepDirY: %i\n", stepDirX, stepDirY);
 if (stepDirY < 0 && stepDirX > 0)
  return (mstr.map.map[y + 1][x] == '1' && mstr.map.map[y][x - 1] == '1');
 if (stepDirY < 0 && stepDirX < 0)
  return (mstr.map.map[y + 1][x] == '1' && mstr.map.map[y][x + 1] == '1');
 if (stepDirY > 0 && stepDirX < 0)
  return (mstr.map.map[y - 1][x] == '1' && mstr.map.map[y][x + 1] == '1');
 if (stepDirY > 0 && stepDirX > 0)
  return (mstr.map.map[y - 1][x] == '1' && mstr.map.map[y][x - 1] == '1');
 return (0);
}

void walkUp(void)
{
 int x;
 int y;

 x = mstr.ray.tire.ix;
 y = mstr.ray.tire.iy;
 if ((mstr.ray.dir.y >= -1 && mstr.ray.dir.y <= -0.25))
  y -= 1;
 else if (mstr.ray.dir.y >= 0.25 && mstr.ray.dir.y <= 1)
  y += 1;
 if (mstr.ray.dir.x >= -1 && mstr.ray.dir.x <= -0.25)
  x -= 1;
 else if (mstr.ray.dir.x >= 0.25 && mstr.ray.dir.x <= 1)
  x += 1;
 if ((input_ok(x, y) && mstr.map.map[y][x] == '1') || blindSpot(x, y))
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
 else if (mstr.ray.dir.y >= 0.25 && mstr.ray.dir.y <= 1)
  y -= 1;
 if (mstr.ray.dir.x >= -1 && mstr.ray.dir.x <= -0.25)
  x += 1;
 else if (mstr.ray.dir.x >= 0.25 && mstr.ray.dir.x <= 1)
  x -= 1;
 if ((input_ok(x, y) && mstr.map.map[y][x] == '1') || blindSpot(x, y))
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

 x = mstr.ray.tire.ix;
 y = mstr.ray.tire.iy;
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
 else if (mstr.ray.dir.x == -1 && (mstr.ray.dir.y > -0.25 && mstr.ray.dir.y < 0.25))
  y += 1;
 else if (mstr.ray.dir.x == 1 && (mstr.ray.dir.y > -0.25 && mstr.ray.dir.y < 0.25))
  y -= 1;
 if ((input_ok(x, y) && mstr.map.map[y][x] == '1') || blindSpot(x, y))
  return;
 mstr.ray.tire.ix = x;
 mstr.ray.tire.iy = y;
 re_draw();
}

void walkRight(void)
{
 int x;
 int y;

 x = mstr.ray.tire.ix;
 y = mstr.ray.tire.iy;
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
 else if (mstr.ray.dir.x == -1 && (mstr.ray.dir.y > -0.25 && mstr.ray.dir.y < 0.25))
  y -= 1;
 else if (mstr.ray.dir.x == 1 && (mstr.ray.dir.y > -0.25 && mstr.ray.dir.y < 0.25))
  y += 1;
 if ((input_ok(x, y) && mstr.map.map[y][x] == '1') || blindSpot(x, y))
  return;
 mstr.ray.tire.ix = x;
 mstr.ray.tire.iy = y;
 re_draw();
}