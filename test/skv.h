/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skv.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 12:44:16 by npineau           #+#    #+#             */
/*   Updated: 2017/10/03 11:28:49 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SKV_H
# define SKV_H

# include <unistd.h>
# include "inc/kv.h"

typedef struct	s_skv
{
	char		*k;
	char		*v;
}				t_skv;

void			*skv_new(char *k, char *v);
int				skv_copy(t_skv *in, t_skv *out);
void			skv_delete(t_skv *skv);
int				skv_equ(t_skv *l, t_skv *r);
size_t			skv_hash(t_skv *skv, size_t capacity);
ssize_t			skv_print(int fd, t_kv *skvs);
t_kv_ops		skv_ops(void);

#endif
