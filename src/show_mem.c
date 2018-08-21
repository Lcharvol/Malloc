
# include "../includes/prototypes.h"

void    print_page(t_page *page)
{
    while(page)
    {
        int i;

        i = 0;
        ft_putstr(page->pageName);
        ft_putstr(": ");
        ft_printf("%p", page);
        page = page->next;
    };
}

void show_alloc_mem() {
    t_env       *env = &s_env;

    if(env->tiny)
        print_page(env->tiny);
    else
        ft_putstr("TINY: NULL");
    ft_putchar('\n');
    if(env->small)
        print_page(env->small);
    else
        ft_putstr("SMALL: NULL");
    ft_putchar('\n');
    if(env->large)
        print_page(env->large);
    else
        ft_putstr("LARGE: NULL");
    ft_putchar('\n');
};