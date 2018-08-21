#ifndef MALLOC_H
# define MALLOC_H

#include <stdlib.h>
#include <stdio.h>
#include <sys/mman.h>
#include "../libft/includes/libft.h"

# define TINY 16
# define SMALL 512
# define LARGE 4000

typedef struct		s_page
{
    int             start;
    size_t          size;
    char            *pageName;
    int             *blocks;
    struct s_page    *next;
}					t_page;
typedef struct		s_env
{
    t_page          *tiny;
    t_page          *small;
    t_page          *large;
}					t_env;
extern t_env s_env;

void                free(void *ptr);
void                *malloc(size_t size);
void                *realloc(void *ptr, size_t size);
void                show_alloc_mem();

#endif