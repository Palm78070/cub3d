#include "cub3d.h"

void getTextPoint(void)
{
 mstr.ray.tex.ix = (int)(mstr.ray.wallHit * (float)texSz);
 if (mstr.ray.isX && mstr.ray.rayDir.x > 0)
  mstr.ray.tex.ix = texSz - mstr.ray.tex.ix - 1;
 else if (!mstr.ray.isX && mstr.ray.rayDir.y < 0)
  mstr.ray.tex.ix = texSz - mstr.ray.tex.iy - 1;
 // printf("texX: %i\n", mstr.ray.tex.ix);
}