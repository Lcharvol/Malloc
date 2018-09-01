# include "../includes/malloc.h"

int                 is_large_ptr(void *ptr)
{
    int             pos;
    t_large         *tmp = g_env.large;

    pos = 0;
    while(tmp)
    {
        if((tmp + sizeof(t_large)) == ptr)
        {
            g_env.large = tmp;
            return pos;
        };
        tmp = tmp->next;
        pos++;
    };
    if((tmp + 1) == ptr)
        return pos;
    return -1;
}

int             get_ptr_pos_in_container(void *ptr, t_container *container)
{
    int             i;
    int             block_size;
    t_container     *tmp = container;

    if(!container)
        return -1;
    block_size = ft_strcmp(container->name, "TINY") == 0 ? TINY : SMALL; 
    i = 0;
    while(tmp)
    {
        while(i < BLOCKS_LENGTH)
        {
            if((void *)tmp + sizeof(t_container) + (i * block_size) == ptr)
                return i;
            i++;
        };
        tmp = tmp->next;
    };
    return -1;
}

int             is_empty_container(t_container *container)
{
    int i;
    int isEmpty;

    i = 0;
    isEmpty = 0;
    while(i < BLOCKS_LENGTH)
    {
        if(container->blocks[i] != 0)
            isEmpty = -1;
        i++;
    };
    return isEmpty;
}

t_container       *free_empty_container(t_container *container)
{
    int i;
    t_container *tmp;

    i = 0;
    tmp = container;
    while(container)
    {
        if(is_empty_container(container) == 0)
        {
            if(i == 0)
                tmp = container->next;
            else
                tmp[i - 1] = container[i + 1];
            munmap(container, container->length + sizeof(t_container));
            return tmp;
        };
        i++;
        container = container->next;
    };
    return tmp;
}