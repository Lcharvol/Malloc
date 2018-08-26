# include "../includes/prototypes.h"

// int     is_size_avalaible(size_t *blocks, int start, int size)
// {
//     while(start < start + size)
//     {
//         if((start > BLOCKS_LENGTH) | (blocks[start] != 0))
//             return -1;
//         start++;
//     };
//     return 0;
// };

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