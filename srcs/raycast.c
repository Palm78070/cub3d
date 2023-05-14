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
  // printf("ceil(camX) %i\n", camX);
  dstX = (camX * (abs(tireX - mstr.vec.tireX) - 1));
  dstY = (abs(tireY - mstr.vec.tireY) - 1);
  mstr.vec.lmtX = mstr.vec.posX - (int)(camX * (tireSz / 2)) + dstX * tireSz + (camX * tireSz);
  mstr.vec.lmtY = mstr.vec.posY + (mstr.vec.dirY * (tireSz / 2)) - dstY * tireSz;
}

void find_hitW(int endX, int endY)
{
  (void)endY;
  int camX;
  int mv;

  if (mstr.vec.camX < 0)
    camX = ceil(mstr.vec.camX * -1) * -1;
  else
    camX = ceil(mstr.vec.camX);
  printf("(posX - endX) / tireSz => (%f - %i)/30\n", mstr.vec.posX, endX);
  mv = round(fabsf(mstr.vec.posX - mstr.vec.lmtX) / mstr.map.tireSz);
  printf("tireX: %i + mv: %i\n", mstr.vec.tireX, mv);
  mstr.vec.hitX = mstr.vec.tireX + (int)(camX * mv);
  printf("\n\nnew hitX %i\n\n", mstr.vec.hitX);
}

float rtx(float vx, float vy)
{
  return ((vx * cos(mstr.rot.rad)) + (vy * (-1 * sin(mstr.rot.rad))));
}

float rty(float vx, float vy)
{
  return ((vx * sin(mstr.rot.rad)) + (vy * cos(mstr.rot.rad)));
}

void drawRay(float dstX, float dstY, int tireX, int tireY)
{
  (void)tireX;
  (void)tireY;
  (void)dstX;
  (void)dstY;
  float posY;
  float posX;
  // float dstX;
  // float dstY;

  posY = mstr.vec.posY;
  posX = mstr.vec.posX;
  dstX = rtx(posX + (mstr.vec.rayDirX * 30), posY + (mstr.vec.rayDirY * 30));
  dstY = rty(posX + (mstr.vec.rayDirX * 30), posY + (mstr.vec.rayDirY * 30));
  if (mstr.vec.camX == 0)
    line(posX, posY, dstX, dstY);
}

void raycast(float tireX, float tireY, float n)
{
  (void)n;
  int hitWall;
  float dstX;
  float dstY;
  float posX;
  float posY;

  hitWall = 0;
  dstX = 0;
  dstY = 0;
  ////////////////////////////
  mstr.vec.sideDstX = 0;
  mstr.vec.sideDstY = 0;
  posX = (mstr.vec.tireX - 0.5);
  posY = (mstr.vec.tireY - 0.5);
  // printf("posX:%f posY:%f\n", posX, posY);
  // printf("posX:%i posY:%i\n", (int)posX, (int)posY);
  ////////////////////////////
  // mstr.vec.deltaDstX = sqrt(1 + (pow(mstr.vec.rayDirY, 2) / pow(mstr.vec.rayDirX, 2)));
  // mstr.vec.deltaDstY = sqrt(1 + (pow(mstr.vec.rayDirX, 2) / pow(mstr.vec.rayDirY, 2)));
  mstr.vec.deltaDstX = fabs(1 / mstr.vec.rayDirX);
  mstr.vec.deltaDstY = fabs(1 / mstr.vec.rayDirY);
  // printf("deltaDstX %f\n", mstr.vec.deltaDstX);
  // printf("deltaDstY %f\n", mstr.vec.deltaDstY);
  if (mstr.vec.rayDirX < 0)
  {
    // printf("zzz1\n");
    mstr.vec.stepX = -1;
    // mstr.vec.sideDstX = (int)((mstr.map.tireSz / 2) * mstr.vec.deltaDstX);
    // mstr.vec.sideDstX = (int)((mstr.map.tireSz) * mstr.vec.deltaDstX);
    // mstr.vec.sideDstX = (0.5 * mstr.vec.deltaDstX);
    // sideDstX2 = (int)((mstr.map.tireSz / 2) * deltaDstX2);
    // mstr.vec.sideDstX = (mstr.vec.posX - mstr.vec.tireX) * mstr.vec.deltaDstX;
    mstr.vec.sideDstX = (posX - mstr.vec.tireX) * mstr.vec.deltaDstX;
    // printf("sideDstX %f\n", mstr.vec.sideDstX);
  }
  else
  {
    // printf("zzz2\n");
    mstr.vec.stepX = 1;
    // mstr.vec.sideDstX = (int)((mstr.map.tireSz / 2) * mstr.vec.deltaDstX);
    // mstr.vec.sideDstX = (int)((mstr.map.tireSz) * mstr.vec.deltaDstX);
    // mstr.vec.sideDstX = (0.5 * mstr.vec.deltaDstX);
    // sideDstX2 = (int)((mstr.map.tireSz / 2) * deltaDstX2);
    // mstr.vec.sideDstX = (mstr.vec.tireX + 1.0 - mstr.vec.posX) * mstr.vec.deltaDstX;
    mstr.vec.sideDstX = (mstr.vec.tireX + 1.0 - posX) * mstr.vec.deltaDstX;
    // printf("sideDstX %f\n", mstr.vec.sideDstX);
    //  printf("sideDstX2 %f\n", sideDstX2);
  }
  if (mstr.vec.rayDirY < 0)
  {
    // printf("zzz3\n");
    mstr.vec.stepY = -1;
    // mstr.vec.sideDstY = (int)((mstr.map.tireSz / 2) * mstr.vec.deltaDstY);
    // mstrdstX = mstr.vec.sideDstX;.vec.sideDstY = (int)((mstr.map.tireSz) * mstr.vec.deltaDstY);
    // mstr.vec.sideDstY = (0.5 * mstr.vec.deltaDstY);
    // sideDstY2 = (int)((mstr.map.tireSz / 2) * deltaDstY2);
    // mstr.vec.sideDstY = (mstr.vec.posY - mstr.vec.tireY) * mstr.vec.deltaDstY;
    mstr.vec.sideDstY = (posY - mstr.vec.tireY) * mstr.vec.deltaDstY;
    // printf("sideDstY %f\n", mstr.vec.sideDstY);
    //  printf("sideDstY2 %f\n", sideDstY2);
  }
  else
  {
    // printf("zzz4\n");
    mstr.vec.stepY = 1;
    // mstr.vec.sideDstY = (int)((mstr.map.tireSz / 2) * mstr.vec.deltaDstY);
    // mstr.vec.sideDstY = (int)((mstr.map.tireSz) * mstr.vec.deltaDstY);
    // mstr.vec.sideDstY = (0.5 * mstr.vec.deltaDstY);
    // sideDstY2 = (int)((mstr.map.tireSz / 2) * deltaDstY2);
    mstr.vec.sideDstY = (mstr.vec.tireY + 1.0 - posY) * mstr.vec.deltaDstY;
    // printf("sideDstY %f\n", mstr.vec.sideDstY);
    //  printf("sideDstY2 %f\n", sideDstY2);
  }
  /////////////////////
  // if (mstr.vec.sideDstX < 0)
  //   mstr.vec.sideDstX = MAXFLOAT;
  // if (mstr.vec.sideDstY < 0)
  //   mstr.vec.sideDstY = MAXFLOAT;
  /////////////////////
  // (void)n;
  // mstr.vec.deltaDstX = sqrt(1 + (pow(mstr.vec.rayDirY, 2) / pow(mstr.vec.rayDirX, 2)));
  // mstr.vec.deltaDstY = sqrt(1 + (pow(mstr.vec.rayDirX, 2) / pow(mstr.vec.rayDirY, 2)));
  //////////////////////
  // deltaDstX2 = sqrt(pow(30, 2) + (pow(mstr.vec.rayDirY, 2) / pow(mstr.vec.rayDirX, 2)));
  // deltaDstY2 = sqrt(pow(30, 2) + (pow(mstr.vec.rayDirX, 2) / pow(mstr.vec.rayDirY, 2)));
  // printf("deltaDstX %f\n", mstr.vec.deltaDstX);
  // printf("deltaDstY %f\n", mstr.vec.deltaDstY);
  // printf("deltaDstX2 %f\n", deltaDstX2);
  // printf("deltaDstY2 %f\n", deltaDstY2);
  //////////////////////
  // float dstX2;
  // float dstY2;
  /////////////////////
  // hitWall = 1;
  // dstX = mstr.vec.sideDstX;
  // dstY = mstr.vec.sideDstY;
  /////////////////////
  while (hitWall == 0)
  {
    if (mstr.vec.sideDstX < mstr.vec.sideDstY)
    {
      mstr.vec.isX = 1;
      // printf("Choose sideX sideX:%f < sideY: %f\n", mstr.vec.sideDstX, mstr.vec.sideDstY);
      tireX += mstr.vec.stepX * 0.5;
      dstX = mstr.vec.sideDstX;
      // mstr.vec.sideDstX += (mstr.map.tireSz * mstr.vec.deltaDstX);
      // mstr.vec.sideDstX += (mstr.vec.deltaDstX * 30);
      mstr.vec.sideDstX += (mstr.vec.deltaDstX);
      // printf("Choose sideX2 sideX2:%f < sideY2: %f\n", sideDstX2, sideDstY2);
      // dstX2 = sideDstX2;
      // sideDstX2 += deltaDstX2;
      // printf("map[%f][%f]\n", tireY, tireX);
    }
    else
    {
      mstr.vec.isX = 0;
      // printf("Choose sideY sideY:%f < sideX: %f\n", mstr.vec.sideDstY, mstr.vec.sideDstX);
      tireY += mstr.vec.stepY * 0.5;
      dstY = mstr.vec.sideDstY;
      // mstr.vec.sideDstY += (mstr.map.tireSz * mstr.vec.deltaDstY);
      // mstr.vec.sideDstY += (mstr.vec.deltaDstY * 30);
      mstr.vec.sideDstY += (mstr.vec.deltaDstY);
      // printf("Choose sideY2 sideY2:%f < sideX2: %f\n", sideDstY2, sideDstX2);
      // dstY2 = sideDstY2;
      // sideDstY2 += deltaDstY2;
      // printf("map[%f][%f]\n", tireY, tireX);
    }
    if (input_ok(tireX, tireY))
      if (mstr.map.map[(int)tireY][(int)tireX] == '1')
      {
        // printf("hit wall map[%i][%i]\n", (int)tireY, (int)tireX);
        mstr.vec.hitX = tireX;
        mstr.vec.hitY = tireY;
        find_limit_pos(tireX, tireY);
        hitWall = 1;
      }
  }
  // printf("end sideDstY %f\n", mstr.vec.sideDstY);
  // printf("end sideDstX %f\n", mstr.vec.sideDstX);
  // printf("end dstY %f\n", dstY);
  // printf("end dstX %f\n", dstX);
  ///////////////////////////////////////////////
  if (hitWall == 1 && mstr.vec.camX == 0)
    drawRay(0, 0, tireX, tireY);
  // drawRay(dstX * 30, 30, tireX, tireY);
  if (hitWall)
  {
    if (mstr.vec.isX)
      mstr.vec.ppwd = (mstr.vec.sideDstX - mstr.vec.deltaDstX);
    else
      mstr.vec.ppwd = (mstr.vec.sideDstY - mstr.vec.deltaDstY);
    // printf("/////////////////////////////\n");
    // printf("sideDstX %f\n", mstr.vec.sideDstX);
    // printf("sideDstY %f\n", mstr.vec.sideDstY);
    // printf("deltaDstX %f\n", mstr.vec.deltaDstX);
    // printf("deltaDstY %f\n", mstr.vec.deltaDstY);
    printf("ray%i:ppwd is %f\n", mstr.vec.rayN, mstr.vec.ppwd);
    // printf("/////////////////////////////\n");
  }
  // drawRay(dstX * 30, dstY * 30, tireX, tireY);
}

void raycast2(void)
{
  int x;
  int w;

  x = 0;
  // w = 9;
  // w = 199;
  w = 399;
  // w = 2;
  mstr.vec.camX = 0;
  mstr.vec.rayDirX = mstr.vec.dirX + (mstr.vec.planeX * mstr.vec.camX);
  mstr.vec.rayDirY = mstr.vec.dirY + (mstr.vec.planeY * mstr.vec.camX);
  // printf("\nray middle \n\n");
  mstr.color = 0xADD8E6;
  raycast(mstr.vec.tireX, mstr.vec.tireY, 1);
  mstr.color = 0xFFFFFF;
  while (x < w)
  {

    mstr.vec.rayN = x;
    // printf("\nray %i\n\n", x + 1);
    // printf("lmtX %f\n", mstr.vec.lmtX);
    // printf("map[%i][%i]\n", mstr.vec.tireY, mstr.vec.tireX);
    mstr.vec.camX = ((2 * x) / (float)w) - 1;
    // printf("camX %f\n", mstr.vec.camX);
    // printf("dirX %f planeX %f camX %f\n", mstr.vec.dirX, mstr.vec.planeX, mstr.vec.camX);
    mstr.vec.rayDirX = mstr.vec.dirX + (mstr.vec.planeX * mstr.vec.camX);
    mstr.vec.rayDirY = mstr.vec.dirY + (mstr.vec.planeY * mstr.vec.camX);
    // printf("rayDirX %f rayDirY %f\n", mstr.vec.rayDirX, mstr.vec.rayDirY);
    raycast(mstr.vec.tireX, mstr.vec.tireY, 1);
    ++x;
  }
  mstr.vec.rayN = x;
  printf("\nray %i\n\n", x + 1);
  mstr.vec.camX = 1;
  // mstr.vec.rayDirX = mstr.vec.dirX + (mstr.vec.planeX * mstr.vec.camX);
  // mstr.vec.rayDirY = mstr.vec.dirY + (mstr.vec.planeY * mstr.vec.camX);
  // raycast(mstr.vec.tireX, mstr.vec.tireY, 1);
  mstr.vec.isX = -1;
  mstr.vec.rayN = -1;
  mstr.vec.dummy = 1;
  // printf("Floating %f\n", 0.5555);
  // printf("Test floating point %f\n", 0.5555 * 10);
  printf("rdx %f\n", mstr.rot.rdx);
  printf("rdy %f\n", mstr.rot.rdy);
}