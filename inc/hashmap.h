/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashmap.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 12:13:08 by npineau           #+#    #+#             */
/*   Updated: 2017/03/31 12:54:03 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HASHMAP_H
# define HASHMAP_H

# include <stddef.h>

typedef int	(*t_kv_copy)(void*, void*);
typedef int	(*t_kv_equ)(void*, void*);
typedef size_t	(*t_kv_hash)(void*, size_t);

typedef struct	s_kv_ops
{
	t_kv_copy	kv_copy;
	t_kv_equ	kv_equ;
	t_kv_hash	kv_hash;
}				t_kv_ops;

typedef struct	s_hashmap
{
	size_t		size;
	size_t		capacity;
	size_t		used;
	double		lf_limit;
	t_kv_copy	kv_copy;
	t_kv_equ	kv_equ;
	t_kv_hash	kv_hash;
	void		*kvs;
}				t_hashmap;

#endif
