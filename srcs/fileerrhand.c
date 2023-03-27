/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fileerrhand.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psrikamo <psrikamo@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 20:15:38 by psrikamo          #+#    #+#             */
/*   Updated: 2023/03/21 21:01:16 by psrikamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// error handling of map's file
void	fileerrhand(int errnum)
{
	if (errnum == 0)
	{
		printf("number of arguments is not match\n");
		printf("please try cmd \"./cub3D [file.cub]\"\n");
	}
	else if (errnum == 1)
	{
		printf("file type is not .cub\n");
		printf("please select .cub file\n");
	}
}