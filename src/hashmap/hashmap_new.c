/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashmap_new.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 12:52:46 by npineau           #+#    #+#             */
/*   Updated: 2017/06/07 12:51:33 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "inc/hashmap.h"

static void	static_bzero(void *src, size_t len)
{
	unsigned char	*mem;
	size_t			i;

	if (src)
	{
		mem = (unsigned char *)src;
		i = 0;
		while (i < len)
			mem[i] = 0;
	}
}

t_hashmap	hashmap_new(t_kv_ops kv_ops,
		double lf_limit,
		size_t capacity,
		size_t size)
{
	t_hashmap	new;

	new.kvs = malloc(size * capacity);
	static_bzero(new.kvs, size * capacity);
	new.threshold = lf_limit;
	new.capacity = capacity;
	new.size = size;
	new.used = 0;
	new.kv_copy = kv_ops.kv_copy;
	new.kv_equ = kv_ops.kv_equ;
	new.kv_empty = kv_ops.kv_empty;
	new.kv_hash = kv_ops.kv_hash;
	new.kv_delete = kv_ops.kv_delete;
	return (new);
}
