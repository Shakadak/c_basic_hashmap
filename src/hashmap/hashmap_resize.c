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
	while (old_capacity > 0)
	{
		old_capacity -= 1;
		if (old_flags[old_capacity] == KV_OCCUPIED)
		{
			hashmap_insert(map, old_kvs + old_capacity * map->size); 
			map->kv_delete(old_kvs + old_capacity * map->size);
		}
	}
	free(old_kvs);
	free(old_flags);
	return (map);
}
