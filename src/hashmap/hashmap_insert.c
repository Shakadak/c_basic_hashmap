/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashmap_insert.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 15:04:04 by npineau           #+#    #+#             */
/*   Updated: 2017/06/07 12:51:24 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/hashmap.h"

int	hashmap_insert(t_hashmap *map, void *kv)
{
	size_t	i;
	size_t	j;

	j = 0;
	i = map->kv_hash(kv, map->capacity) * map->size;
	while (j < map->capacity)
	{
		if (map->kv_empty(map->kvs + i))
		{
			map->kv_copy(kv, map->kvs + i);
			map->used += 1;
			return (1);
		}
		else if (map->kv_equ(map->kvs + i, kv))
		{
			map->kv_delete(map->kvs + i);
			map->kv_copy(kv, map->kvs + i);
			return (1);
		}
		j++;
		i = (i + map->size) % (map->capacity * map->size);
	}
	return (0);
}
