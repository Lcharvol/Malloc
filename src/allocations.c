# include "../includes/prototypes.h"

// t_container *add_new_tiny_or_small(t_container *container)
// {
//     t_container *newContainer;
//     t_container *tmp;

//     tmp = container;
//     size_t size;

//     size = ft_strcmp(container->containerName, "TINY") ? TINY * BLOCKS_LENGTH : SMALL * BLOCKS_LENGTH;
//     newContainer = create_container(size, container->containerName);
//     while(container->next)
//         container = container->next;
//     container->next = newContainer;
//     container = tmp;
//     return container;
// };

// t_large *new_large(size_t size)
// {
//     t_large *newLarge;

//     newLarge = create_large(size);
//     return newLarge;
// };

void    *allocate_tiny_and_small(t_container *container)
{
    int i;
    int blockSize;
    t_container *tmp;

    tmp = container;
    blockSize = ft_strcmp("TINY", container->containerName) == 0 ? TINY : SMALL;
    while(container)
    {
        i = 0;
        while(i < BLOCKS_LENGTH)
        {
            if((container->next == NULL) & (i == BLOCKS_LENGTH - 1))
                container->next = create_container(blockSize * BLOCKS_LENGTH, container->containerName);
            if(container->blocks[i] == 0)
            {
                container->blocks[i] = 1;
                return (void *)container + sizeof(t_container) + (i * blockSize);
            };
            i++;
        };
        container = container->next;
    };
    return NULL;
};

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
};