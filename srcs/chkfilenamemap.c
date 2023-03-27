/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chkfilenamemap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psrikamo <psrikamo@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 18:52:04 by psrikamo          #+#    #+#             */
/*   Updated: 2023/03/21 21:41:53 by psrikamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// file type is .cub return 0
// file type is not .cub return 1
int	chkfiletype(char *filename)
{
	int	i;

	i = 0;
	while ((filename[i] != '.') && (filename[i] != 0)) 
		i++;
	if (filename[i] != 0)
	{
		if ((filename[i + 1] == 'c') && (filename[i + 2] == 'u') \
			&& (filename[i + 3] == 'b') && (filename[i + 4] == 0))
			return (0);
	}
	return (1);
}

// map is correct return 0
// map is incorrect return 1
int	chkfilenamemap(int argc, char **argv)
{
	if (argc == 2)
	{
		if (!chkfiletype(argv[1]))
		{
			printf("file is .cub\n");
			return (0);
		}
		fileerrhand(1);
	}
	fileerrhand(0);
	return (1);
}