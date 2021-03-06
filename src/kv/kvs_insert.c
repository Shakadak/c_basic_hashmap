/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kvs_insert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 15:04:04 by npineau           #+#    #+#             */
/*   Updated: 2017/10/03 13:49:07 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/kv.h"

static int	kvs_insert_go(void *kv, t_kv *map)
{
	size_t	i;
	size_t	j;

	j = 0;
	i = map->kv_hash(kv, map->capacity);
	while (j < map->capacity)
	{
		if (map->flags[i] != KV_OCCUPIED)
		{
			map->kv_copy(kv, (char *)map->kvs + i * map->size);
			map->used += 1;
			map->flags[i] = KV_OCCUPIED;
			return (1);
		}
		else if (map->kv_equ((char *)map->kvs + i * map->size, kv))
		{
			map->kv_delete((char *)map->kvs + i * map->size);
			map->kv_copy(kv, (char *)map->kvs + i * map->size);
			return (1);
		}
		j++;
		i = (i + 1) % map->capacity;
	}
	return (0);
}

int			kvs_insert(void *kv, t_kv *map)
{
	if (map->used + 1 > (unsigned int)(map->capacity * map->threshold))
	{
		map = kvs_resize(map->capacity * 2, map);
	}
	return (kvs_insert_go(kv, map));
}
