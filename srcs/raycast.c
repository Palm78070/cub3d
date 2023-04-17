#include "cub3d.h"

void find_limit_pos(int tireX, int tireY)
{
 int tireSz;
 int camX;
 int dstX;
 int dstY;

 tireSz = mstr.map.tireSz;
 if (mstr.vec.camX < 0)
  camX = ceil(mstr.vec.camX * -1) * -1;
 else
  camX = ceil(mstr.vec.camX);
 printf("ceil(camX) %i\n", camX);
 dstX = (camX * (abs(tireX - mstr.vec.tireX) - 1));
 dstY = (abs(tireY - mstr.vec.tireY) - 1);
 if (mstr.vec.isX)
 {
  printf("posX %f\n", mstr.vec.posX);
  printf("(camX * (tireSz / 2)) %i\n", (camX * (tireSz / 2)));
  printf("dstX * tireSz %i\n", dstX * tireSz);
  printf("camX * tireSz %i\n", camX * tireSz);
  mstr.vec.lmtX = mstr.vec.posX - (camX * (tireSz / 2)) + dstX * tireSz + (camX * tireSz);
  printf("floor posX is %f\n", mstr.vec.lmtX);
  printf("player posX %f\n", mstr.vec.posX);
 }
 else
 {
  mstr.vec.lmtY = mstr.vec.posY + (mstr.vec.dirY * (tireSz / 2)) - dstY * tireSz;
  printf("hit y side of the wall distance tireY is %i\n", abs(tireY - mstr.vec.tireY));
  printf("floor posY is %f\n", mstr.vec.lmtY);
  printf("player posY %f\n", mstr.vec.posY);
 }
}

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
 printf("end dstY %i\n", dstY);
 printf("end dstX %i\n", dstX);
 float endX;
 float endY;
 float posY;
 float posX;

 posY = mstr.vec.posY;
 posX = mstr.vec.posX;
 endX = (posX + (mstr.vec.rayDirX * dstX));
 endY = (posY + (mstr.vec.rayDirY * dstY));
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

 hitWall = 0;
 dstX = 0;
 dstY = 0;
 printf("posX - sc_w %f\n", mstr.vec.posX - mstr.map.sc_w);
 // mstr.vec.deltaDstX = sqrt(1 + (pow(mstr.vec.rayDirY, 2) / pow(mstr.vec.rayDirX, 2)));
 // mstr.vec.deltaDstY = sqrt(1 + (pow(mstr.vec.rayDirX, 2) / pow(mstr.vec.rayDirY, 2)));
 mstr.vec.deltaDstX = sqrt(pow(30, 2) + (pow(mstr.vec.rayDirY, 2) / pow(mstr.vec.rayDirX, 2)));
 mstr.vec.deltaDstY = sqrt(pow(30, 2) + (pow(mstr.vec.rayDirX, 2) / pow(mstr.vec.rayDirY, 2)));
 printf("deltaDstY %f\n", mstr.vec.deltaDstY);
 printf("deltaDstX %f\n", mstr.vec.deltaDstX);
 if (mstr.vec.rayDirX < 0)
 {
  printf("zzz1\n");
  mstr.vec.stepX = -1;
  mstr.vec.sideDstX = (mstr.map.tireSz / 2) * mstr.vec.deltaDstX;
  //  mstr.vec.sideDstX = (mstr.map.tireSz * mstr.vec.deltaDstX) / 2;
  //  mstr.vec.sideDstX = (mstr.vec.posX - (mstr.vec.tireX * 30)) * mstr.vec.deltaDstX;
  //   mstr.vec.sideDstX = (mstr.map.tireSz) * mstr.vec.deltaDstX;
  //    mstr.vec.sideDstX = (mstr.map.tireSz / 2) * sqrt(pow(15, 2) + pow(mstr.vec.rayDirY / mstr.vec.rayDirX, 2));
  //    mstr.vec.sideDstX = (mstr.map.tireSz / 2) * sqrt(1 + pow(mstr.vec.rayDirY / mstr.vec.rayDirX, 2));
  //   mstr.vec.sideDstX = sqrt(pow(15, 2) + pow(mstr.vec.rayDirY / mstr.vec.rayDirX, 2));
  // printf("posX %f\n", mstr.vec.posX);
  // printf("(tireX * tireSz) %i\n", (mstr.vec.tireX * mstr.map.tireSz));
  // printf("posX - (tireX * tireSz) %f\n", fabs(mstr.vec.posX - (mstr.vec.tireX * mstr.map.tireSz)));
  // mstr.vec.sideDstX = fabs((mstr.vec.posX / mstr.map.tireSz) - mstr.vec.tireX) * mstr.vec.deltaDstX;
  // mstr.vec.sideDstX = 0.5 * mstr.vec.deltaDstX;
  printf("sideDstX %f\n", mstr.vec.sideDstX);
  // hitWall = 1;
 }
 else
 {
  printf("zzz2\n");
  mstr.vec.stepX = 1;
  mstr.vec.sideDstX = (mstr.map.tireSz / 2) * mstr.vec.deltaDstX;
  // mstr.vec.sideDstX = (mstr.map.tireSz * mstr.vec.deltaDstX) / 2;
  // mstr.vec.sideDstX = (((mstr.vec.tireX + 1) * 30) - mstr.vec.posX) * mstr.vec.deltaDstX;
  // mstr.vec.sideDstX = (mstr.map.tireSz) * mstr.vec.deltaDstX;
  // mstr.vec.sideDstX = (mstr.map.tireSz / 2) * sqrt(pow(15, 2) + pow(mstr.vec.rayDirY / mstr.vec.rayDirX, 2));
  // mstr.vec.sideDstX = (mstr.map.tireSz / 2) * sqrt(1 + pow(mstr.vec.rayDirY / mstr.vec.rayDirX, 2));
  // mstr.vec.sideDstX = sqrt(pow(15, 2) + pow(mstr.vec.rayDirY / mstr.vec.rayDirX, 2));
  // printf("posX %f\n", mstr.vec.posX);
  // printf("(tireX * tireSz) %i\n", (mstr.vec.tireX * mstr.map.tireSz));
  // printf("((tireX + 1) * tireSz) - posX %f\n", (((mstr.vec.tireX + 1) * mstr.map.tireSz) - mstr.vec.posX));
  // mstr.vec.sideDstX = fabs((mstr.vec.tireX + 1) - (mstr.vec.posX / mstr.map.tireSz)) * mstr.vec.deltaDstX;
  // mstr.vec.sideDstX = 0.5 * mstr.vec.deltaDstX;
  printf("sideDstX %f\n", mstr.vec.sideDstX);
  // hitWall = 1;
 }
 if (mstr.vec.rayDirY < 0)
 {
  printf("zzz3\n");
  mstr.vec.stepY = -1;
  mstr.vec.sideDstY = (mstr.map.tireSz / 2) * mstr.vec.deltaDstY;
  // mstr.vec.sideDstY = (mstr.map.tireSz * mstr.vec.deltaDstY) / 2;
  // mstr.vec.sideDstY = (mstr.vec.posY - (mstr.vec.tireY * 30)) * mstr.vec.deltaDstY;
  // mstr.vec.sideDstY = (mstr.map.tireSz) * mstr.vec.deltaDstY;
  // mstr.vec.sideDstY = (mstr.map.tireSz / 2) * sqrt(pow(15, 2) + pow(mstr.vec.rayDirX / mstr.vec.rayDirY, 2));
  // mstr.vec.sideDstY = (mstr.map.tireSz / 2) * sqrt(1 + pow(mstr.vec.rayDirX / mstr.vec.rayDirY, 2));
  // mstr.vec.sideDstY = sqrt(pow(15, 2) + pow(mstr.vec.rayDirX / mstr.vec.rayDirY, 2));
  // printf("posY %f\n", mstr.vec.posY);
  // printf("(tireY * tireSz) %i\n", (mstr.vec.tireY * mstr.map.tireSz));
  // printf("posY - (tireY * tireSz) %f\n", fabs(mstr.vec.posY - (mstr.vec.tireY * mstr.map.tireSz)));
  // mstr.vec.sideDstY = fabs((mstr.vec.posY / mstr.map.tireSz) - mstr.vec.tireY) * mstr.vec.deltaDstY;
  // mstr.vec.sideDstY = 0.5 * mstr.vec.deltaDstY;
  printf("sideDstY %f\n", mstr.vec.sideDstY);
  // hitWall = 1;
 }
 else
 {
  printf("zzz4\n");
  mstr.vec.stepY = 1;
  mstr.vec.sideDstY = (mstr.map.tireSz / 2) * mstr.vec.deltaDstY;
  // mstr.vec.sideDstY = (mstr.map.tireSz * mstr.vec.deltaDstY) / 2;
  // mstr.vec.sideDstY = (((mstr.vec.tireY + 1) * 30) - mstr.vec.posY) * mstr.vec.deltaDstY;
  // mstr.vec.sideDstY = (mstr.map.tireSz) * mstr.vec.deltaDstY;
  //  mstr.vec.sideDstY = (mstr.map.tireSz / 2) * sqrt(pow(15, 2) + pow(mstr.vec.rayDirX / mstr.vec.rayDirY, 2));
  //  mstr.vec.sideDstY = (mstr.map.tireSz / 2) * sqrt(1 + pow(mstr.vec.rayDirX / mstr.vec.rayDirY, 2));
  //  mstr.vec.sideDstY = sqrt(pow(15, 2) + pow(mstr.vec.rayDirX / mstr.vec.rayDirY, 2));
  // printf("posY %f\n", mstr.vec.posY);
  // printf("(tireY * tireSz) %i\n", (mstr.vec.tireY * mstr.map.tireSz));
  // printf("((tireY + 1) * tireSz) - posY %f\n", (((mstr.vec.tireY + 1) * mstr.map.tireSz) - mstr.vec.posY));
  // mstr.vec.sideDstY = fabs((mstr.vec.tireY + 1) - (mstr.vec.posY / mstr.map.tireSz)) * mstr.vec.deltaDstY;
  // mstr.vec.sideDstY = 0.5 * mstr.vec.deltaDstY;
  printf("sideDstY %f\n", mstr.vec.sideDstY);
  // hitWall = 1;
 }
 ////////////////////////////////////////
 // hitWall = 1;
 // dstX = mstr.vec.sideDstX;
 // dstY = mstr.vec.sideDstY;
 ////////////////////////////////////////
 // int z = 0;
 while (hitWall == 0)
 {
  printf("xxx\n");
  if (mstr.vec.sideDstX < mstr.vec.sideDstY)
  {
   mstr.vec.isX = 1;
   printf("Choose sideX sideX:%f < sideY: %f\n", mstr.vec.sideDstX, mstr.vec.sideDstY);
   tireX += mstr.vec.stepX;
   dstX = mstr.vec.sideDstX;
   // mstr.vec.sideDstX += (mstr.map.tireSz * roundf(mstr.vec.deltaDstX));
   // printf("sideX += (tireSz * deltaDstX) => %f += (%i * %f)\n", mstr.vec.sideDstX, mstr.map.tireSz, mstr.vec.deltaDstX);
   // mstr.vec.sideDstX += (mstr.map.tireSz * mstr.vec.deltaDstX);
   mstr.vec.sideDstX += mstr.vec.deltaDstX;
   printf("map[%i][%i]\n", tireY, tireX);
  }
  else
  {
   mstr.vec.isX = 0;
   printf("Choose sideY sideY:%f < sideX: %f\n", mstr.vec.sideDstY, mstr.vec.sideDstX);
   tireY += mstr.vec.stepY;
   dstY = mstr.vec.sideDstY;
   // mstr.vec.sideDstY += (mstr.map.tireSz * roundf(mstr.vec.deltaDstY));
   // printf("sideY += (tireSz * deltaDstY) => %f += (%i * %f)\n", mstr.vec.sideDstY, mstr.map.tireSz, mstr.vec.deltaDstY);
   // mstr.vec.sideDstY += (mstr.map.tireSz * mstr.vec.deltaDstY);
   mstr.vec.sideDstY += mstr.vec.deltaDstY;
   printf("map[%i][%i]\n", tireY, tireX);
  }
  /////////////////////
  // hitWall = 1;
  // dstX = mstr.vec.sideDstX;
  // if (z++ == 1)
  //  hitWall = 1;
  /////////////////////
  if (input_ok(tireX, tireY))
   if (mstr.map.map[tireY][tireX] == '1')
   {
    printf("hit wall map[%i][%i]\n", tireY, tireX);
    // find_limit_pos(tireX, tireY);
    hitWall = 1;
   }
 }
 printf("end sideDstY %f\n", mstr.vec.sideDstY);
 printf("end sideDstX %f\n", mstr.vec.sideDstX);
 printf("end dstY %f\n", dstY);
 printf("end dstX %f\n", dstX);
 ///////////////////////////////////////////////
 // if (mstr.vec.isX)
 //  mstr.vec.sideDstX -= ((mstr.map.tireSz / 2) * mstr.vec.deltaDstX);
 // else
 //  mstr.vec.sideDstY -= ((mstr.map.tireSz / 2) * mstr.vec.deltaDstY);
 // printf("tireSz: %i deltaDstY: %f deltaDstX: %f\n", mstr.map.tireSz, mstr.vec.deltaDstY, mstr.vec.deltaDstX);
 printf("XXXend sideDstY %f\n", mstr.vec.sideDstY);
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
  // if (x == 0 || x == 1 || x == 2)
  raycast(mstr.vec.tireX, mstr.vec.tireY);
  ++x;
  // break;
 }
 // printf("\nray %i\n\n", x + 1);
 // mstr.vec.camX = 1;
 // mstr.vec.rayDirX = mstr.vec.dirX + (mstr.vec.planeX * mstr.vec.camX);
 // mstr.vec.rayDirY = mstr.vec.dirY + (mstr.vec.planeY * mstr.vec.camX);
 // raycast(mstr.vec.tireX, mstr.vec.tireY);
 mstr.vec.isX = -1;
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