#include "./includes/prototypes.h"

int main() {
    char *str = (char *)malloc(10);
    int i = 0;

    while( i < 10) {
        str[i] = 'C';
        i++;
    }
    str[i] = '\0';
    show_alloc_mem();
    return 0;
}