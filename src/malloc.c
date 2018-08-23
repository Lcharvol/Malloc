
# include "../includes/prototypes.h"

t_env s_env = {NULL, NULL, NULL};

void    *malloc(size_t size) {
    if(!size)
        return 0;
    if(size < TINY)
    {
        if(!s_env.tiny)
            s_env.tiny = create_container(TINY * BLOCKS_LENGTH, "TINY");
        return allocate_new_block(s_env.tiny, size);
    }
    if(size < SMALL) {
        if(!s_env.small)
            s_env.small = create_container(SMALL * BLOCKS_LENGTH, "SMALL");
        return mmap(0, size + 1, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
    }
    if(!s_env.large)
        s_env.large = create_large();
    return s_env.large;
}