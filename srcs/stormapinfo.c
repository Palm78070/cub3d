/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stormapinfo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psrikamo <psrikamo@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 21:42:34 by psrikamo          #+#    #+#             */
/*   Updated: 2023/03/23 22:48:08 by psrikamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int is_keyword(char c)
{
 if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
		return (1);
 return (0);
}

int is_mapHeight(char *s)
{
 int i;
 int all_space;

 i = -1;
 all_space = 1;
 while (s[++i])
 {
		if (is_keyword(s[i]) || s[i] == '0' || s[i] == '1')
		{
			all_space = 0;
			break;
		}
		else if (!ft_isspace(s[i]))
			return (0);
 }
 if (all_space)
		return (0);
 return (1);
}

void stormapinfo(t_list *tmpmap, t_mapinfo *map)
{
 unsigned int i;
 int map_w;

 map_w = 0;
 map->no = (char *)tmpmap->content;
 tmpmap = tmpmap->next;
 printf("%s", map->no);
 map->so = (char *)tmpmap->content;
 tmpmap = tmpmap->next;
 printf("%s", map->so);
 map->we = (char *)tmpmap->content;
 tmpmap = tmpmap->next;
 printf("%s", map->we);
 map->ea = (char *)tmpmap->content;
 tmpmap = tmpmap->next;
 printf("%s", map->ea);
 map->ceil = (char *)tmpmap->content;
 tmpmap = tmpmap->next;
 printf("%s", map->ceil);
 map->flor = (char *)tmpmap->content;
 tmpmap = tmpmap->next;
 printf("%s", map->flor);
 i = ft_lstsize(tmpmap);
 map->map = malloc(sizeof(char *) * i);
 i = 0;
 while (tmpmap != NULL)
 {
		map->map[i] = (char *)tmpmap->content;
		if (is_mapHeight(map->map[i]))
		{
			mstr.map.mapH += 1;
			map_w = ft_strlen(map->map[i]);
			if (mstr.map.mapW - 1 < map_w - 1)
				mstr.map.mapW = map_w - 1;
		}
		// printf("length %zu\n", ft_strlen(map->map[i]));
		printf("%s", map->map[i]);
		tmpmap = tmpmap->next;
		i++;
 }
 printf("map height %i\n", mstr.map.mapH);
 printf("map width %i\n", mstr.map.mapW);
}