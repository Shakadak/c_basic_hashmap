/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashmap_delete.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 14:56:19 by npineau           #+#    #+#             */
/*   Updated: 2017/06/07 15:01:35 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/hashmap.h"

int	hashmap_delete(void *kv, t_hashmap *map)
{
	size_t	i;
	size_t	j;

	j = 0;
	i = map->kv_hash(kv, map->capacity);
	while (j < map->capacity)
	{
		if (map->flags[i] == KV_EMPTY)
		{
			return (0);
		}
		else if (map->flags[i] == KV_OCCUPIED
				&& map->kv_equ(map->kvs + i * map->size, kv))
		{
			map->kv_delete(map->kvs + i * map->size);
			map->flags[i] = KV_DELETED;
			return (1);
		}
		j++;
		i = (i + 1) % map->capacity;
	}
	return (0);
}
