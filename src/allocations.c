# include "../includes/prototypes.h"

t_container *add_new_tiny_or_small(t_container *container)
{
    t_container *newContainer;
    size_t size;

    size = ft_strcmp(container->containerName, "TINY") ? TINY * BLOCKS_LENGTH : SMALL*BLOCKS_LENGTH;
    newContainer = create_container(size, container->containerName);
    newContainer->next = NULL;
    container->next = newContainer;
    return container;
};

t_large *add_new_large(t_large *large, size_t size)
{
    t_large *newLarge;

    newLarge = create_large(size);
    newLarge->taken = 1;
    return newLarge + sizeof(t_large);
};

void    *allocate_tiny_and_small(t_container *container)
{
    int i;
    int blockSize;

    i = 0;
    blockSize = ft_strcmp("TINY", container->containerName) == 0 ? TINY : SMALL;
    while(i < BLOCKS_LENGTH)
    {
        if(container->blocks[i] == 0)
        {
            container->blocks[i] = 1;
            return (void *)container + sizeof(t_container) + (i * blockSize);
        };
        i++;
    }
    if(container->next == NULL)
    {
        allocate_tiny_and_small(add_new_tiny_or_small(container));
    }
    return allocate_tiny_and_small(container->next);
};

void    *allocate_large(t_large *large, size_t size)
{
    t_large *newPtr;
    while(large->next)
    {
        if(large->taken == 0)
        {
           ft_printf("DIDNT ADD NEW LARGE\n");
            large->taken = 1;
            return (void *)large + sizeof(t_large);
        };
        large = large->next;
    }
    ft_printf("ADD NEW LARGE\n");
    newPtr = add_new_large(large, size);
    large->next = newPtr;
    return newPtr;
};