#include "cub3d.h"

static void free_double_pointer(char **s)
{
 int i;

 i = -1;
 while (++i < mstr.map.mapH)
 {
  free(s[i]);
  s[i] = NULL;
 }
 s[--i] = NULL;
 free(s);
 s = NULL;
}

void ft_clear(void)
{
 if (mstr.tmpmap)
 {
  ft_lstfree((mstr.tmpmap));
  free(mstr.tmpmap);
 }
 if (mstr.map.tmp)
  free_double_pointer(mstr.map.tmp);
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