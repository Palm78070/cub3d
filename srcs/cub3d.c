/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psrikamo <psrikamo@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 18:17:48 by psrikamo          #+#    #+#             */
/*   Updated: 2023/03/23 22:09:22 by psrikamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_cub3d mstr;

int main(int argc, char **argv)
{
 // t_cub3d mstr;

 // check map
 if (!chkfilenamemap(argc, argv))
 {
		// printf("file name map is ok\n");
		if (initmstr(&mstr) == 1)
		{
			// printf("failed to init main struct\n");
			return (1);
		}
		if (storfile2tlist(argv[1], mstr.tmpmap))
		{
			printf("map is already store\n");
			// {
			// 	t_list	*tmp;
			// 	int		i = 0;

			// 	printf("test show map\n");
			// 	tmp = *(mstr.tmpmap);
			// 	while (tmp != NULL)
			// 	{
			// 		printf("%d:%s", i, (char *)tmp->content);
			// 		tmp = tmp->next;
			// 		i++;
			// 	}
			// 	printf("end test show map\n");
			// }
			stormapinfo(*(mstr.tmpmap), &(mstr.map));
		}
		// ft_lstfree((mstr.tmpmap));
		// free(mstr.tmpmap);

		// init all about mlx
		mlx_setup();
		draw_minimap(0, 0);
		mlx_hook(mstr.mlx.win, 2, 1L << 0, &handle_key, &mstr);
		mlx_hook(mstr.mlx.win, 17, 0L, &handle_cross, &mstr);
		mlx_loop(mstr.mlx.ptr);
 }
 return (0);
}
