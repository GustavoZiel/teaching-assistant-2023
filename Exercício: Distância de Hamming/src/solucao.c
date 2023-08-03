#include <stdio.h>

int to_binary(int num){
    // Convertendo um int para seu correspondente em binário
    // 10 -> 1010
    int bin = 0, pot = 1;
    
    while(num > 0){
        bin += (num % 2)*pot;
        num = num / 2;
        pot *= 10;
    }

    return bin;
}

int hamming_distance(int num){
    // Contando quantos 1's aparecem em um número no formato binário 
    // 101010 (42) -> 3 1's
    int counter = 0;

    do{
        if(num % 10 == 1){
            counter++;
        }
        num = num / 10;
    }while( num != 0 );

    return counter;
}

int main(){

    int x, y;
    scanf("%d %d",&x,&y);

    int z = x ^ y;
    z = to_binary(z);
    printf("%d\n",hamming_distance(z));
    
    return 0;
}