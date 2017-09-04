/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashmap_insert.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 15:04:04 by npineau           #+#    #+#             */
/*   Updated: 2017/09/04 13:50:51 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/hashmap.h"

static int	hashmap_insert_go(void *kv, t_hashmap *map)
{
	size_t	i;
	size_t	j;

	j = 0;
	i = map->kv_hash(kv, map->capacity);
	while (j < map->capacity)
	{
		if (map->flags[i] != KV_OCCUPIED)
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

int			hashmap_insert(void *kv, t_hashmap *map)
{
	if (map->used + 1 > (unsigned int)(map->capacity * map->threshold))
	{
		map = hashmap_resize(map->capacity * 2, map);
	}
	return (hashmap_insert_go(kv, map));
}
