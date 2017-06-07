/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashmap_search.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 15:30:11 by npineau           #+#    #+#             */
/*   Updated: 2017/06/07 12:51:26 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/hashmap.h"

int	hashmap_search(t_hashmap *map, void *kv, void *kv_out)
{
	size_t	i;
	size_t	j;

	j = 0;
	i = map->kv_hash(kv, map->capacity) * map->size;
	while (j < map->capacity)
	{
		if (map->kv_empty(map->kvs + i))
		{
			return (0);
		}
		else if (map->kv_equ(map->kvs + i, kv))
		{
			map->kv_copy(map->kvs + i, kv_out);
			return (1);
		}
		j++;
		i = (i + map->size) % (map->capacity * map->size);
	}
	return (0);
}
