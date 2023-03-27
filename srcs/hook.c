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
