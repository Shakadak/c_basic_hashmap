/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashmap_search.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 15:30:11 by npineau           #+#    #+#             */
/*   Updated: 2017/06/07 14:50:37 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/hashmap.h"

int	hashmap_search(t_hashmap *map, void *kv, void *kv_out)
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
			map->kv_copy(map->kvs + i * map->size, kv_out);
			return (1);
		}
		j++;
		i = (i + 1) % map->capacity;
	}
	return (0);
}
