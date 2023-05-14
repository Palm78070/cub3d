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
 mstr->map.sc_w = 400;
 mstr->map.sc_h = 400;
 // mstr->map.sc_w = 640;
 // mstr->map.sc_h = 480;
 mstr->vec.isX = -1;
 mstr->map.mapW = 0;
 mstr->map.mapH = 0;
 mstr->map.tireSz = 30;
 mstr->color = 0xFFFFFF;
 mstr->mnMp.rl_path = "./img/red_dot_30.xpm";
 mstr->vec.tireX = -1;
 mstr->vec.tireY = -1;
 mstr->vec.img_posX = (mstr->map.sc_w / 2) - mstr->map.tireSz / 2;
 mstr->vec.img_posY = (mstr->map.sc_h / 2) - mstr->map.tireSz / 2;
 mstr->vec.posX = (mstr->map.sc_w / 2);
 mstr->vec.posY = (mstr->map.sc_h / 2);
 mstr->vec.dirX = 0;
 mstr->vec.dirY = -1;
 mstr->vec.planeX = 0.66;
 mstr->vec.planeY = 0; // FOV is 2*atan(0.66/1.0) = 66
 mstr->vec.lmtX = INFINITY;
 mstr->rot.rad = 0;
 mstr->rot.rdx = 1;
 mstr->rot.rdy = 1;
 mstr->vec.dummy = 1;
 return (0);
}

void mlx_setup()
{
 mstr.mlx.ptr = mlx_init();
 if (!mstr.mlx.ptr)
		ft_error("Failed to initialise mlx with mlx_init()\n");
 mstr.mlx.win = mlx_new_window(mstr.mlx.ptr, 400, 400, "cub3d");
 if (!mstr.mlx.win)
		ft_error("Failed to open mlx_new_window()\n");
 mstr.mlx.img_ptr = mlx_new_image(mstr.mlx.ptr, 400, 400);
 mstr.mlx.img_addr = mlx_get_data_addr(mstr.mlx.img_ptr, &mstr.mlx.bpp, &mstr.mlx.size_line, &mstr.mlx.endian);
}