/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skv_new.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 12:22:12 by npineau           #+#    #+#             */
/*   Updated: 2017/10/03 11:56:40 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "test/skv.h"

static size_t	mstrlen(const char *str)
{
	size_t len;

	len = 0;
	while (str[len] != '\0')
	{
		len += 1;
	}
	return (len);
}

static char		*mstrdup(const char *str)
{
	char	*dup;
	size_t	i;

	dup = (char *)malloc(sizeof(char) * (mstrlen(str) + 1));
	i = 0;
	while (str[i] != '\0')
	{
		dup[i] = str[i];
		i += 1;
	}
	dup[i] = '\0';
	return (dup);
}

void			*skv_new(char *k, char *v)
{
	t_skv	*skv;

	skv = malloc(sizeof(t_skv));
	skv->k = mstrdup(k);
	skv->v = mstrdup(v);
	return ((void *)skv);
}
