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

void find_player_pos(void)
{
 int w;
 int h;

 w = -1;
 h = -1;
 if (mstr.ray.tire.ix != -1 || mstr.ray.tire.iy != -1)
		return;
 while (++h < mstr.map.mapH)
 {
		w = -1;
		while (++w < (int)ft_strlen(mstr.map.map[h]) - 1)
		{
			if (mstr.map.map[h][w] && is_keyword(mstr.map.map[h][w]))
			{
				mstr.ray.tire.ix = w;
				mstr.ray.tire.iy = h;
				find_player_dir(mstr.map.map[h][w]);
				printf("player current tire (x:%i, y:%i)\n", mstr.ray.tire.ix, mstr.ray.tire.iy);
				printf("keyword is %c\n", mstr.map.map[h][w]);
				return;
			}
		}
 }
}

void create_boarder(void)
{
 // int startX;
 // int startY;
 // int endX;
 // int endY;
 t_point start;
 t_point end;

 start.ix = mstr.mnMp.floorX;
 start.iy = mstr.mnMp.floorY;
 end.ix = mstr.mnMp.ceilX;
 end.iy = mstr.mnMp.ceilY;
 lineT(start, (t_point){.ix = end.ix, .iy = start.iy});
 lineT(start, (t_point){.ix = start.ix, .iy = end.iy});
 mstr.ray.img_pos.ix = start.ix + (MnMp_W / 2) - (mstr.mnMp.imgW / 2);
 mstr.ray.img_pos.iy = start.iy + (MnMp_H / 2) - (mstr.mnMp.imgH / 2);
 mstr.ray.pos.x = start.ix + (MnMp_W / 2);
 mstr.ray.pos.y = start.iy + (MnMp_H / 2);
}

void draw_minimap(int x, int y)
{
 int w;
 int h;

 w = -1;
 h = -1;
 if (mstr.ray.tire.ix == -1 || mstr.ray.tire.iy == -1)
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
			x += tireSz;
		}
		y += tireSz;
 }
 create_boarder();
 flood_tire();
 raycast2();
 printf("imgW: %i imgH: %i\n", mstr.mnMp.imgW, mstr.mnMp.imgH);
 mlx_put_image_to_window(&mstr, mstr.mlx.win, mstr.mlx.img_ptr, 0, 0);
 mlx_put_image_to_window(&mstr, mstr.mlx.win, mstr.mnMp.img,
																									mstr.ray.img_pos.ix, mstr.ray.img_pos.iy);
}

void re_draw(void)
{
 mlx_destroy_image(mstr.mlx.ptr, mstr.mlx.img_ptr);
 mstr.mlx.img_ptr = mlx_new_image(mstr.mlx.ptr, SC_W, SC_H);
 mstr.mlx.img_addr = mlx_get_data_addr(mstr.mlx.img_ptr, &mstr.mlx.bpp, &mstr.mlx.size_line, &mstr.mlx.endian);
 draw_minimap(0, 0);
}