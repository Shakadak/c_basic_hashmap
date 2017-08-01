#include <stdlib.h>
#include "inc/hashmap.h"

static void	static_bzero(void *src, size_t len)
{
	unsigned char	*mem;
	size_t			i;

	if (src)
	{
		mem = (unsigned char *)src;
		i = 0;
		while (i < len)
			mem[i] = 0;
	}
}

static t_hashmap	*transfer(t_hashmap *map,
		size_t capacity,
		t_kv_flags *flags,
		void *kvs)
{
	size_t	i;

	i = 0;
	while (i < capacity)
	{
		if (flags[i] == KV_OCCUPIED)
		{
			hashmap_insert(map, kvs + i * map->size); 
			map->kv_delete(kvs + i * map->size);
		}
	}
	return map;
}

t_hashmap	*hashmap_resize(size_t capacity, t_hashmap *map)
{
	t_kv_flags	*old_flags;
	void		*old_kvs;
	size_t		old_capacity;

	old_flags = map->flags;
	old_kvs = map->kvs;
	old_capacity = map->capacity;
	map->flags = malloc(capacity * sizeof(t_kv_flags));
	static_bzero(map->flags, capacity);
	map->kvs = malloc(map->size * capacity);
	static_bzero(map->kvs, map->size * capacity);
	map->capacity = capacity;
	map->used = 0;
	transfer(map, old_capacity, old_flags, old_kvs);
	free(old_kvs);
	free(old_flags);
	return (map);
}
