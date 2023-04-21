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
  mstr.vec.lmtX = mstr.vec.posX - (camX * (tireSz / 2)) + dstX * tireSz + (camX * tireSz);
  mstr.vec.lmtY = mstr.vec.posY + (mstr.vec.dirY * (tireSz / 2)) - dstY * tireSz;
}

// void rayBorder(float endX, float endY)
// {
//   float len_dirVec;
//   float posY;
//   float posX;

//   posX = mstr.vec.posX;
//   posY = mstr.vec.posY;
//   len_dirVec = fabs(posY - endY);
//   mstr.color = 0xFF0000;
//   line(endX, endY, endX - len_dirVec, endY);
//   line(endX, endY, endX + len_dirVec, endY);
//   mstr.color = 0xFFFFFF;
// }

void drawRay(int dstX, int dstY, int tireX, int tireY)
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
  ///////////////////////////////
  (void)tireX;
  (void)tireY;
  // mstr.color = 0xFF0000;
  // if (mstr.vec.camX != 0 && mstr.vec.rayN != 4)
  // {
  //   printf("rayN %i\n", mstr.vec.rayN);
  //   find_limit_pos(tireX, tireY);
  //   if (mstr.vec.rayN == 4)
  //     mstr.color = 0x90EE90;
  // line(posX, posY, endX + 15, endY);
  // }
  // mstr.color = 0xFFFFFF;
  ///////////////////////////////
  ///////////////////////////////
  // mstr.color = 0xFF0000;
  // line(posX, posY, posX, endY);
  // line(posX, posY, endX, posY);
  // mstr.color = 0xFFFFFF;
  ///////////////////////////////
  // if (mstr.vec.rayDirX == 0)
  //   rayBorder(endX, endY);
  // if (mstr.vec.camX != 0 && mstr.vec.rayN != 0 && mstr.vec.rayN != 4)
  // {
  //   find_limit_pos(tireX, tireY);
  //   mstr.color = 0xFF0000;
  //   printf("lmtX %f\n", mstr.vec.lmtX);
  //   printf("oldLmtX %f\n", mstr.vec.oldLmtX);
  //   printf("diff %f\n", ((mstr.vec.lmtX - mstr.vec.oldLmtX) / 2));
  //   line(posX, posY, mstr.vec.oldLmtX + ((mstr.vec.lmtX - mstr.vec.oldLmtX) / 2), endY);
  //   mstr.color = 0xFFFFFF;
  // }
  if (mstr.vec.isX)
    mstr.vec.ppwd = fabs(mstr.vec.lmtX - mstr.vec.posX);
  else
    mstr.vec.ppwd = fabs(mstr.vec.lmtY - mstr.vec.posY);
  printf("ppwd is %f\n", mstr.vec.ppwd);
  mstr.color = 0x90EE90;
  printf("lmtX %f\n", mstr.vec.lmtX);
  line(mstr.vec.lmtX, mstr.vec.posY, mstr.vec.lmtX, mstr.vec.posY + (mstr.vec.dirY * mstr.vec.ppwd));
  line(mstr.vec.lmtX, mstr.vec.posY, mstr.vec.posX, mstr.vec.posY);
  printf("my ppwd is %f\n", fabs(mstr.vec.lmtY - mstr.vec.posY));
  mstr.color = 0xFFFFFF;
  printf("Last lmtX %f\n", mstr.vec.lmtX);
  printf("Last lmtY %f\n", mstr.vec.lmtY);
  printf("Diff lmtX and endX %f\n", fabs(mstr.vec.lmtX - endX));
  // mstr.vec.oldLmtX = mstr.vec.lmtX;
}

void raycast(int tireX, int tireY, float n)
{
  int hitWall;
  float dstX;
  float dstY;

  hitWall = 0;
  dstX = 0;
  dstY = 0;
  ////////////////////////////
  mstr.vec.sideDstX = 0;
  mstr.vec.sideDstY = 0;
  ////////////////////////////
  mstr.vec.deltaDstX = sqrt(pow(30, 2) + (pow(mstr.vec.rayDirY, 2) / pow(mstr.vec.rayDirX, 2)));
  mstr.vec.deltaDstY = sqrt(pow(30, 2) + (pow(mstr.vec.rayDirX, 2) / pow(mstr.vec.rayDirY, 2)));
  ////////////////////////////
  // float sideDstX2;
  // float sideDstY2;
  ////////////////////////////
  // float deltaDstX2 = sqrt(pow(30, 2) + (pow(mstr.vec.rayDirY, 2) / pow(mstr.vec.rayDirX, 2)));
  // float deltaDstY2 = sqrt(pow(30, 2) + (pow(mstr.vec.rayDirX, 2) / pow(mstr.vec.rayDirY, 2)));
  printf("deltaDstX %f\n", mstr.vec.deltaDstX);
  printf("deltaDstY %f\n", mstr.vec.deltaDstY);
  // printf("deltaDstX2 %f\n", deltaDstX2);
  // printf("deltaDstY2 %f\n", deltaDstY2);
  if (mstr.vec.rayDirX < 0)
  {
    printf("zzz1\n");
    mstr.vec.stepX = -1;
    mstr.vec.sideDstX = (int)((mstr.map.tireSz / 2) * mstr.vec.deltaDstX);
    // mstr.vec.sideDstX = (int)((mstr.map.tireSz) * mstr.vec.deltaDstX);
    // mstr.vec.sideDstX = (0.5 * mstr.vec.deltaDstX);
    // sideDstX2 = (int)((mstr.map.tireSz / 2) * deltaDstX2);
    printf("sideDstX %f\n", mstr.vec.sideDstX);
    // printf("sideDstX2 %f\n", sideDstX2);
  }
  else
  {
    printf("zzz2\n");
    mstr.vec.stepX = 1;
    mstr.vec.sideDstX = (int)((mstr.map.tireSz / 2) * mstr.vec.deltaDstX);
    // mstr.vec.sideDstX = (int)((mstr.map.tireSz) * mstr.vec.deltaDstX);
    // mstr.vec.sideDstX = (0.5 * mstr.vec.deltaDstX);
    // sideDstX2 = (int)((mstr.map.tireSz / 2) * deltaDstX2);
    printf("sideDstX %f\n", mstr.vec.sideDstX);
    // printf("sideDstX2 %f\n", sideDstX2);
  }
  if (mstr.vec.rayDirY < 0)
  {
    printf("zzz3\n");
    mstr.vec.stepY = -1;
    mstr.vec.sideDstY = (int)((mstr.map.tireSz / 2) * mstr.vec.deltaDstY);
    // mstr.vec.sideDstY = (int)((mstr.map.tireSz) * mstr.vec.deltaDstY);
    // mstr.vec.sideDstY = (0.5 * mstr.vec.deltaDstY);
    // sideDstY2 = (int)((mstr.map.tireSz / 2) * deltaDstY2);
    printf("sideDstY %f\n", mstr.vec.sideDstY);
    // printf("sideDstY2 %f\n", sideDstY2);
  }
  else
  {
    printf("zzz4\n");
    mstr.vec.stepY = 1;
    mstr.vec.sideDstY = (int)((mstr.map.tireSz / 2) * mstr.vec.deltaDstY);
    // mstr.vec.sideDstY = (int)((mstr.map.tireSz) * mstr.vec.deltaDstY);
    // mstr.vec.sideDstY = (0.5 * mstr.vec.deltaDstY);
    // sideDstY2 = (int)((mstr.map.tireSz / 2) * deltaDstY2);
    printf("sideDstY %f\n", mstr.vec.sideDstY);
    // printf("sideDstY2 %f\n", sideDstY2);
  }
  /////////////////////
  if (mstr.vec.sideDstX < 0)
    mstr.vec.sideDstX = MAXFLOAT;
  if (mstr.vec.sideDstY < 0)
    mstr.vec.sideDstY = MAXFLOAT;
  /////////////////////
  mstr.vec.deltaDstX = sqrt(pow(n, 2) + (pow(mstr.vec.rayDirY, 2) / pow(mstr.vec.rayDirX, 2)));
  mstr.vec.deltaDstY = sqrt(pow(n, 2) + (pow(mstr.vec.rayDirX, 2) / pow(mstr.vec.rayDirY, 2)));
  //////////////////////
  // deltaDstX2 = sqrt(pow(30, 2) + (pow(mstr.vec.rayDirY, 2) / pow(mstr.vec.rayDirX, 2)));
  // deltaDstY2 = sqrt(pow(30, 2) + (pow(mstr.vec.rayDirX, 2) / pow(mstr.vec.rayDirY, 2)));
  // printf("deltaDstX %f\n", mstr.vec.deltaDstX);
  printf("deltaDstY %f\n", mstr.vec.deltaDstY);
  // printf("deltaDstX2 %f\n", deltaDstX2);
  // printf("deltaDstY2 %f\n", deltaDstY2);
  //////////////////////
  // float dstX2;
  // float dstY2;
  while (hitWall == 0)
  {
    if (mstr.vec.sideDstX < mstr.vec.sideDstY)
    {
      mstr.vec.isX = 1;
      printf("Choose sideX sideX:%f < sideY: %f\n", mstr.vec.sideDstX, mstr.vec.sideDstY);
      tireX += mstr.vec.stepX;
      dstX = mstr.vec.sideDstX;
      // mstr.vec.sideDstX += (int)(mstr.map.tireSz * mstr.vec.deltaDstX);
      mstr.vec.sideDstX += mstr.vec.deltaDstX;
      // printf("Choose sideX2 sideX2:%f < sideY2: %f\n", sideDstX2, sideDstY2);
      // dstX2 = sideDstX2;
      // sideDstX2 += deltaDstX2;
      printf("map[%i][%i]\n", tireY, tireX);
    }
    else
    {
      mstr.vec.isX = 0;
      printf("Choose sideY sideY:%f < sideX: %f\n", mstr.vec.sideDstY, mstr.vec.sideDstX);
      tireY += mstr.vec.stepY;
      dstY = mstr.vec.sideDstY;
      // mstr.vec.sideDstY += (int)(mstr.map.tireSz * mstr.vec.deltaDstY);
      mstr.vec.sideDstY += mstr.vec.deltaDstY;
      // printf("Choose sideY2 sideY2:%f < sideX2: %f\n", sideDstY2, sideDstX2);
      // dstY2 = sideDstY2;
      // sideDstY2 += deltaDstY2;
      printf("map[%i][%i]\n", tireY, tireX);
    }
    // if (mstr.vec.isX)
    // {
    //   mstr.vec.isX = 0;
    //   printf("Choose sideX sideX:%f < sideY: %f\n", mstr.vec.sideDstX, mstr.vec.sideDstY);
    //   tireX += mstr.vec.stepX;
    //   dstX = mstr.vec.sideDstX;
    //   mstr.vec.sideDstX += (int)(mstr.map.tireSz * mstr.vec.deltaDstX);
    //   printf("map[%i][%i]\n", tireY, tireX);
    // }
    // else
    // {
    //   mstr.vec.isX = 1;
    //   printf("Choose sideY sideY:%f < sideX: %f\n", mstr.vec.sideDstY, mstr.vec.sideDstX);
    //   tireY += mstr.vec.stepY;
    //   dstY = mstr.vec.sideDstY;
    //   mstr.vec.sideDstY += (int)(mstr.map.tireSz * mstr.vec.deltaDstY);
    //   printf("map[%i][%i]\n", tireY, tireX);
    // }
    if (input_ok(tireX, tireY))
      if (mstr.map.map[tireY][tireX] == '1')
      {
        printf("hit wall map[%i][%i]\n", tireY, tireX);
        find_limit_pos(tireX, tireY);
        hitWall = 1;
      }
  }
  ///////////////////////////////////
  // mstr.vec.sideDstX -= mstr.map.tireSz;
  // mstr.vec.sideDstX -= (int)(mstr.map.tireSz * mstr.vec.deltaDstX);
  // mstr.vec.sideDstY -= (int)(mstr.map.tireSz * mstr.vec.deltaDstY);
  /////////////////////////////////////
  printf("end sideDstY %f\n", mstr.vec.sideDstY);
  printf("end sideDstX %f\n", mstr.vec.sideDstX);
  printf("end dstY %f\n", dstY);
  printf("end dstX %f\n", dstX);
  ///////////////////////////////////////////////
  if (hitWall == 1)
    drawRay(dstX, dstY, tireX, tireY);
  // if (hitWall == 1 && mstr.vec.rayN != 3 && mstr.vec.rayN != 4 && mstr.vec.rayN != 5 && mstr.vec.rayN != 6)
  // {s
  // mstr.color = 0xFF0000;
  // drawRay(sideDstX2, sideDstY2, tireX, tireY);
  // mstr.color = 0xFFFFFF;
  // }
  // drawRay(mstr.vec.sideDstX, mstr.vec.sideDstY, tireX, tireY);
  // if (n > 1 || mstr.vec.camX == 0)
  // {
  //   mstr.color = 0xFFFFFF;
  //   return;
  // }
  // printf("\n\n n is %f\n\n", n);
  // mstr.color = 0xFF0000;
  // raycast(mstr.vec.tireX, mstr.vec.tireY, n + 1);
}

void raycast2(void)
{
  int x;
  int w;

  x = 0;
  w = 9;
  // w = 19;
  // w = 11;
  mstr.vec.camX = 0;
  mstr.vec.rayDirX = mstr.vec.dirX + (mstr.vec.planeX * mstr.vec.camX);
  mstr.vec.rayDirY = mstr.vec.dirY + (mstr.vec.planeY * mstr.vec.camX);
  printf("\nray middle \n\n");
  mstr.color = 0xADD8E6;
  raycast(mstr.vec.tireX, mstr.vec.tireY, 1);
  mstr.color = 0xFFFFFF;
  while (x < w)
  {
    mstr.vec.rayN = x;
    printf("\nray %i\n\n", x + 1);
    printf("lmtX %f\n", mstr.vec.lmtX);
    printf("map[%i][%i]\n", mstr.vec.tireY, mstr.vec.tireX);
    mstr.vec.camX = ((2 * x) / (float)w) - 1;
    printf("camX %f\n", mstr.vec.camX);
    printf("dirX %f planeX %f camX %f\n", mstr.vec.dirX, mstr.vec.planeX, mstr.vec.camX);
    mstr.vec.rayDirX = mstr.vec.dirX + (mstr.vec.planeX * mstr.vec.camX);
    mstr.vec.rayDirY = mstr.vec.dirY + (mstr.vec.planeY * mstr.vec.camX);
    printf("rayDirX %f rayDirY %f\n", mstr.vec.rayDirX, mstr.vec.rayDirY);
    // if (x == 2)
    // if (x == 0 || x == 1 || x == 2)
    // if (x == 3 || x == 4 || x == 5 || x == 6)
    // if (x == 4 || x == 5)
    raycast(mstr.vec.tireX, mstr.vec.tireY, 1);
    ++x;
  }
  mstr.vec.rayN = x;
  printf("\nray %i\n\n", x + 1);
  mstr.vec.camX = 1;
  mstr.vec.rayDirX = mstr.vec.dirX + (mstr.vec.planeX * mstr.vec.camX);
  mstr.vec.rayDirY = mstr.vec.dirY + (mstr.vec.planeY * mstr.vec.camX);
  raycast(mstr.vec.tireX, mstr.vec.tireY, 1);
  mstr.vec.isX = -1;
  mstr.vec.rayN = -1;
  // printf("Floating %f\n", 0.5555);
  // printf("Test floating point %f\n", 0.5555 * 10);
}