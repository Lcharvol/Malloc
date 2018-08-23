# include "../includes/prototypes.h"

// t_zone	*create_zone(size_t size, char *name)
// {
// 	t_alloc	alloc;
// 	t_zone	*zone;

// 	size = ((size + sizeof(t_zone) + sizeof(t_alloc) - 1) / getpagesize()) *
// 	getpagesize() + getpagesize();
// 	if ((zone = mmap(NULL, size, PROT_READ | PROT_WRITE,
// 		MAP_PRIVATE | MAP_ANON, -1, 0)) == MAP_FAILED)
// 	{
// 		malloc_error(ERROR_MMAP, NULL);
// 		return (NULL);
// 	}
// 	malloc_log(LOG_MMAP, (uint64_t)zone, size);
// 	zone->size = size - sizeof(t_zone);
// 	zone->next = NULL;
// 	zone->name = name;
// 	alloc.size = zone->size - sizeof(t_alloc);
// 	alloc.type = TYPE_FREE;
// 	ft_memcpy(&zone[1], &alloc, sizeof(t_alloc));
// 	return (zone);
// }

t_container   *create_container(size_t length, char *name)
{
    t_container  *newContainer;
    int     i;
    i = 0;
    
    length = ((length + sizeof(t_container) - 1) / getpagesize()) * getpagesize() + getpagesize();
    if((newContainer = mmap(0, length, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0)) == MAP_FAILED)
        return NULL;
    newContainer->containerName = name;
    newContainer->length = length - sizeof(t_container);
    newContainer->next = NULL;
    return newContainer;
};

t_container  *create_large(void)
{
    t_container  *newContainer;
    newContainer = mmap(0, getpagesize(), PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
    return newContainer;
}