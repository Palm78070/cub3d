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
 mstr->map.sc_w = 400;
 mstr->map.sc_h = 400;
 mstr->map.mapW = 0;
 mstr->map.mapH = 0;
 mstr->map.tire_w = 30;
 mstr->map.tire_h = 30;
 mstr->miniMp.rl_path = "./img/Basic_red_dot.xpm";
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
 mstr.miniMp.img = mlx_xpm_file_to_image(mstr.mlx.ptr, mstr.miniMp.rl_path, &mstr.miniMp.img_w, &mstr.miniMp.img_h);
 if (!mstr.miniMp.img)
		ft_error("Failed to create player icon in minimap\n");
}