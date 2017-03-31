/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashmap_new.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 12:52:46 by npineau           #+#    #+#             */
/*   Updated: 2017/03/31 13:50:53 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/hashmap.h"

t_hashmap	hashmap_new(t_kv_ops kv_ops,
		double lf_limit,
		size_t capacity,
		size_t size)
{
	t_hashmap	new;

	new.kvs = malloc(size * capacity);
	new.threshold = lf_limit;
	new.capacity = capacity;
	new.size = size;
	new.used = 0;
	new.kv_copy = kv_ops.kv_copy;
	new.kv_equ = kv_ops.kv_equ;
	new.kv_hash = kv_ops.kv_hash;
	return (new);
}
