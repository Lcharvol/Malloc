# include "../includes/prototypes.h"

int     is_large_ptr(void *ptr)
{
    t_large *large = s_env.large;
    int pos;

    pos = 0;
    while(large)
    {
        if((large + 1) == ptr)
            return pos;
        large = large->next;
        pos++;
    };
    if((large + 1) == ptr)
        return pos;
    return -1;
}

void     *free_tiny_or_small(void *ptr)
{

};

void    *free_large(int pos, void *ptr)
{
    t_large *large = s_env.large;
    size_t  length;

    length = s_env.large[pos].length;
    if(pos == 0)
        s_env.large = s_env.large->next;
    else
        s_env.large[pos - 1].next = &s_env.large[pos + 1];
    munmap(ptr - sizeof(t_large), length + sizeof(t_large));
};

void    free(void *ptr)
{
    int largePos;
    if((largePos = is_large_ptr(ptr)) != -1)
        free_large(largePos, ptr);
    else
        free_tiny_or_small(ptr);
};