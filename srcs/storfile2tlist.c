/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   storfile2tlist.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psrikamo <psrikamo@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 21:04:26 by psrikamo          #+#    #+#             */
/*   Updated: 2023/03/23 20:35:40 by psrikamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// success store line. return 0
// fail store line. return 1
int storline2list(char *line, t_list **tmpmap)
{
 t_list *tlst;

 tlst = ft_lstnew((void *)line);
 if (tlst != NULL)
 {
		// mstr.map.mapH += 1;
		ft_lstadd_back(tmpmap, tlst);
		// printf("try to add link list\n");
		return (0);
 }
 else
 {
		// clr t_list and
		// end program here
		printf("cannot create new t_list\n");
		ft_lstfree(tmpmap);
		free(tmpmap);
		return (1);
 }
}

// success save map. return 0
// fail to save map. return 1
int storfile2tlist(char *mapfile, t_list **tmpmap)
{
 int fd;
 char *line;

 fd = open(mapfile, O_RDONLY);
 if (fd > -1)
 {
		while (1)
		{
			line = get_next_line(fd);
			if (line != NULL)
			{
				if (storline2list(line, tmpmap) == 1)
					break;
			}
			// means end of file
			else
				break;
		}
		close(fd);
 }
 // printf("map height %i\n", mstr.map.mapH);
 return (1);
}

// // success save map. return 0
// // fail to save map. return 1
// int	storfile2tlist(char *mapfile, t_list **tmpmap)
// {
// 	int		fd;
// 	char	*line;
// 	t_list	*tlst;

// 	fd = open(mapfile, O_RDONLY);
// 	if (fd > -1)
// 	{
// 		while (1)
// 		{
// 			line = get_next_line(fd);
// 			if (line != NULL)
// 			{
// 				tlst = ft_lstnew(line);
// 				if (tlst)
// 					ft_lstadd_back(tmpmap, tlst);
// 				else
// 				{
// 					// clr t_list and
// 					// end program here
// 					printf("cannot create new t_list\n");

// 					break ;
// 				}
// 			}
// 			else
// 			{
// 				// means end of file
// 				break ;
// 			}
// 		}
// 		close(fd);
// 	}
// 	return (1);
// }

// // success save map. return 0
// // fail to save map. return 1
// int	savemap(char **argv, t_cub3d *mstr)
// {
// 	int		fd;
// 	char	*line;

// 	(void)mstr;
// 	fd = open(argv[1], O_RDONLY);
// 	if (fd > -1)
// 	{
// 		line = get_next_line(fd);
// 		while (line != NULL)
// 		{
// 			printf("%s", line);
// 			free(line);
// 			line = get_next_line(fd);
// 		}
// 		printf("aft last line\n");
// 		close(fd);
// 		return (0);
// 	}
// 	return (1);
// }