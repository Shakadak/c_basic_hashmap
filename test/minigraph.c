/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minigraph.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 11:51:32 by npineau           #+#    #+#             */
/*   Updated: 2017/09/28 11:57:14 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "inc/kv.h"

int print_kvs(t_kv *kvs)
{
	size_t	len;
	char	*str;

	str = kvs_to_str(str_kv_to_str, kvs, len);
	return write(1, str, len);
}

int main(void)
{
	t_kv	kvs;

	return (0);
}
