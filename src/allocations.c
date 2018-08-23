# include "../includes/prototypes.h"

int     is_size_avalaible(size_t *blocks, int start, int size)
{
    while(start < start + size)
    {
        if((start > BLOCKS_LENGTH) | (blocks[start] != 0))
            return -1;
        start++;
    };
    return 0;
};

void    *allocate_new_block(t_container *container, int size)
{
    int i;
    int i2;

    i = 0;
    while(i < BLOCKS_LENGTH)
    {
        if((container->blocks[i] == 0) & is_size_avalaible((size_t *)container->blocks, i , size))
        {
            i2 = i;
            while(i2 < (i + size))
            {
                container->blocks[i2] = (i2 == i) | (i2 == (i + size - 1)) ? 2 : 1;
                i2++;
            };
            return &container + 32 + (i * TINY);
        };
        i++;
    }
    return NULL;
};