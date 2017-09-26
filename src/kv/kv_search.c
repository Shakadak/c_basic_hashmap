/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kv_search.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 15:30:11 by npineau           #+#    #+#             */
/*   Updated: 2017/09/26 15:45:01 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/kv.h"

int	kv_search(t_kv *map, void *kv, void *kv_out)
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
		j += 1;
		i = (i + 1) % map->capacity;
	}
	return (0);
}
