#include "cub3d.h"

void ft_clear(void)
{
 if (mstr.tmpmap)
 {
  ft_lstfree((mstr.tmpmap));
  free(mstr.tmpmap);
 }
}

void ft_error(char *s)
{
 ft_putstr_fd(s, 2);
 ft_clear();
 exit(1);
}

void ft_close(char *s)
{
 ft_putstr_fd(s, 1);
 ft_clear();
 exit(0);
}