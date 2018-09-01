
# include "../includes/malloc.h"

void    print_blocks_content(t_container *container)
{
    int i;
    int isIn;

    i = 0;
    isIn = 0;
    while(i < BLOCKS_LENGTH)
    {
        if(container->blocks[i] != 0)
            ft_printf("'%s'\n", container + i + 1);
        i++;
    }
};

void    print_container_content(t_container *container)
{
    while(container)
    {
        int i;

        i = 0;
        ft_putstr(container->name);
        ft_putstr(": ");
        ft_printf("%p\n", container);
        print_blocks_content(container);
        container = container->next;
    };
}

void    print_large_content(t_large *large)
{
    while(large->next)
    {
        ft_printf("LARGE: %p\n%s\n", large, large + 1);
        large = large->next;
    };
    ft_printf("LARGE: %p\n%s\n", large, large + 1);
}

void show_alloc_content()
{
    t_env       *env = &g_env;

    if(env->tiny)
        print_container_content(env->tiny);
    else
        ft_putstr("TINY : NULL");
    ft_putchar('\n');
    if(env->small)
        print_container_content(env->small);
    else
        ft_putstr("SMALL : NULL");
    ft_putchar('\n');
    if(env->large)
        print_large_content(env->large);
    else
        ft_putstr("LARGE : NULL");
    ft_putchar('\n');
}