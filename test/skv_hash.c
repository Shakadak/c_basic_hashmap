/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skv_hash.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 10:01:34 by npineau           #+#    #+#             */
/*   Updated: 2017/09/29 10:54:17 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "test/skv.h"

size_t	skv_hash(t_skv *skv, size_t capacity)
{
	uint64_t	hash;
	uint8_t		*data;
	size_t		i;

	hash = 0xcbf29ce484222325;
	data = (uint8_t *)skv->k;
	i = 0;
	while (data[i] != 0)
	{
		hash = hash ^ data[i];
		hash = hash * 0x100000001b3;
		i += 1;
	}
	return (hash % capacity);
}
