/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skv_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 10:33:33 by npineau           #+#    #+#             */
/*   Updated: 2017/09/29 10:54:47 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "inc/kv.h"
#include "test/skv.h"

static char	*skv_to_str(t_skv *skv)
{
	char	*str;

	return (str);
}

ssize_t		skv_print(int fd, t_kv *skvs)
{
	size_t	len;
	char	*buffer;

	buffer = kvs_to_str((char *(*)(void *))skv_to_str, skvs, &len);
	return (write(fd, buffer, len));
}
