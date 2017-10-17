/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kvs_delete.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 14:56:19 by npineau           #+#    #+#             */
/*   Updated: 2017/10/17 11:31:29 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/kv.h"

static int	kvs_delete_go(void *kv, t_kv *map)
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
				&& map->kv_equ((char *)map->kvs + i * map->size, kv))
		{
			map->kv_delete((char *)map->kvs + i * map->size);
			map->flags[i] = KV_DELETED;
			map->used -= 1;
			return (1);
		}
		j++;
		i = (i + 1) % map->capacity;
	}
	return (0);
}

int			kvs_delete(void *kv, t_kv *map)
{
	int	ret;

	ret = kvs_delete_go(kv, map);
	if (ret == 1)
	{
		if (map->used < (size_t)(map->capacity * (map->threshold / 2))
				&& map->capacity >= 32)
		{
			map = kvs_resize(map->capacity / 2, map);
		}
	}
	return (ret);
}
