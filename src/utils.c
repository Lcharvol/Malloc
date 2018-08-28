# include "../includes/prototypes.h"

int                 is_large_ptr(void *ptr)
{
    int             pos;
    t_large         *tmp = s_env.large;

    pos = 0;
    while(tmp)
    {
        if((tmp + 1) == ptr)
            return pos;
        tmp = tmp->next;
        pos++;
    };
    if((tmp + 1) == ptr)
        return pos;
    return -1;
};

int             get_ptr_pos_in_container(void *ptr, t_container *container)
{
    int             i;
    int             blockSize;
    t_container     *tmp = container;

    blockSize = ft_strcmp(container->containerName, "TINY") == 0 ? TINY : SMALL; 
    while(tmp)
    {
        i = 0;
        while(i < BLOCKS_LENGTH)
        {
            if((void *)tmp + sizeof(t_container) + (i * blockSize) == ptr)
                return i;
            i++;
        };
        tmp = tmp->next;
    };
    return -1;
};