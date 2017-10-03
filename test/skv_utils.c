/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skv_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 15:15:25 by npineau           #+#    #+#             */
/*   Updated: 2017/10/03 10:32:18 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/kv.h"
#include "test/skv.h"

t_kv_ops	skv_ops(void)
{
	t_kv_ops	ops;

	ops.kv_copy = (t_kv_copy)skv_copy;
	ops.kv_equ = (t_kv_equ)skv_equ;
	ops.kv_hash = (t_kv_hash)skv_hash;
	ops.kv_delete = (t_kv_delete)skv_delete;
	return (ops);
}
