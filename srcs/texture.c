#include "cub3d.h"

void getTextPoint(void)
{
 // printf("//////////////Component of wallHit///////////////////\n");
 // printf("posX: %f posY: %f rayDirX: %f rayDirY: %f ppwd: %f ", mstr.ray.pos.x, mstr.ray.pos.y, mstr.ray.rayDir.x, mstr.ray.rayDir.y, mstr.ray.ppwd);
 // printf("wallHit %f\n", mstr.ray.wallHit);
 // printf("//////////////////////////////////////////////////////\n");
 mstr.ray.tex.ix = (int)(mstr.ray.wallHit * (float)texSz);
 if (mstr.ray.isX && mstr.ray.rayDir.x > 0)
  mstr.ray.tex.ix = texSz - mstr.ray.tex.ix - 1;
 else if (!mstr.ray.isX && mstr.ray.rayDir.y < 0)
  mstr.ray.tex.ix = texSz - mstr.ray.tex.iy - 1;
 // printf("texX: %i\n", mstr.ray.tex.ix);
}