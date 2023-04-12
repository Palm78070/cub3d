#include "cub3d.h"

void rayBorder(float endX, float endY)
{
 float len_dirVec;
 float posY;
 float posX;

 posX = mstr.vec.posX;
 posY = mstr.vec.posY;
 len_dirVec = fabs(posY - endY);
 mstr.color = 0xFF0000;
 line(endX, endY, endX - len_dirVec, endY);
 line(endX, endY, endX + len_dirVec, endY);
 mstr.color = 0xFFFFFF;
}

void drawRay(int dstX, int dstY)
{
 float endX;
 float endY;
 float posY;
 float posX;

 posY = mstr.vec.posY;
 posX = mstr.vec.posX;
 endX = posX + (mstr.vec.rayDirX * dstX);
 endY = posY + (mstr.vec.rayDirY * dstY);
 ////////////////////////////////////////////
 mstr.vec.sideDstX = endX;
 mstr.vec.sideDstY = endY;
 ////////////////////////////////////////////
 printf("ZZZendX : %f endY: %f\n", endX, endY);
 line(posX, posY, endX, endY);
 if (mstr.vec.rayDirX == 0)
  rayBorder(endX, endY);
}

void raycast(int tireX, int tireY)
{
 int hitWall;
 float dstX;
 float dstY;
 int floorY;
 int floorX;

 hitWall = 0;
 dstX = 0;
 dstY = 0;
 // if (mstr.vec.rayDirX == 0)
 //  mstr.vec.rayDirX = 0;
 // if (mstr.vec.rayDirY == 0)
 //  mstr.vec.rayDirY = 0;
 printf("posX - sc_w %f\n", mstr.vec.posX - mstr.map.sc_w);
 // mstr.vec.deltaDstX = sqrt(fabs(mstr.vec.posX - mstr.map.sc_w) + pow(mstr.vec.rayDirY / mstr.vec.rayDirX, 2));
 // if (mstr.vec.deltaDstX != INFINITY)
 //  mstr.vec.deltaDstX = 24;
 // // mstr.vec.deltaDstX = 20.726028;
 // printf("length %f\n", fabs(mstr.vec.posX - mstr.map.sc_w));
 // mstr.vec.deltaDstY = sqrt(fabs(mstr.vec.posY - mstr.map.sc_h) + pow(mstr.vec.rayDirX / mstr.vec.rayDirY, 2));
 mstr.vec.deltaDstX = sqrt(1 + pow(mstr.vec.rayDirY / mstr.vec.rayDirX, 2));
 mstr.vec.deltaDstY = sqrt(1 + pow(mstr.vec.rayDirX / mstr.vec.rayDirY, 2));
 printf("deltaDstY %f\n", mstr.vec.deltaDstY);
 printf("deltaDstX %f\n", mstr.vec.deltaDstX);
 /////////////////////////////////////////
 // mstr.vec.deltaDstY = roundf(mstr.vec.deltaDstY);
 // mstr.vec.deltaDstX = roundf(mstr.vec.deltaDstX);
 // printf("deltaDstY %f\n", mstr.vec.deltaDstY);
 // printf("deltaDstX %f\n", mstr.vec.deltaDstX);
 /////////////////////////////////////////
 if (mstr.vec.rayDirX < 0)
 {
  printf("zzz1\n");
  mstr.vec.stepX = -1;
  mstr.vec.sideDstX = (mstr.map.tireSz / 2) * mstr.vec.deltaDstX;
  //  mstr.vec.sideDstX = fabs(mstr.vec.posX - mstr.map.sc_w);
  // mstr.vec.sideDstX = mstr.vec.deltaDstX;
  printf("sideDstX %f\n", mstr.vec.sideDstX);
  // hitWall = 1;
 }
 else
 {
  printf("zzz2\n");
  mstr.vec.stepX = 1;
  mstr.vec.sideDstX = (mstr.map.tireSz / 2) * mstr.vec.deltaDstX;
  //   mstr.vec.sideDstX = fabs(mstr.vec.posX - mstr.map.sc_w);
  // mstr.vec.sideDstX = mstr.vec.deltaDstX;
  printf("sideDstX %f\n", mstr.vec.sideDstX);
  // hitWall = 1;
 }
 if (mstr.vec.rayDirY < 0)
 {
  printf("zzz3\n");
  mstr.vec.stepY = -1;
  mstr.vec.sideDstY = (mstr.map.tireSz / 2) * mstr.vec.deltaDstY;
  //   mstr.vec.sideDstY = fabs(mstr.vec.posY - mstr.map.sc_h);
  // mstr.vec.sideDstY = mstr.vec.deltaDstY;
  printf("sideDstY %f\n", mstr.vec.sideDstY);
  // hitWall = 1;
 }
 else
 {
  printf("zzz4\n");
  mstr.vec.stepY = 1;
  mstr.vec.sideDstY = (mstr.map.tireSz / 2) * mstr.vec.deltaDstY;
  //   mstr.vec.sideDstY = fabs(mstr.vec.posY - mstr.map.sc_h);
  // mstr.vec.sideDstY = mstr.vec.deltaDstY;
  printf("sideDstY %f\n", mstr.vec.sideDstY);
  // hitWall = 1;
 }
 floorY = 15;
 floorX = 15;
 while (hitWall == 0)
 {
  printf("xxx\n");
  if (mstr.vec.sideDstX < mstr.vec.sideDstY)
  {
   printf("ppp1\n");
   tireX += mstr.vec.stepX;
   dstX += mstr.vec.sideDstX;
   // mstr.vec.sideDstX += (mstr.map.tireSz * roundf(mstr.vec.deltaDstX));
   floorX += mstr.map.tireSz;
   mstr.vec.sideDstX += (mstr.map.tireSz * (mstr.vec.deltaDstX));
   floorX += mstr.map.tireSz;
   //  mstr.vec.sideDstX += (mstr.vec.deltaDstX);
   printf("map[%i][%i]\n", tireY, tireX);
  }
  else if (mstr.vec.sideDstY != 0)
  {
   printf("ppp2\n");
   tireY += mstr.vec.stepY;
   dstY = mstr.vec.sideDstY;
   // mstr.vec.sideDstY += (mstr.map.tireSz * roundf(mstr.vec.deltaDstY));
   mstr.vec.sideDstY += (mstr.map.tireSz * (mstr.vec.deltaDstY));
   floorY += mstr.map.tireSz;
   //  mstr.vec.sideDstY += (mstr.vec.deltaDstY);
   printf("map[%i][%i]\n", tireY, tireX);
  }
  /////////////////////////////////////
  // hitWall = 1;
  /////////////////////////////////////
  if (input_ok(tireX, tireY))
   if (mstr.map.map[tireY][tireX] == '1')
   {
    printf("hit wall map[%i][%i]\n", tireY, tireX);
    hitWall = 1;
   }
 }
 printf("end sideDstY %f\n", mstr.vec.sideDstY);
 printf("end sideDstX %f\n", mstr.vec.sideDstX);
 ///////////////////////////////////////////////
 mstr.vec.sideDstY -= mstr.map.tireSz;
 floorY -= mstr.map.tireSz;
 floorX -= (mstr.map.tireSz / 2);
 printf("XXXend sideDstY %f\n", mstr.vec.sideDstY);
 printf("XXXend floorY %i\n", floorY);
 printf("XXXend floorX %i\n", floorX);
 mstr.color = 0xFF0000;
 // line(mstr.vec.posX, mstr.vec.posY, mstr.vec.posX + (round(mstr.vec.rayDirX) * floorX), mstr.vec.posY - floorY);
 mstr.color = 0xFFFFFF;
 ///////////////////////////////////////////////
 if (hitWall == 1)
  drawRay(mstr.vec.sideDstX, mstr.vec.sideDstY);
 // drawRay(dstX, dstY);
}

void raycast2(void)
{
 int x;
 int w;

 x = 0;
 w = 20;
 while (x < w)
 {
  printf("\nray %i\n\n", x + 1);
  printf("map[%i][%i]\n", mstr.vec.tireY, mstr.vec.tireX);
  mstr.vec.camX = ((2 * x) / (float)w) - 1;
  printf("camX %f\n", mstr.vec.camX);
  printf("dirX %f planeX %f camX %f\n", mstr.vec.dirX, mstr.vec.planeX, mstr.vec.camX);
  mstr.vec.rayDirX = mstr.vec.dirX + (mstr.vec.planeX * mstr.vec.camX);
  mstr.vec.rayDirY = mstr.vec.dirY + (mstr.vec.planeY * mstr.vec.camX);
  printf("rayDirX %f rayDirY %f\n", mstr.vec.rayDirX, mstr.vec.rayDirY);
  // if (x == 0)
  raycast(mstr.vec.tireX, mstr.vec.tireY);
  ++x;
 }
 printf("\nray %i\n\n", x + 1);
 mstr.vec.camX = 1;
 mstr.vec.rayDirX = mstr.vec.dirX + (mstr.vec.planeX * mstr.vec.camX);
 mstr.vec.rayDirY = mstr.vec.dirY + (mstr.vec.planeY * mstr.vec.camX);
 raycast(mstr.vec.tireX, mstr.vec.tireY);
}
//////////////////////////////////////////////////////////////////////
// void rayBorder2(float endX, float endY)
// {
//  float len_dirVec;
//  float posY;
//  float posX;

//  posX = mstr.vec.posX;
//  posY = mstr.vec.posY;
//  len_dirVec = fabs(posY - endY);
//  mstr.color = 0xFF0000;
//  line(endX, endY, endX - len_dirVec, endY);
//  line(endX, endY, endX + len_dirVec, endY);
//  mstr.color = 0xFFFFFF;
// }

// void drawRay2(float dstX, float dstY)
// {
//  float posX;
//  float posY;
//  float endX;
//  float endY;

//  posY = mstr.vec.posY;
//  posX = mstr.vec.posX;
//  printf("dstX %f\n", dstX);
//  printf("dstY %f\n", dstY);
//  endX = posX + mstr.vec.rayDirX * (dstX - (mstr.map.tireSz / 2));
//  endY = posY + mstr.vec.rayDirY * (dstY - (mstr.map.tireSz / 2));
//  line(posX, posY, endX, endY);
//  if (mstr.vec.rayDirX == 0)
//   rayBorder2(endX, endY);
// }

// void raycast(int tireX, int tireY)
// {
//  int hitWall;
//  float dstX;
//  float dstY;
//  // float posY;

//  hitWall = 0;
//  dstX = 0;
//  dstY = 0;
//  // mstr.vec.rayDirX = 0;
//  // mstr.vec.rayDirY = -1;
//  if (mstr.vec.rayDirX == 0)
//   mstr.vec.rayDirX = 0;
//  if (mstr.vec.rayDirY == 0)
//   mstr.vec.rayDirY = 0;
//  mstr.vec.deltaDstX = 0;
//  mstr.vec.deltaDstY = 0;
//  printf("deltaDstY %f\n", mstr.vec.deltaDstY);
//  printf("deltaDstX %f\n", mstr.vec.deltaDstX);
//  if (mstr.vec.rayDirX < 0)
//  {
//   printf("zzz1\n");
//   mstr.vec.stepX = -1;
//   // mstr.vec.sideDstX = (mstr.vec.posX - tireX) * mstr.vec.deltaDstX;
//   mstr.vec.sideDstX = (mstr.map.tireSz);
//   printf("sideDstX %f\n", mstr.vec.sideDstX);
//  }
//  else if (mstr.vec.rayDirX == 0)
//  {
//   mstr.vec.stepX = 0;
//   mstr.vec.sideDstX = 0;
//  }
//  else
//  {
//   printf("zzz2\n");
//   mstr.vec.stepX = 1;
//   // mstr.vec.sideDstX = (tireX + 1.0 - mstr.vec.posX) * mstr.vec.deltaDstX;
//   mstr.vec.sideDstX = (mstr.map.tireSz);
//   printf("sideDstX %f\n", mstr.vec.sideDstX);
//  }
//  if (mstr.vec.rayDirY < 0)
//  {
//   printf("zzz3\n");
//   mstr.vec.stepY = -1;
//   // mstr.vec.sideDstY = (mstr.vec.posY - tireY) * mstr.vec.deltaDstY;
//   mstr.vec.sideDstY = (mstr.map.tireSz);
//   printf("sideDstY %f\n", mstr.vec.sideDstY);
//  }
//  else
//  {
//   printf("zzz4\n");
//   mstr.vec.stepY = 1;
//   // mstr.vec.sideDstY = (tireY + 1.0 - mstr.vec.posY) * mstr.vec.deltaDstY;
//   mstr.vec.sideDstY = (mstr.map.tireSz);
//   printf("sideDstY %f\n", mstr.vec.sideDstY);
//  }
//  while (hitWall == 0)
//  {
//   printf("xxx\n");
//   if (mstr.vec.sideDstX != 0 && mstr.vec.sideDstX < mstr.vec.sideDstY)
//   {
//    printf("ppp1\n");
//    tireX += mstr.vec.stepX;
//    dstX += mstr.vec.sideDstX;
//    // mstr.vec.sideDstX += mstr.vec.deltaDstX;
//    mstr.vec.sideDstX += (mstr.map.tireSz);
//   }
//   else
//   {
//    printf("ppp2\n");
//    tireY += mstr.vec.stepY;
//    dstY = mstr.vec.sideDstY;
//    // dstY += mstr.map.tireSz;
//    mstr.vec.sideDstY += (mstr.map.tireSz);
//   }
//   if (input_ok(tireX, tireY))
//    if (mstr.map.map[tireY][tireX] == '1')
//    {
//     printf("hit wall map[%i][%i]\n", tireY, tireX);
//     hitWall = 1;
//    }
//  }
//  printf("end sideDstY %f\n", mstr.vec.sideDstY);
//  printf("end sideDstX %f\n", mstr.vec.sideDstX);
//  if (hitWall == 1)
//   drawRay2(dstX, dstY);
// }

// void raycast2(void)
// {
//  mstr.vec.rayDirX = 0;
//  mstr.vec.rayDirY = -1;
//  raycast(mstr.vec.tireX, mstr.vec.tireY);
//  printf("OOOplane %f\n", mstr.vec.planeX);
//  mstr.vec.rayDirX += 0.61;
//  raycast(mstr.vec.tireX, mstr.vec.tireY);
// }

// else if (mstr.vec.rayDirX == 0)
// {
//  mstr.vec.stepX = 0;
//  mstr.vec.sideDstX = 0;
//  // hitWall = 1;
// }