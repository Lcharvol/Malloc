#include "./includes/prototypes.h"

int main() {

    // TINY 1
    char *str = (char *)malloc(10);
    int i = 0;

    while( i < 10) {
        str[i] = 'T';
        i++;
    }
    str[i] = '\0';

    // TINY 2
    char *str3 = (char *)malloc(5);
    i = 0;

    while( i < 5) {
        str3[i] = 'T';
        i++;
    }
    str3[i] = '\0';

    //SMALL

    char *str2 = (char *)malloc(50);
    i = 0;

    while( i < 50) {
        str2[i] = 'S';
        i++;
    }
    str2[i] = '\0';

    // //LARGE

    // char *str3 = (char *)malloc(4096);
    // i = 0;

    // while( i < 4096) {
    //     str3[i] = 'S';
    //     i++;
    // }
    // str3[i] = '\0';

    // SHOW ALLOCATE MEMORY
    show_alloc_mem();
    return 0;
}