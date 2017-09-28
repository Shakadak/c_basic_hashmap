/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skv.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 12:44:16 by npineau           #+#    #+#             */
/*   Updated: 2017/09/28 13:43:29 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SKV_H
# define SKV_H

typedef struct	s_skv
{
	char		*k;
	char		*v;
}				t_skv;

void	*str_kv_new(char *k, char *v);
t_skv	*skv_copy(t_skv *skv);
#endif
