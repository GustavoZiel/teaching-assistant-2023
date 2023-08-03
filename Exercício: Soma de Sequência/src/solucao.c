#include <stdio.h>

int main(){

    // Lendo quantidade de termos da sequência
    int qtd_termos;
    scanf("%d",&qtd_termos);

    // Primeiro denominador é 1, será incrementado a cada termo
    float denominador = 1;
    
    // Se 'sinal' == 0, termo é positivo
    // Se 'sinal' == 1, termo é positivo
    int sinal = 0; // Primeiro termo é 1, portanto positivo
    
    float resultado = 0;
    while(qtd_termos > 0){
        if(sinal == 0){
            resultado += 1/denominador;
            sinal++;
        }
        else{
            resultado -= 1/denominador;
            sinal--;
        }
        denominador++;
        qtd_termos--;
    }

    // Imprimir com 4 casa decimais e sem quebra de linha
    printf("%.4f",resultado);

    return 0;
}