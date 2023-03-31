#include "cub3d.h"

void raycast(void)
{
 printf("In raycast function\n");
 int x;
 int hit;
 int side;

 x = 0;
 while (x < mstr.map.tireSz)
 {
  printf("x %i\n", x);
  mstr.vec.camX = (2 * x++) / (float)mstr.map.tireSz - 1;
  mstr.vec.rayDirX = mstr.vec.dirX + mstr.vec.planeX * mstr.vec.camX;
  mstr.vec.rayDirY = mstr.vec.dirY + mstr.vec.planeY * mstr.vec.camX;
  ///////////////////////////////
  mstr.vec.mapX = mstr.vec.tireX;
  mstr.vec.mapY = mstr.vec.tireY;
  if (mstr.vec.rayDirX == 0 || mstr.vec.rayDirY == 0)
   break;
  // printf("undefined\n");
  mstr.vec.deltaDstX = fabs(1 / mstr.vec.rayDirX);
  mstr.vec.deltaDstY = fabs(1 / mstr.vec.rayDirY);
  if (mstr.vec.rayDirX < 0)
  {
   mstr.vec.stepX = -1;
   mstr.vec.sideDstX = (mstr.vec.posX - mstr.vec.tireX) * mstr.vec.deltaDstX;
  }
  else
  {
   mstr.vec.stepX = 1;
   mstr.vec.sideDstX = (mstr.vec.tireX + 1.0 - mstr.vec.posX) * mstr.vec.deltaDstX;
  }
  if (mstr.vec.rayDirY < 0)
  {
   mstr.vec.stepY = -1;
   mstr.vec.sideDstY = (mstr.vec.posY - mstr.vec.tireY) * mstr.vec.deltaDstY;
  }
  else
  {
   mstr.vec.stepY = 1;
   mstr.vec.sideDstY = (mstr.vec.tireY + 1.0 - mstr.vec.posY) * mstr.vec.deltaDstY;
  }
  while (hit == 0)
  {
   if (mstr.vec.sideDstX < mstr.vec.sideDstY)
   {
    mstr.vec.sideDstX += mstr.vec.deltaDstX;
    mstr.vec.mapX += mstr.vec.stepX;
    side = 0;
   }
   else
   {
    mstr.vec.sideDstY += mstr.vec.deltaDstY;
    mstr.vec.mapY += mstr.vec.stepY;
    side = 1;
   }
   if (mstr.map.map[mstr.vec.mapY][mstr.vec.mapX] == '1')
    hit = 1;
  }
  if (side == 0)
   mstr.vec.ppWallDst = (mstr.vec.sideDstX - mstr.vec.deltaDstX);
  else
   mstr.vec.ppWallDst = (mstr.vec.sideDstY - mstr.vec.deltaDstY);
  printf("before draw line ray\n");
  line(mstr.vec.posX, mstr.vec.posY, mstr.vec.sideDstX, mstr.vec.sideDstY);
  mlx_put_image_to_window(&mstr, mstr.mlx.win, mstr.mlx.img_ptr, 0, 0);
 }
 printf("break loop\n");
}