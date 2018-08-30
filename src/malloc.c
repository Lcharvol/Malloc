
# include "../includes/prototypes.h"

t_env s_env = {NULL, NULL, NULL};

void    *malloc(size_t size) {
    ft_printf("MALLOC: %d\n", size);
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
    if(!s_env.large) {
        ft_printf("CREATE NEW LARGE\n");
        s_env.large = create_large(size);
    }
    return allocate_large(s_env.large, size);
}