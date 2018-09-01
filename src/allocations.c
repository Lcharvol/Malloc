# include "../includes/malloc.h"

void    *allocate_tiny_and_small(t_container *container)
{
    int i;
    int block_size;
    t_container *tmp;

    tmp = container;
    block_size = ft_strcmp("TINY", container->name) == 0 ? TINY : SMALL;
    while(container)
    {
        i = 0;
        while(i < BLOCKS_LENGTH)
        {
            if((container->next == NULL) & (i == BLOCKS_LENGTH - 1))
                container->next = create_container(block_size * BLOCKS_LENGTH, container->name);
            if(container->blocks[i] == 0)
            {
                container->blocks[i] = 1;
                return (void *)container + sizeof(t_container) + (i * block_size);
            };
            i++;
        };
        container = container->next;
    };
    return NULL;
}

void    *allocate_large(t_large *large, size_t size)
{
    t_large *newPtr;
    t_large *tmp;

    tmp = large;
    while(large->next)
        large = large->next;
    newPtr = create_large(size);
    large->next = newPtr;
    return tmp;
}