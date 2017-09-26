/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kv.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 12:13:08 by npineau           #+#    #+#             */
/*   Updated: 2017/09/26 10:57:33 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KV_H
# define KV_H

# include <stddef.h>

typedef enum	e_kv_flags
{
	KV_EMPTY,
	KV_OCCUPIED,
	KV_DELETED
}				t_kv_flags;

typedef int		(*t_kv_copy)(void* src, void* dst);
typedef int		(*t_kv_equ)(void*, void*);
typedef size_t	(*t_kv_hash)(void*, size_t capacity);
typedef int		(*t_kv_empty)(void*);
typedef void	(*t_kv_delete)(void*);

typedef struct	s_kv_ops
{
	t_kv_copy	kv_copy;
	t_kv_equ	kv_equ;
	t_kv_empty	kv_empty;
	t_kv_hash	kv_hash;
	t_kv_delete	kv_delete;
}				t_kv_ops;

typedef struct	s_kv
{
	size_t		size;
	size_t		capacity;
	size_t		used;
	double		threshold;
	t_kv_copy	kv_copy;
	t_kv_equ	kv_equ;
	t_kv_empty	kv_empty;
	t_kv_hash	kv_hash;
	t_kv_delete	kv_delete;
	t_kv_flags	*flags;
	void		*kvs;
}				t_kv;

t_kv			kv_new(t_kv_ops kv_ops,
		double lf_limit,
		size_t capacity,
		size_t size);
int				kv_insert(void *kv, t_kv *map);
int				kv_search(t_kv *map, void *kv, void *kv_out);
int				kv_delete(void *kv, t_kv *map);
t_kv		*kv_resize(size_t capacity, t_kv *map);

#endif
