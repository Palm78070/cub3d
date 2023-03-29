#include "cub3d.h"

void draw_tire(int x, int y)
{
 int tire_w;
 int tire_h;

 tire_w = mstr.map.tire_w;
 tire_h = mstr.map.tire_h;
 line(x, y, x, y + tire_h);
 line(x, y, x + tire_w, y);
 x += tire_w;
 line(x, y, x, y + tire_h);
 y += tire_h;
 line(x, y, x - tire_w, y);
}

void draw_wall(int x, int y)
{
 line(x, y, x + 30, y + 30);
 line(x + 30, y, x, y + 30);
 mlx_put_image_to_window(&mstr, mstr.mlx.win, mstr.mlx.img_ptr, x, y);
}

void find_player_pos(void)
{
 int w;
 int h;

 w = -1;
 h = -1;
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

int input_ok(int tireX, int tireY)
{
 // int map_width;

 // map_width = ft_strlen(mstr.map.map[tireY]) - 1;
 if (mstr.map.map == NULL || mstr.map.mapW < 0 || mstr.map.mapH < 0)
		return (0);
 if (tireX < 0 || tireY < 0 || tireY > mstr.map.mapH - 1 || tireX > (int)ft_strlen(mstr.map.map[tireY]) - 2)
		return (0);
 return (1);
}

void fill_zone(int tireX, int tireY, int imgPosX, int imgPosY)
{
 int tire_w;
 int tire_h;
 char **map;

 tire_w = mstr.map.tire_w;
 tire_h = mstr.map.tire_h;
 map = mstr.map.map;
 if (!input_ok(tireX, tireY))
		return;
 // printf("tire x: %i y: %i mapW %i\n", tireX, tireY, mstr.map.mapW);
 // printf("map[%i][%i] is %c\n", tireY, tireX, map[tireY][tireX]);
 if (map[tireY][tireX] == '2')
 {
		printf("\\\\\\\\out of recusion\\\\\\\\\n");
		return;
 }
 if (map[tireY][tireX] == '1')
		draw_wall(imgPosX, imgPosY);
 map[tireY][tireX] = '2';
 draw_tire(imgPosX, imgPosY);
 // left
 if (input_ok(tireX - 1, tireY) && map[tireY][tireX - 1] != '2')
		fill_zone(tireX - 1, tireY, imgPosX - tire_w, imgPosY);
 // right
 if (input_ok(tireX + 1, tireY) && map[tireY][tireX + 1] != '2')
		fill_zone(tireX + 1, tireY, imgPosX + tire_w, imgPosY);
 // top
 if (input_ok(tireX, tireY - 1) && map[tireY - 1][tireX] != '2')
		fill_zone(tireX, tireY - 1, imgPosX, imgPosY - tire_h);
 // down
 if (input_ok(tireX, tireY + 1) && map[tireY + 1][tireX] != '2')
		fill_zone(tireX, tireY + 1, imgPosX, imgPosY + tire_h);
}

void flood_tire(void)
{
 int tireX;
 int tireY;

 tireX = mstr.vec.tireX;
 tireY = mstr.vec.tireY;
 if (!input_ok(tireX, tireY))
		return;
 fill_zone(tireX, tireY, mstr.vec.img_posX, mstr.vec.img_posY);
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
			// draw_tire(x, y);
			x += mstr.map.tire_w;
		}
		y += mstr.map.tire_h;
 }
 flood_tire();
 line(0, 0, 400, 400);
 line(400, 0, 0, 400);
 mlx_put_image_to_window(&mstr, mstr.mlx.win, mstr.mlx.img_ptr, 0, 0);
 mlx_put_image_to_window(&mstr, mstr.mlx.win, mstr.mnMp.img,
																									mstr.vec.img_posX, mstr.vec.img_posY);
}
// printf("found keyword %c\n", mstr.map.map[h][w]);
// printf("player current tire (%i, %i)\n", mstr.vector.tireY, mstr.vector.tireX);
// printf("player position x:%f y:%f\n", mstr.vector.posX, mstr.vector.posY);
