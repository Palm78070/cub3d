#include "cub3d.h"

void	draw_tire(int x, int y)
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

void	find_player_pos(void)
{
	int w;
	int h;

	w = -1;
	h = -1;
	while (++h < mstr.map.mapH)
	{
		w = -1;
		while (++w < mstr.map.mapW)
		{
			if (mstr.map.map[h][w] && is_keyword(mstr.map.map[h][w]))
			{
				mstr.vec.tireX = w;
				mstr.vec.tireY = h;
				printf("player current tire (x:%i, y:%i)\n", mstr.vec.tireX, mstr.vec.tireY);
				return ;
			}
		}
	}
}

void	find_first_pos(int *x, int *y)
{
	int	first_x;
	int	first_y;
	int	tire_x;
	int	tire_y;

	first_x = mstr.map.sc_w / 2;
	first_y = mstr.map.sc_h / 2;
	tire_x = mstr.vec.tireX;
	tire_y = mstr.vec.tireY;
	printf("tire_x %i\n", tire_x);
	printf("tire_y %i\n", tire_y);
	//////////////////////////////
	printf("first_x before %i\n", first_x);
	printf("first_y before %i\n", first_y);
	//////////////////////////////
	while (tire_y-- >= 0)
		first_y -= 30;
	while (tire_x-- >= 0)
		first_x -= 30;
	printf("tire_x after %i\n", tire_x);
	printf("tire_y after %i\n", tire_y);
	printf("first_x after %i\n", first_x);
	printf("first_y after %i\n", first_y);
	*x = first_x;
	*y = first_y;
}

void	draw_minimap(int x, int y)
{
	int w;
	int h;

	w = -1;
	h = -1;
	if (mstr.vec.tireX == -1 || mstr.vec.tireY == -1)
		find_player_pos();
	/////////////////////test middle//////////////////////////////
	line(mstr.vec.img_posX, mstr.vec.img_posY, mstr.vec.img_posX + 200, mstr.vec.img_posY - 200);
	mlx_put_image_to_window(&mstr, mstr.mlx.win, mstr.mlx.img_ptr, mstr.vec.img_posX, mstr.vec.img_posY);
	///////////////////////////////////////////////////
	find_first_pos(&x, &y);
	while (++h < mstr.map.mapH)
	{
		w = -1;
		x = 0;
		while (++w < mstr.map.mapW)
		{
			//////////////test wall//////////////////////
			if (mstr.map.map[h][w] && mstr.map.map[h][w] == '1')
			{
				line(x, y, x + 30, y + 30);
				line(x + 30, y, x, y + 30);
				mlx_put_image_to_window(&mstr, mstr.mlx.win, mstr.mlx.img_ptr, x, y);
			}
			////////////////////////////////////////////
			if (mstr.map.map[h][w] && is_keyword(mstr.map.map[h][w]))
			{
				mstr.mnMp.img = mlx_xpm_file_to_image(mstr.mlx.ptr, \
					mstr.mnMp.rl_path, &mstr.mnMp.imgW, &mstr.mnMp.imgH);
				if (!mstr.mnMp.img)
					ft_error("Failed to create player icon in minimap\n");
			}
			draw_tire(x, y);
			x += mstr.map.tire_w;
		}
		y += mstr.map.tire_h;
	}
	line(0, 0, 400, 400);
	line(400, 0, 0, 400);
	mlx_put_image_to_window(&mstr, mstr.mlx.win, mstr.mlx.img_ptr, 0, 0);
	mlx_put_image_to_window(&mstr, mstr.mlx.win, mstr.mnMp.img, \
			mstr.vec.img_posX, mstr.vec.img_posY);
}
// printf("found keyword %c\n", mstr.map.map[h][w]);
// printf("player current tire (%i, %i)\n", mstr.vector.tireY, mstr.vector.tireX);
// printf("player position x:%f y:%f\n", mstr.vector.posX, mstr.vector.posY);
