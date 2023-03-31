#include "cub3d.h"

void ft_walk(int tireX, int tireY)
{
    if (input_ok(tireX, tireY) && mstr.map.map[tireY][tireX] == '1')
        return;
    mstr.vec.tireX = tireX;
    mstr.vec.tireY = tireY;
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
        ft_walk(mstr.vec.tireX, mstr.vec.tireY - 1); // up
    else if (key_code == 0)
        ft_walk(mstr.vec.tireX - 1, mstr.vec.tireY); // left
    else if (key_code == 2)
        ft_walk(mstr.vec.tireX + 1, mstr.vec.tireY); // right
    else if (key_code == 1)
        ft_walk(mstr.vec.tireX, mstr.vec.tireY + 1); // down
    printf("player current tire (x:%i, y:%i)\n", mstr.vec.tireX, mstr.vec.tireY);
    return (0);
}

int handle_cross(void)
{
    ft_close("Cross is pressed, window is closed\n");
    return (0);
}