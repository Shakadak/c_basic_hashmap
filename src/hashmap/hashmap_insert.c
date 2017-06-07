/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashmap_insert.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 15:04:04 by npineau           #+#    #+#             */
/*   Updated: 2017/06/07 14:48:47 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/hashmap.h"

int	hashmap_insert(t_hashmap *map, void *kv)
{
	size_t	i;
	size_t	j;

	j = 0;
	i = map->kv_hash(kv, map->capacity);
	while (j < map->capacity)
	{
		if (map->flags[i] == KV_EMPTY || map->flags[i] == KV_DELETED)
		{
			map->kv_copy(kv, map->kvs + i * map->size);
			map->used += 1;
			map->flags[i] = KV_OCCUPIED;
			return (1);
		}
		else if (map->kv_equ(map->kvs + i * map->size, kv))
		{
			map->kv_delete(map->kvs + i * map->size);
			map->kv_copy(kv, map->kvs + i * map->size);
			return (1);
		}
		j++;
		i = (i + 1) % map->capacity;
	}
	return (0);
}
