/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kvs_to_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/26 11:03:26 by npineau           #+#    #+#             */
/*   Updated: 2017/09/26 16:35:43 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "inc/kv.h"

static size_t	strlen(char *str)
{
	size_t len;

	len = 0;
	while (str[len] != '\0')
	{
		len += 1;
	}
	return (len);
}

static char*	stpcpy(char *out, const char *in)
{
	size_t	i;

	i = 0;
	while (in[i] != '\0')
	{
		out[i] = in[i];
		i += 1;
	}
	out[i] = '\0';
	return (&(out[i]));
}

static char		*join_with(char *glue, char **strs, size_t *len_out)
{
	size_t	i;
	char	*str;
	size_t	capacity;
	char	*end;

	i = 0;
	capacity = 0;
	while (strs[i] != NULL)
	{
		capacity += strlen(strs[i]);
		i += 1;
	}
	capacity += (i - 1) * strlen(glue);
	str = malloc(sizeof(char) * capacity);
	i = 0;
	end = str;
	while (strs[i] != NULL)
	{
		end = stpcpy(end, strs[i]);
		i += 1;
		if (strs[i] != NULL)
			end = stpcpy(end, glue);
	}
	return (str);
}

char			*kvs_to_str(char* (*as_str)(void *), t_kv *kvs, size_t *len_out)
{
	char	**kv_as_str;
	size_t	i;
	size_t	j;

	kv_as_str = malloc(sizeof(char **) * kvs->used);
	if (kv_as_str == NULL)
	{
		return (0);
	}
	i = 0;
	j = 0;
	while (i < kvs->capacity)
	{
		if(kvs->flags[i] == KV_OCCUPIED)
		{
			kv_as_str[j] = as_str(kvs->kvs + kvs->size * i);
			j += 1;
		}
		i += 1;
	}
	return (join_with(",\n", kv_as_str, len_out));
}
