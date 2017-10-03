/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minigraph.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 11:51:32 by npineau           #+#    #+#             */
/*   Updated: 2017/10/03 12:40:13 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "inc/kv.h"
#include "test/skv.h"

int	main(void)
{
	t_kv		kvs;

	kvs = kvs_new(skv_ops(), 0.7, 16, sizeof(t_skv));
	kvs_insert(skv_new("A", "B"), &kvs);
	skv_print(1, &kvs);
	kvs_insert(skv_new("B", "C, D"), &kvs);
	skv_print(1, &kvs);
	kvs_insert(skv_new("C", "E"), &kvs);
	skv_print(1, &kvs);
	kvs_insert(skv_new("D", "E"), &kvs);
	skv_print(1, &kvs);
	kvs_delete(skv_new("B", ""), &kvs);
	skv_print(1, &kvs);
	kvs_delete(skv_new("C", ""), &kvs);
	skv_print(1, &kvs);
	kvs_delete(skv_new("A", ""), &kvs);
	skv_print(1, &kvs);
	kvs_delete(skv_new("F", ""), &kvs);
	skv_print(1, &kvs);
	return (0);
}
