# include "../includes/prototypes.h"

t_page   *create_page(char *name)
{
    t_page  *newPage;
    int     i;

    i = 0;
    t_block newArray[100];
    newPage = mmap(0, sizeof(t_page), PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
    newPage->blocks = ft_memcpy(&newPage->blocks, &newArray, 99);
    newPage->pageName = name;
    newPage->start = (int)&newPage;
    newPage->next = NULL;
    return newPage;
};