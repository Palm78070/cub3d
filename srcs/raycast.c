#include "cub3d.h"

// void find_limit_pos(int tireX, int tireY)
// {
//   int camX;
//   int dstX;
//   int dstY;

//   if (mstr.ray.camX < 0)
//     camX = ceil(mstr.ray.camX * -1) * -1;
//   else
//     camX = ceil(mstr.ray.camX);
//   // printf("ceil(camX) %i\n", camX);
//   dstX = (camX * (abs(tireX - mstr.ray.tire.ix) - 1));
//   dstY = (abs(tireY - mstr.ray.tire.iy) - 1);
//   mstr.ray.lmt.x = mstr.ray.pos.x - (int)(camX * (tireSz / 2)) + dstX * tireSz + (camX * tireSz);
//   mstr.ray.lmt.y = mstr.ray.pos.y + (mstr.ray.dir.y * (tireSz / 2)) - dstY * tireSz;
// }

// void find_hitW(int endX, int endY)
// {
//   (void)endY;
//   int camX;
//   int mv;

//   if (mstr.ray.camX < 0)
//     camX = ceil(mstr.ray.camX * -1) * -1;
//   else
//     camX = ceil(mstr.ray.camX);
//   printf("(posX - endX) / tireSz => (%f - %i)/30\n", mstr.ray.pos.x, endX);
//   mv = round(fabsf(mstr.ray.pos.x - mstr.ray.lmt.x) / tireSz);
//   printf("tireX: %i + mv: %i\n", mstr.ray.tire.ix, mv);
//   mstr.ray.hit.ix = mstr.ray.tire.ix + (int)(camX * mv);
//   printf("\n\nnew hitX %i\n\n", mstr.ray.hit.ix);
// }

t_vec rotate(t_vec v)
{
  // printf("Before Rotate v.x: %f v.y: %f\n", v.x, v.y);
  float old_x;

  old_x = v.x;
  v.x = (v.x * cosf(mstr.rot.rad)) - (v.y * sinf(mstr.rot.rad));
  v.y = ((old_x * sinf(mstr.rot.rad)) + (v.y * cosf(mstr.rot.rad)));
  if (v.y > 1)
    v.y = 1;
  if (v.y < -1)
    v.y = -1;
  if (v.x > 1)
    v.x = 1;
  if (v.x < -1)
    v.x = -1;
  // printf("After Rotate v.x: %f v.y: %f\n", v.x, v.y);
  return (v);
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

  posY = mstr.ray.pos.y;
  posX = mstr.ray.pos.x;
  // printf("sideDstX %f\n", mstr.ray.sideDst.x);
  // printf("sideDstY %f\n", mstr.ray.sideDst.y);
  dstX = (posX + (mstr.ray.dir.x * tireSz));
  dstY = (posY + (mstr.ray.dir.y * tireSz));
  // printf("dirX: %f dirY: %f\n", mstr.ray.dir.x, mstr.ray.dir.y);
  // printf("posX: %f posY: %f\n", posX, posY);
  // printf("sideDstX: %f sideDstY: %f\n", mstr.ray.sideDst.x, mstr.ray.sideDst.y);
  // printf("dstX: %f dstY: %f\n", dstX, dstY);
  if (mstr.ray.camX == 0)
  {
    mstr.color = 0x90EE90;
    line(posX, posY, dstX, dstY);
    mstr.color = 0xFFFFFF;
  }
  // line(posX, posY, dstX, dstY);
}

void raycast(float tireX, float tireY)
{
  int hitWall;
  float dstX;
  float dstY;
  float posX;
  float posY;

  hitWall = 0;
  dstX = 0;
  dstY = 0;
  mstr.ray.sideDst.x = 0;
  mstr.ray.sideDst.y = 0;
  posX = (mstr.ray.tire.ix + 0.5);
  posY = (mstr.ray.tire.iy + 0.5);
  mstr.ray.deltaDst.x = fabs(1 / mstr.ray.rayDir.x);
  mstr.ray.deltaDst.y = fabs(1 / mstr.ray.rayDir.y);
  // printf("deltaDstX %f\n", mstr.ray.deltaDstX);
  // printf("deltaDstY %f\n", mstr.ray.deltaDstY);
  if (mstr.ray.rayDir.x < 0)
  {
    // printf("zzz1\n");
    mstr.ray.step.ix = -1;
    mstr.ray.sideDst.x = (posX - mstr.ray.tire.ix) * mstr.ray.deltaDst.x;
    // printf("sideDstX %f\n", mstr.ray.sideDstX);
  }
  else
  {
    // printf("zzz2\n");
    mstr.ray.step.ix = 1;
    mstr.ray.sideDst.x = ((mstr.ray.tire.ix + 1.0) - posX) * mstr.ray.deltaDst.x;
    // printf("sideDstX %f\n", mstr.ray.sideDstX);
  }
  if (mstr.ray.rayDir.y < 0)
  {
    // printf("zzz3\n");
    mstr.ray.step.iy = -1;
    mstr.ray.sideDst.y = (posY - mstr.ray.tire.iy) * mstr.ray.deltaDst.y;
    // printf("sideDstY %f\n", mstr.ray.sideDstY);
  }
  else
  {
    // printf("zzz4\n");
    mstr.ray.step.iy = 1;
    mstr.ray.sideDst.y = ((mstr.ray.tire.iy + 1.0) - posY) * mstr.ray.deltaDst.y;
    // printf("sideDstY %f\n", mstr.ray.sideDstY);
  }
  while (hitWall == 0)
  {
    if (mstr.ray.sideDst.x < mstr.ray.sideDst.y)
    {
      mstr.ray.isX = 1;
      // printf("Choose sideX sideX:%f < sideY: %f\n", mstr.ray.sideDstX, mstr.ray.sideDstY);
      //  tireX += mstr.ray.stepX * 0.5;
      tireX += mstr.ray.step.ix;
      dstX = mstr.ray.sideDst.x;
      // mstr.ray.sideDstX += (mstr.map.tireSz * mstr.ray.deltaDstX);
      // mstr.ray.sideDstX += (mstr.ray.deltaDstX * 30);
      mstr.ray.sideDst.x += (mstr.ray.deltaDst.x);
      // printf("Choose sideX2 sideX2:%f < sideY2: %f\n", sideDstX2, sideDstY2);
      // dstX2 = sideDstX2;
      // sideDstX2 += deltaDstX2;
      // printf("map[%f][%f]\n", tireY, tireX);
    }
    else
    {
      mstr.ray.isX = 0;
      // printf("Choose sideY sideY:%f < sideX: %f\n", mstr.ray.sideDstY, mstr.ray.sideDstX);
      //  tireY += mstr.ray.stepY * 0.5;
      tireY += mstr.ray.step.iy;
      dstY = mstr.ray.sideDst.y;
      // mstr.ray.sideDstY += (mstr.map.tireSz * mstr.ray.deltaDstY);
      // mstr.ray.sideDstY += (mstr.ray.deltaDstY * 30);
      mstr.ray.sideDst.y += (mstr.ray.deltaDst.y);
      // printf("Choose sideY2 sideY2:%f < sideX2: %f\n", sideDstY2, sideDstX2);
      // dstY2 = sideDstY2;
      // sideDstY2 += deltaDstY2;
      // printf("map[%f][%f]\n", tireY, tireX);
    }
    if (input_ok(tireX, tireY))
      if (mstr.map.map[(int)tireY][(int)tireX] == '1')
      {
        //   printf("hit wall map[%i][%i] ", (int)tireY, (int)tireX);
        mstr.ray.hit.ix = tireX;
        mstr.ray.hit.iy = tireY;
        // find_limit_pos(tireX, tireY);
        hitWall = 1;
      }
  }
  // printf("end sideDstY %f\n", mstr.ray.sideDstY);
  // printf("end sideDstX %f\n", mstr.ray.sideDstX);
  // printf("end dstY %f\n", dstY);
  // printf("end dstX %f\n", dstX);
  ///////////////////////////////////////////////
  if (mstr.ray.sideDst.x == INFINITY)
    mstr.ray.sideDst.x = 0;
  if (mstr.ray.sideDst.y == INFINITY)
    mstr.ray.sideDst.y = 0;
  if (hitWall == 1 && mstr.ray.camX == 0)
    drawRay(0, 0, tireX, tireY);
  if (hitWall)
  {
    drawRay(0, 0, tireX, tireY);
    // printf("hit wall map[%i][%i] ", (int)tireY, (int)tireX);
    if (mstr.ray.isX)
    {
      // printf("\nX side");
      mstr.ray.ppwd = (mstr.ray.sideDst.x - mstr.ray.deltaDst.x);
      mstr.ray.wallHit = (float)mstr.ray.pos.x + (float)mstr.ray.ppwd * (float)mstr.ray.rayDir.x;
      // mstr.ray.wallHit = (float)mstr.ray.tire.ix + (float)mstr.ray.ppwd * (float)mstr.ray.rayDir.x;
    }
    else
    {
      // printf("\nY side");
      mstr.ray.ppwd = (mstr.ray.sideDst.y - mstr.ray.deltaDst.y);
      mstr.ray.wallHit = (float)mstr.ray.pos.y + (float)mstr.ray.ppwd * (float)mstr.ray.rayDir.y;
      // mstr.ray.wallHit = (float)mstr.ray.tire.iy + (float)mstr.ray.ppwd * (float)mstr.ray.rayDir.y;
    }
    // printf(" ppwd: %f rayDirX: %f rayDirY: %f\n", mstr.ray.ppwd, mstr.ray.rayDir.x, mstr.ray.rayDir.y);
    mstr.ray.wallHit -= floor(mstr.ray.wallHit);
    getTextPoint();
    // printf("\nwallHit %f ", mstr.ray.wallHit);
    // printf("floor(hitWall) %f\n", floor(mstr.ray.wallHit));
    // printf("wallHit - floor(hitWall) %f\n", mstr.ray.wallHit - floor(mstr.ray.wallHit));
    // printf("ray%i:ppwd is %f\n", mstr.ray.rayN, mstr.ray.ppwd);
    // printf("camX: %f sideDstX: %f sideDstY: %f\n", mstr.ray.camX, mstr.ray.sideDst.x, mstr.ray.sideDst.y);
  }
}

void raycast2(void)
{
  int x;

  x = 0;
  mstr.ray.camX = 0;
  mstr.ray.plane = rotate(mstr.ray.plane);
  mstr.ray.dir = rotate(mstr.ray.dir);
  while (x < SC_W)
  {
    mstr.ray.rayN = x;
    mstr.ray.camX = ((2 * x) / (float)SC_W) - 1;
    mstr.ray.rayDir.x = mstr.ray.dir.x + (mstr.ray.plane.x * FOV * mstr.ray.camX);
    mstr.ray.rayDir.y = mstr.ray.dir.y + (mstr.ray.plane.y * FOV * mstr.ray.camX);
    // printf("rayDirX: %f rayDirY: %f\n", mstr.ray.rayDir.x, mstr.ray.rayDir.y);
    raycast(mstr.ray.tire.ix, mstr.ray.tire.iy);
    ++x;
  }
  // mstr.ray.rayN = x;
  //  printf("\nray %i\n\n", x + 1);
  // mstr.ray.camX = 1;
  //  mstr.ray.rayDirX = mstr.ray.dirX + (mstr.ray.planeX * mstr.ray.camX);
  //  mstr.ray.rayDirY = mstr.ray.dirY + (mstr.ray.planeY * mstr.ray.camX);
  //  raycast(mstr.ray.tireX, mstr.ray.tireY, 1);
  mstr.ray.isX = -1;
  mstr.ray.rayN = -1;
  mstr.rot.rad = 0;

  printf("rad %f\n", mstr.rot.rad);
  printf("player posX: %f posY: %f\n", mstr.ray.pos.x, mstr.ray.pos.y);
  // mstr.color = 0xFF0000;
  // line(mstr.ray.pos.x, mstr.ray.pos.y, mstr.ray.pos.x, mstr.ray.pos.y - tireSz);
  // mstr.color = 0xFFFFFF;
  // printf("rdx %f\n", mstr.rot.rdx);
  // printf("rdy %f\n", mstr.rot.rdy);
  printf("dirX: %f dirY: %f\n", mstr.ray.dir.x, mstr.ray.dir.y);
}