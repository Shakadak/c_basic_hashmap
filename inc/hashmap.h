/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashmap.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 12:13:08 by npineau           #+#    #+#             */
/*   Updated: 2017/06/07 14:49:42 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HASHMAP_H
# define HASHMAP_H

# include <stddef.h>

enum			e_kv_flags
{
	KV_EMPTY,
	KV_OCCUPIED,
	KV_DELETED
};

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

typedef struct	s_hashmap
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
	char		*flags;
	void		*kvs;
}				t_hashmap;

t_hashmap		hashmap_new(t_kv_ops kv_ops,
		double lf_limit,
		size_t capacity,
		size_t size);
int				hashmap_insert(t_hashmap *map, void *kv);
int				hashmap_search(t_hashmap *map, void *kv, void *kv_out);

#endif
