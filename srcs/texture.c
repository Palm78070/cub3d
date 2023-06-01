#include "cub3d.h"

void getTextPoint(void)
{
 // printf("//////////////Component of wallHit///////////////////\n");
 // printf("posX: %f posY: %f rayDirX: %f rayDirY: %f ppwd: %f ", mstr.ray.pos.x, mstr.ray.pos.y, mstr.ray.rayDir.x, mstr.ray.rayDir.y, mstr.ray.ppwd);
 // printf("wallHit %f ", mstr.ray.wallHit);
 // printf("//////////////////////////////////////////////////////\n");
 mstr.ray.tex.ix = (int)(mstr.ray.wallHit * (float)texSz);
 if (mstr.ray.isX && mstr.ray.rayDir.x > 0)
  mstr.ray.tex.ix = texSz - mstr.ray.tex.ix - 1;
 if (!mstr.ray.isX && mstr.ray.rayDir.y < 0)
 {
  // printf("texX from Y side ");
  mstr.ray.tex.ix = texSz - mstr.ray.tex.ix - 1;
 }
 // printf("ray %i texX: %i\n", mstr.ray.rayN, mstr.ray.tex.ix);
}