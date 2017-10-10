/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kvs_extract.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/10 13:06:34 by npineau           #+#    #+#             */
/*   Updated: 2017/10/10 13:09:34 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/kv.h"

static int	kvs_extract_go(void *kv, t_kv *map, void *out)
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
			map->kv_copy((char *)map->kvs + i * map->size, out);
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

int			kvs_extract(void *kv, t_kv *map, void *out)
{
	int	ret;

	ret = kvs_extract_go(kv, map, out);
	if (ret == 1)
	{
		if (map->used < (size_t)(map->capacity * (map->threshold / 2)))
		{
			map = kvs_resize(map->capacity / 2, map);
		}
	}
	return (ret);
}
