#include "cub3d.h"

void ft_walk(int tireX, int tireY)
{
    if (input_ok(tireX, tireY) && mstr.map.map[tireY][tireX] == '1')
        return;
    mstr.ray.tire.ix = tireX;
    mstr.ray.tire.iy = tireY;
    re_draw();
}

int handle_key(int key_code)
{
    if (key_code == 53)
    {
        ft_close("Escape key is pressed, window is closed\n");
        return (0);
    }
    else if (key_code == 13)
        ft_walk(mstr.ray.tire.ix, mstr.ray.tire.iy + mstr.ray.dir.y); // up
    else if (key_code == 0)
        ft_walk(mstr.ray.tire.ix - 1, mstr.ray.tire.iy); // left
    else if (key_code == 2)
        ft_walk(mstr.ray.tire.ix + 1, mstr.ray.tire.iy); // right
    else if (key_code == 1)
        ft_walk(mstr.ray.tire.ix, mstr.ray.tire.iy - mstr.ray.dir.y); // down
    else if (key_code == 123)
    {
        printf("rotate left\n");
        mstr.rot.rad = -0.1;
        re_draw();
    }
    else if (key_code == 124)
    {
        printf("rotate right\n");
        mstr.rot.rad = 0.1;
        re_draw();
    }
    printf("player current tire (x:%i, y:%i)\n", mstr.ray.tire.ix, mstr.ray.tire.iy);
    return (0);
}

int handle_cross(void)
{
    ft_close("Cross is pressed, window is closed\n");
    return (0);
}