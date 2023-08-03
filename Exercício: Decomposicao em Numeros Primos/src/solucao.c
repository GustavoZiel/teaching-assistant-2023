#include <stdio.h>

int main(){

    // Ler número
    int x;
    scanf("%d",&x);

    // 'j' representa quantas vezes cada primo ocorre
    int j;
    for(int i = 2; x != 1; i++){
        // 'i' representa os primos, começando pelo primeiro '2'
        j = 0;
        if(x % i == 0){
            // Se o primo divide, dividirá o número até não conseguir mais
            // incrementando 'j' a cada itereção
            while(x % i == 0){
                x = x/i;
                j++;
            }
        }
        // Se o primo dividiu ao menos uma vez, imprimir saída desejada
        if (j != 0){
            printf("%d %d\n",i,j);
        }
    }
    
    return 0;
}