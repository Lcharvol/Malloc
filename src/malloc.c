
# include "../includes/prototypes.h"

t_env s_env = {NULL, NULL, NULL};

void    *malloc(size_t size) {
    if(!size)
        return 0;
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
        s_env.large = create_large(size);
    return allocate_large(s_env.large, size);
}