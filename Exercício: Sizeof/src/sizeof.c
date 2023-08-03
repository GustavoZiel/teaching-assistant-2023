#include <stdio.h>
#include <stdlib.h>

int main(){

    printf("%lu\n", sizeof(char));
    printf("%lu\n", sizeof(int));
    printf("%lu\n", sizeof(float));
    printf("%lu\n", sizeof(double));

    printf("%lu\n", sizeof(unsigned char));
    printf("%lu\n", sizeof(signed char));
    printf("%lu\n", sizeof(unsigned int));
    printf("%lu\n", sizeof(signed int));
    
    printf("%lu\n", sizeof(short int));
    printf("%lu\n", sizeof(long long int));

    return EXIT_SUCCESS;
}