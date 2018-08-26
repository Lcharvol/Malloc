# include "../includes/prototypes.h"

void    *allocate_tiny_and_small(t_container *container)
{
    int i;

    i = 0;
    while(i < BLOCKS_LENGTH)
    {
        if(container->blocks[i] == 0)
        {
            container->blocks[i] = 1;
            return &container[i + 1];
        };
        i++;
    }
    return NULL;
};

t_large *add_new_large(t_large *large, size_t size)
{
    t_large *newLarge;

    newLarge = create_large(size);
    newLarge->taken = 1;
    large->next = newLarge;
    return &newLarge[1];
};

void    *allocate_large(t_large *large, size_t size)
{
    if(large->taken != 0)
        return add_new_large(large, size);
    else
    {
        large->taken = 1;
        return &large[1];
    }
};