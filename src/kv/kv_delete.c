/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kv_delete.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 14:56:19 by npineau           #+#    #+#             */
/*   Updated: 2017/09/26 10:58:23 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/kv.h"

static int	kv_delete_go(void *kv, t_kv *map)
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
			map->used -= 1;
			return (1);
		}
		j++;
		i = (i + 1) % map->capacity;
	}
	return (0);
}

int			kv_delete(void *kv, t_kv *map)
{
	int	ret;

	ret = kv_delete_go(kv, map);
	if (ret == 1)
	{
		if (map->used < (size_t)(map->capacity * (map->threshold / 2)))
		{
			map = kv_resize(map->capacity / 2, map);
		}
	}
		
	return (ret);
}
