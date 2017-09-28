/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skv_delete.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 14:09:32 by npineau           #+#    #+#             */
/*   Updated: 2017/09/28 14:13:53 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test/skv.h"

void	skv_delete(t_skv *skv)
{
	free(skv->k);
	free(skv->v);
}
