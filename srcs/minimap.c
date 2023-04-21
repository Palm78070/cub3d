/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthammat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 11:48:56 by rthammat          #+#    #+#             */
/*   Updated: 2023/03/30 11:49:08 by rthammat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void draw_tire(int x, int y)
{
 int tireSz;

 tireSz = mstr.map.tireSz;
 line(x, y, x, y + tireSz);
 line(x, y, x + tireSz, y);
 x += tireSz;
 line(x, y, x, y + tireSz);
 y += tireSz;
 line(x, y, x - tireSz, y);
}

void draw_wall(int x, int y)
{
 int tireSz;

 tireSz = mstr.map.tireSz;
 line(x, y, x + tireSz, y + tireSz);
 line(x + tireSz, y, x, y + tireSz);
 mlx_put_image_to_window(&mstr, mstr.mlx.win, mstr.mlx.img_ptr, x, y);
}

void find_player_pos(void)
{
 int w;
 int h;

 w = -1;
 h = -1;
 if (mstr.vec.tireX != -1 || mstr.vec.tireY != -1)
		return;
 while (++h < mstr.map.mapH)
 {
		w = -1;
		while (++w < (int)ft_strlen(mstr.map.map[h]) - 1)
		{
			if (mstr.map.map[h][w] && is_keyword(mstr.map.map[h][w]))
			{
				mstr.vec.tireX = w;
				mstr.vec.tireY = h;
				printf("player current tire (x:%i, y:%i)\n", mstr.vec.tireX, mstr.vec.tireY);
				return;
			}
		}
 }
}

void draw_minimap(int x, int y)
{
 int w;
 int h;

 w = -1;
 h = -1;
 if (mstr.vec.tireX == -1 || mstr.vec.tireY == -1)
		find_player_pos();
 while (++h < mstr.map.mapH)
 {
		w = -1;
		x = 0;
		while (++w < (int)ft_strlen(mstr.map.map[h]) - 1)
		{
			if (mstr.map.map[h][w] && is_keyword(mstr.map.map[h][w]))
			{
				mstr.mnMp.img = mlx_xpm_file_to_image(mstr.mlx.ptr,
																																										mstr.mnMp.rl_path, &mstr.mnMp.imgW, &mstr.mnMp.imgH);
				if (!mstr.mnMp.img)
					ft_error("Failed to create player icon in minimap\n");
			}
			x += mstr.map.tireSz;
		}
		y += mstr.map.tireSz;
 }
 flood_tire();
 // line(0, 0, 400, 400);
 // line(400, 0, 0, 400);
 // line(mstr.vec.posX, mstr.vec.posY, mstr.vec.posX, mstr.vec.posY - 100);
 // raycast(mstr.vec.tireX, mstr.vec.tireY);
 raycast2();
 mlx_put_image_to_window(&mstr, mstr.mlx.win, mstr.mlx.img_ptr, 0, 0);
 mlx_put_image_to_window(&mstr, mstr.mlx.win, mstr.mnMp.img,
																									mstr.vec.img_posX, mstr.vec.img_posY);
}

void re_draw(void)
{
 mlx_destroy_image(mstr.mlx.ptr, mstr.mlx.img_ptr);
 mstr.mlx.img_ptr = mlx_new_image(mstr.mlx.ptr, 400, 400);
 mstr.mlx.img_addr = mlx_get_data_addr(mstr.mlx.img_ptr, &mstr.mlx.bpp, &mstr.mlx.size_line, &mstr.mlx.endian);
 draw_minimap(0, 0);
}