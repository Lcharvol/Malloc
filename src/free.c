# include "../includes/prototypes.h"

t_large            *is_large_ptr(void *ptr)
{
    t_large *large = s_env.large;
    while(large)
    {
        if((large + 1) == ptr)
            return large;
        large = large->next;
    };
    if((large + 1) == ptr)
        return large;
    return NULL;
}

void     *free_tiny_or_small(void *ptr)
{

};

void    *free_large(t_large *large)
{

};

void    free(void *ptr)
{
    t_container    *startPtr;
    t_large         *large;
    if((large = is_large_ptr(ptr)) != NULL)
        free_large(large);
    else
        free_tiny_or_small(ptr);
};