
# include "../includes/prototypes.h"

t_env s_env = {NULL, NULL, NULL};

void    *malloc(size_t size) {
    if(!size) {
        return 0;
    };
    if(size < TINY)
    {
        if(!s_env.tiny)
            s_env.tiny = create_page("TINY");
        return allocate_new_block(s_env.tiny, size);
    }
    if(size < SMALL) {
        if(!s_env.small)
            s_env.small = create_page("SMALL");
        return mmap(0, size + 1, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
    }
    if(size < LARGE) {

    }
    return 0;
}