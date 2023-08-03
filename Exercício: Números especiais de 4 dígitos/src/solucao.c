#include <stdio.h>
#include <math.h>

int main(){

    // Explicar como funciona a 'sqrt()' da math.h
    // int x;
    // scanf("%d",&x);
    // printf("%.4lf\n",sqrt(x));

    // Explicar como ler um número e separar suas duas dezenas, 1297 => 12|97
    int first_two, last_two, sum_dezenas;
    // int four_digit_number;
    // scanf("%d",&four_digit_number);
    // first_two = four_digit_number / 100;
    // last_two = four_digit_number % 100;
    // sum_dezenas = first_two + last_two;
    // printf("%d => %d | %d \n%d\n",four_digit_number,first_two,last_two,sum_dezenas);

    // Código para resolução do problema
    for(int i = 1000; i <= 9999; i++){
        first_two = i / 100;
        last_two = i % 100;
        sum_dezenas = first_two + last_two;
        if(sqrt(i) == sum_dezenas){
            printf("%d\n",i);
        }
    }
    
    return 0;
}