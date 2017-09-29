/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minigraph.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 11:51:32 by npineau           #+#    #+#             */
/*   Updated: 2017/09/29 15:58:15 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "inc/kv.h"
#include "test/skv.h"

int	main(void)
{
	t_kv		kvs;
	t_kv_ops	ops;

	kvs = kvs_new(skv_ops(), 0.7, 16, sizeof(t_skv));
	return (0);
}
