#include "cub3d.h"

int handle_key(int key_code)
{
 if (key_code == 53)
  ft_close("Escape key is pressed, window is closed\n");
 return (0);
}

int handle_cross(void)
{
 ft_close("Cross is pressed, window is closed\n");
 return (0);
}

int handle_walk(int key_code)
{
    printf("In walking\n");
    if (key_code == 13)
        mstr.vec.tireY -= 1; //up
    else if (key_code == 0)
        mstr.vec.tireX -= 1; //left
    else if (key_code == 2)
        mstr.vec.tireX += 1; //right
    else if (key_code == 1)
        mstr.vec.tireY += 1; //down
    draw_minimap(0, 0);
    return (0);
}