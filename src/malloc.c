
# include "../includes/prototypes.h"

t_env s_env = {NULL, NULL, NULL};

void    *get_large_ptr(t_large *large)
{
    while(large->next)
        large = large->next;
    return large + sizeof(t_large);
};

int get_strunc_length(t_large *container)
{
    int length;

    length = 0;
    while(container)
    {
        length +=1;
        container = container ->next;
    };
    return length;
};

void    *malloc(size_t size)
{
    if(!size)
        return NULL;
    if(size <= TINY)
    {
        if(!s_env.tiny)
            s_env.tiny = create_container(TINY * BLOCKS_LENGTH, "TINY");
        return allocate_tiny_and_small(s_env.tiny);
    }
    if(size <= SMALL) {
        if(!s_env.small)
            s_env.small = create_container(SMALL * BLOCKS_LENGTH, "SMALL");
        return allocate_tiny_and_small(s_env.small);
    }
    if(!s_env.large)
    {
        s_env.large = create_large(size);
        return s_env.large + sizeof(t_large);
    }
    s_env.large = allocate_large(s_env.large, size);
    return get_large_ptr(s_env.large);
};