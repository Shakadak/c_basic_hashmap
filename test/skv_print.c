/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skv_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 10:33:33 by npineau           #+#    #+#             */
/*   Updated: 2017/10/03 13:54:51 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "inc/kv.h"
#include "test/skv.h"

static size_t	mstrlen(char *str)
{
	size_t len;

	len = 0;
	while (str[len] != '\0')
	{
		len += 1;
	}
	return (len);
}

static char		*mstpcpy(char *out, const char *in)
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

static char		*skv_to_str(t_skv *skv)
{
	char	*str;
	int		k;
	int		v;

	k = skv->k != NULL;
	v = skv->v != NULL;
	str = malloc(sizeof(char)
			* (1 + (k ? mstrlen(skv->k) : 4) + 1
				+ 2 + 1 + (v ? mstrlen(skv->v) : 4) + 1 + 1));
	mstpcpy(mstpcpy(mstpcpy(mstpcpy(mstpcpy(mstpcpy(mstpcpy(str,
									(k ? "\"" : "<")),
								(k ? skv->k : "NULL")),
							(k ? "\"" : ">")),
						": "),
					(v ? "\"" : "<")),
				(v ? skv->v : "NULL")),
			(v ? "\"" : ">"));
	return (str);
}

ssize_t			skv_print(int fd, t_kv *skvs)
{
	size_t	len;
	char	*buffer;
	ssize_t	ret;

	buffer = kvs_to_str((t_kv_to_str)skv_to_str, skvs, &len);
	ret = write(fd, buffer, len);
	return (ret + write(fd, "\n", 1));
}
