#ifndef MALLOC_H
# define MALLOC_H

#include <stdlib.h>
#include <stdio.h>
#include <sys/mman.h>
#include "../libft/includes/libft.h"

# define                TINY 16
# define                SMALL 512
# define                LARGE 4000

# define                BLOCKS_LENGTH 128

typedef struct          s_container
{
    size_t              length;
    char                *containerName;
    size_t              blocks[BLOCKS_LENGTH];
    struct s_container  *next;
}					    t_container;
typedef struct		    s_env
{
    t_container         *tiny;
    t_container         *small;
    t_container         *large;
}					    t_env;

extern t_env s_env;

void                    free(void *ptr);
void                    *malloc(size_t size);
void                    *realloc(void *ptr, size_t size);
void                    show_alloc_mem();
void                    show_alloc_content();
t_container             *create_container(size_t length, char *name);
void                    *allocate_tiny(t_container *container);
t_container             *create_large(void);

#endif