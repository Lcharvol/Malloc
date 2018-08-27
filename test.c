#include "./includes/prototypes.h"

int main() {

    // TINY 1
    char *str1 = (char *)malloc(16);
    int i = 0;

    while( i < 16) {
        str1[i] = 'T';
        i++;
    }
    str1[i] = '\0';

    // TINY 2
    char *str3 = (char *)malloc(5);
    i = 0;

    while( i < 5) {
        str3[i] = 'T';
        i++;
    }
    str3[i] = '\0';

    //SMALL

    char *str2 = (char *)malloc(17);
    i = 0;

    while( i < 17) {
        str2[i] = 'S';
        i++;
    }
    str2[i] = '\0';

    // LARGE 1

    char *str4 = (char *)malloc(4097);
    i = 0;

    while( i < 4097) {
        str4[i] = 'L';
        i++;
    }
    str4[i] = '\0';

    // LARGE 2

    char *str5 = (char *)malloc(10000);
    i = 0;

    while( i < 10000) {
        str5[i] = 'B';
        i++;
    }
    str5[i] = '\0';

    i = 0;
    char *str6;
    while(i < 1200)
    {
        str6 = (char *)malloc(10);
        str6[0] = 'w';
        str6[1] = '\0';
        i++;
    }

    // SHOW ALLOCATE MEMORY

    show_alloc_mem();

    // SHOW ALLOCATE CONTENT

    // show_alloc_content();

    return 0;
}