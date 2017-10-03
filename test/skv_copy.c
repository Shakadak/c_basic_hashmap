/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skv_copy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 13:40:28 by npineau           #+#    #+#             */
/*   Updated: 2017/10/03 11:56:48 by npineau          ###   ########.fr       */
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

int				skv_copy(t_skv *in, t_skv *out)
{
	out->k = mstrdup(in->k);
	out->v = mstrdup(in->v);
	return (out->k != NULL);
}
