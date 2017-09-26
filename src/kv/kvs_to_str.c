/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kv_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/26 11:03:26 by npineau           #+#    #+#             */
/*   Updated: 2017/09/26 13:34:02 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "inc/kv.h"

static char	*joinWith(char *glue, char **strs)
{
	size_t	i;
	size_t	j;
	char	*str;

	str = NULL;
	return (str);
}

int			kv_print(char* (*as_str)(void *), t_kv *kvs, int fd)
{
	char	**kv_as_str;
	size_t	i;

	kv_as_str = malloc(sizeof(char **) * kvs->used);
	if (kv_as_str == NULL)
	{
		return (0);
	}
	i = 0;
	while (i < kvs->capacity)
	{
		i += 1;
	}
	return (1);
}
