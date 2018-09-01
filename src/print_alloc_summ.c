# include "../includes/malloc.h"

int     get_container_alloc_summ(t_container *container, size_t blockSize)
{
    int i;
    int summ;

    summ = 0;
    while(container)
    {
        i = 0;
        while(i < BLOCKS_LENGTH)
        {
            if(container->blocks[i] != 0)
                summ += blockSize;
            i++;
        };
        container = container->next;
    };
    return summ;
}

int     get_large_alloc_summ(t_large *large)
{
    int summ;

    summ = 0;
    while(large)
    {
        summ += large->length;
        large = large->next;
    };
    return summ;
}

void    print_alloc_summ(t_env *env)
{
    int summ;

    summ = get_container_alloc_summ(env->tiny, TINY)
        + get_container_alloc_summ(env->small, SMALL) + get_large_alloc_summ(env->large);
    ft_printf("\n\e[35mTotal\e[0m : \e[32m%d octets\e[00m\n", summ);
}