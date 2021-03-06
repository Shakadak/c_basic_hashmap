/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kvs_resize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/04 13:50:08 by npineau           #+#    #+#             */
/*   Updated: 2017/10/03 13:50:17 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "inc/kv.h"

static void	static_bzero(void *src, size_t len)
{
	unsigned char	*mem;
	size_t			i;

	if (src)
	{
		mem = (unsigned char *)src;
		i = 0;
		while (i < len)
		{
			mem[i] = 0;
			i += 1;
		}
	}
}

static t_kv	*transfer(t_kv *map,
		size_t capacity,
		t_kv_flags *flags,
		void *kvs)
{
	size_t	i;

	i = 0;
	while (i < capacity)
	{
		if (flags[i] == KV_OCCUPIED)
		{
			kvs_insert((char *)kvs + i * map->size, map);
			map->kv_delete((char *)kvs + i * map->size);
		}
		i += 1;
	}
	return (map);
}

t_kv		*kvs_resize(size_t capacity, t_kv *map)
{
	t_kv_flags	*old_flags;
	void		*old_kvs;
	size_t		old_capacity;

	old_flags = map->flags;
	old_kvs = map->kvs;
	old_capacity = map->capacity;
	map->flags = malloc(capacity * sizeof(t_kv_flags));
	static_bzero(map->flags, capacity);
	map->kvs = malloc(map->size * capacity);
	static_bzero(map->kvs, map->size * capacity);
	map->capacity = capacity;
	map->used = 0;
	transfer(map, old_capacity, old_flags, old_kvs);
	free(old_kvs);
	free(old_flags);
	return (map);
}
