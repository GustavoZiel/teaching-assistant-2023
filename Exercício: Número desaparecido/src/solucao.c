#include <stdio.h>

void preenchendo_vetor(int *vetor, int n){
    // Preenchendo vetor de tamanho N
    for(int i = 0; i < n-1; i++){
        scanf("%d",&vetor[i]);
    }
}
void imprimir_vetor(int *vetor, int n){
    // Imprimindo vetor
    for(int i = 0; i < n-1; i++){
        printf("%d ",vetor[i]);
    }
    printf("\n");
}
void ordenar_vetor(int *vetor, int n){
    // Ordenando vetor (Bubble Sort COM otimizações)
    int aux, flag = 0;
    for(int i = 0; i < n - 1; i++){
        flag = 0;
        for(int j = 0; j < n - i - 2; j++){
            if(vetor[j] > vetor[j+1]){
                aux = vetor[j+1];
                vetor[j+1] = vetor[j];    
                vetor[j] = aux;
                flag = 1;
            }
        }
        if(flag == 0){
            break;
        }
    }

    // Ordenando vetor (Bubble Sort SEM otimizações, implementação incorreta)
    // int aux;
    // for(int i = 0; i < n - 1; i++){
    //     for(int j = 0; j < n - 2; j++){
    //         if(vetor[j] > vetor[j+1]){
    //             aux = vetor[j+1];
    //             vetor[j+1] = vetor[j];    
    //             vetor[j] = aux;
    //         }
    //     }
    // }
}
int numero_desaparecido(int *vetor, int n){
    for(int i = 0; i < n-1; i++){
        if((i+1) != vetor[i]){
            return i+1;
        }
    } 
    return n;
}

int main(){

    // Informando N
    int n;
    scanf("%d",&n);

    // Preenchendo vetor de tamanho N
    int vetor[n-1];
    preenchendo_vetor(vetor,n);

    // Ordenando vetor (Bubble Sort com otimizações)
    ordenar_vetor(vetor,n);
    
    // Imprimindo vetor
    // imprimir_vetor(vetor,n);

    // Achando número desaparecido
    int missing_number;
    missing_number = numero_desaparecido(vetor,n);
    
    // Imprimindo resposta
    printf("Numero desaparecido: %d",missing_number);

    return 0;
}