/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skv.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 12:44:16 by npineau           #+#    #+#             */
/*   Updated: 2017/09/29 15:58:12 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SKV_H
# define SKV_H

typedef struct	s_skv
{
	char		*k;
	char		*v;
}				t_skv;

void			*str_kv_new(char *k, char *v);
t_skv			*skv_copy(t_skv *skv);
void			skv_delete(t_skv *skv);
int				skv_equ(t_skv *l, t_skv *r);
size_t			skv_hash(t_skv *skv, size_t capacity);
void			*str_kv_new(char *k, char *v);
ssize_t			skv_print(int fd, t_kv *skvs);
t_kv_ops		skv_ops(void);

#endif
