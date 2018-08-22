# include "../includes/prototypes.h"

void    *allocate_new_block(t_container *container, int size)
{
    int i;

    i = 0;
    while(i < BLOCKS_LENGTH)
    {
        i++;
    }
    return &container + BLOCKS_LENGTH;
    return NULL;
};