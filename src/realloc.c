# include "../includes/prototypes.h"



void                    *realloc(void *ptr, size_t size)
{
    int ptrPos;

    ptrPos = 0;
    if(!ptr)
        return NULL;
    if((ptrPos = is_large_ptr(ptr)) != -1)
    {
        if(size < s_env.large[ptrPos].length)
            return ptr;
        free_large(ptrPos, ptr);
        return malloc(size);
    }
    else if((ptrPos = get_ptr_pos_in_container(ptr, s_env.tiny)) != -1)
    {
        if(size > TINY)
        {
            free_tiny_or_small(ptr);
            return malloc(size);
        }
        else
            return ptr;
    }
    else if((ptrPos = get_ptr_pos_in_container(ptr, s_env.small)) != -1)
    {
       if(size > SMALL)
        {
            free_tiny_or_small(ptr);
            return malloc(size);
        }
        else
            return ptr;
    };
    return NULL;
};