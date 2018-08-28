
# include "../includes/prototypes.h"

void    print_blocks_mem(t_container *container)
{
    int i;
    int blockSize;

    i = 0;
    blockSize = ft_strcmp(container->containerName, "TINY") == 0 ? TINY : SMALL; 
    while(i < BLOCKS_LENGTH)
    {
        if(container->blocks[i] != 0)
        {
            ft_printf(" %02X \e[02m- \e[0m", (void *)container + (i * blockSize) + sizeof(t_container));
            ft_printf("%02X : \e[32m %d octets \e[00m\n", (void *)container + (i * TINY) + sizeof(t_container) + blockSize, blockSize);
        };
        i++;
    };
};

void    print_container_mem(t_container *container)
{
    while(container)
    {
        int i;

        i = 0;
        ft_printf("\n\e[33m%s : \e[0m%02X\n\n", container->containerName, container);
        print_blocks_mem(container);
        container = container->next;
    };
};

void    print_large_mem(t_large *large)
{
    while(large->next)
    {
        ft_printf("\n\e[33mLARGE\e[0m: %p\n\n", large);
        ft_printf(" %02X \e[02m- \e[0m", (void *)large + sizeof(t_large));
        ft_printf("%02X : \e[32m %d octets \e[00m\n", (void *)large + sizeof(t_large) + large->length, large->length);
        large = large->next;
    };
    ft_printf("\n\e[33mLARGE\e[0m: %p\n\n", large);
    ft_printf(" %02X \e[02m- \e[0m", (void *)large + sizeof(t_large));
    ft_printf("%02X : \e[32m %d octets \e[00m\n", (void *)large + sizeof(t_large) + large->length, large->length);
};

void show_alloc_mem() {
    t_env       *env = &s_env;

    if(env->tiny)
        print_container_mem(env->tiny);
    else
        ft_putstr("\n\e[33mTINY\e[0m : NULL\n");
    if(env->small)
        print_container_mem(env->small);
    else
        ft_putstr("\n\e[33mSMALL\e[0m : NULL\n");
    if(env->large)
        print_large_mem(env->large);
    else
        ft_putstr("\n\e[33mLARGE\e[0m : NULL\n");
};