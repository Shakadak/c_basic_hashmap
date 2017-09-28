/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skv_equ.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 13:44:15 by npineau           #+#    #+#             */
/*   Updated: 2017/09/28 14:01:07 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test/skv.h"

static int	mstrequ(const char *l, const char *r)
{
	size_t	i;

	i = 0;
	while (l[i] != '\0' && r[i] != '\0')
	{
		if (l[i] != r[i])
		{
			return (0);
		}
		i += 1;
	}
	return (l[i] == r[i]);
}

int			skv_equ(t_skv *l, t_skv *r)
{
	return mstrequ(l->k, r->k);
}
