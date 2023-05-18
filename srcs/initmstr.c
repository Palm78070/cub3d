/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initmstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psrikamo <psrikamo@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 09:20:22 by psrikamo          #+#    #+#             */
/*   Updated: 2023/03/23 20:35:12 by psrikamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int initmstr(t_cub3d *mstr)
{
 mstr->tmpmap = malloc(sizeof(t_list *));
 if (mstr->tmpmap == NULL)
		return (1);
 *(mstr->tmpmap) = NULL;
 mstr->map.tmp = NULL;
 mstr->ray.isX = -1;
 mstr->map.mapW = 0;
 mstr->map.mapH = 0;
 mstr->color = 0xFFFFFF;
 mstr->mnMp.rl_path = "./img/red_dot_30.xpm";
 mstr->ray.tire = (t_point){.ix = -1, .iy = -1};
 mstr->ray.img_pos = (t_point){.ix = (SC_W / 2) - tireSz / 2,
																															.iy = (SC_H / 2) - tireSz / 2};
 mstr->ray.pos = (t_vec){.x = SC_W / 2, .y = SC_H / 2};
 mstr->ray.dir = (t_vec){.x = 0, .y = -1};
 mstr->ray.plane = (t_vec){.x = 0.66, .y = 0}; // FOV is 2*atan(0.66/1.0) = 66
 mstr->ray.lmt = (t_point){.x = INFINITY, .y = INFINITY};
 mstr->rot.rad = 0;
 return (0);
}

void mlx_setup()
{
 mstr.mlx.ptr = mlx_init();
 if (!mstr.mlx.ptr)
		ft_error("Failed to initialise mlx with mlx_init()\n");
 mstr.mlx.win = mlx_new_window(mstr.mlx.ptr, SC_W, SC_H, "cub3d");
 if (!mstr.mlx.win)
		ft_error("Failed to open mlx_new_window()\n");
 mstr.mlx.img_ptr = mlx_new_image(mstr.mlx.ptr, SC_W, SC_H);
 mstr.mlx.img_addr = mlx_get_data_addr(mstr.mlx.img_ptr, &mstr.mlx.bpp, &mstr.mlx.size_line, &mstr.mlx.endian);
}

void find_player_dir(char c)
{
 if (c == 'N')
 {
		mstr.ray.dir = (t_vec){.x = 0, .y = -1};
		mstr.ray.plane = (t_vec){.x = 1, .y = 0};
 }
 if (c == 'S')
 {
		mstr.ray.dir = (t_vec){.x = 0, .y = 1};
		mstr.ray.plane = (t_vec){.x = -1, .y = 0};
 }
 if (c == 'W')
 {
		mstr.ray.dir = (t_vec){.x = 1, .y = 0};
		mstr.ray.plane = (t_vec){.x = 0, .y = -1};
 }
 if (c == 'E')
 {
		mstr.ray.dir = (t_vec){.x = 1, .y = 0};
		mstr.ray.plane = (t_vec){.x = 0, .y = 1};
 }
}