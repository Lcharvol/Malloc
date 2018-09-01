#ifndef MALLOC_H
# define MALLOC_H

#include <stdlib.h>
#include <stdio.h>
#include <sys/mman.h>
#include "../libft/includes/libft.h"
#include <errno.h>

# define                TINY 32
# define                SMALL 1024

# define                BLOCKS_LENGTH 128

typedef struct          s_container
{
    size_t              length;
    int                 blocks[BLOCKS_LENGTH];
    char                *containerName;
    struct s_container  *next;
}					    t_container;

typedef struct          s_large
{
    size_t              length;
    struct s_large  *next;
}					    t_large;

typedef struct		    s_env
{
    t_container         *tiny;
    t_container         *small;
    t_large        *large;
}					    t_env;

extern t_env s_env;

void                    free(void *ptr);
void                    *malloc(size_t size);
void                    *realloc(void *ptr, size_t size);
void                    show_alloc_mem();
void                    show_alloc_content();
void                    *allocate_tiny_and_small(t_container *container);
void                    *allocate_large(t_large *container, size_t size);
void                    print_alloc_summ(t_env *env);
void                    free_large(int pos, void *ptr);
void                    free_tiny_or_small(void *ptr);

int                     is_large_ptr(void *ptr);
int                     get_ptr_pos_in_container(void *ptr, t_container *container);
int                     get_ptr_pos_in_small(void *ptr);

t_large                 *create_large(size_t length);

t_container             *create_container(size_t length, char *name);
t_container       *free_empty_container(t_container *container);

#endif