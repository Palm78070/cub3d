/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psrikamo <psrikamo@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 18:51:07 by psrikamo          #+#    #+#             */
/*   Updated: 2023/03/23 22:09:40 by psrikamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

#include "libft.h"
#include "get_next_line.h"
#include "mlx.h"
#include <unistd.h>
#include <fcntl.h>
#include <math.h>
#include <stdio.h>

typedef struct s_mapinfo
{
    char *no;
    char *so;
    char *we;
    char *ea;
    char *ceil;
    char *flor;
    char **map;
    int sc_w;
    int sc_h;
    int mapW;
    int mapH;
    int tire_w;
    int tire_h;
} t_mapinfo;

typedef struct s_mlx
{
    void *ptr;
    void *win;
    void *img_ptr;
    char *img_addr;
    int bpp;
    int size_line;
    int endian;
} t_mlx;

typedef struct s_minimap
{
    void *img;
    char *rl_path;
    int imgW;
    int imgH;
} t_minimap;

typedef struct s_vector
{
    int tireX;
    int tireY;
    int img_posX;
    int img_posY;
    float posX;
    float posY;
    float dirX;
    float dirY;
    float planeX;
    float planeY;
} t_vector;

// typedef struct s_tire
// {
//     int x;
//     int y;
// } t_tire;

typedef struct s_cub3d
{
    t_mlx mlx;
    char **mapfile;
    t_list **tmpmap;
    t_mapinfo map;
    t_minimap mnMp;
    t_vector vec;
} t_cub3d;

extern t_cub3d mstr;

// check map
int chkfilenamemap(int argc, char **argv);

// map error handling
void fileerrhand(int errnum);

// initial main struct
int initmstr(t_cub3d *mstr);

// save map into linklist
int storfile2tlist(char *mapfile, t_list **tmpmap);

// key word
int is_keyword(char c);
// save map from linklist to mapinfo
void stormapinfo(t_list *tmpmap, t_mapinfo *map);

// mlx
void mlx_setup();
// hook
int handle_key(int key_code);
int handle_cross(void);
// draw
void ft_pixel_put(int x, int y, int color);
void line(float x0, float y0, float x1, float y1);
// minimap
void draw_minimap(int x, int y);
// clear
void ft_clear(void);
void ft_error(char *s);
void ft_close(char *s);
#endif
