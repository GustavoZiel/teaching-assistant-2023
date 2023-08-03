#include <stdio.h>

void swap(int *a, int *b){
    // Troca de elementos para o Bubble
    int aux;
    aux = *a;
    *a = *b;
    *b = aux;
}

void preencher_vetores(int *pontos, int *pontos_ordenado, int *posicao, int qtd){
    int aux;
    for(int i = 0; i < qtd; i++){
        // Ex: [10,3,8,9,4] (Vetor de pontos por atleta)
        scanf("%d",&aux);
        pontos[i] = aux;
        pontos_ordenado[i] = aux;

        // Posição dos atletas no vetor
        posicao[i] = i; // [1,2,3,4,5]
    }
}

void ordenando_vetores(int *pontos_ordenado, int *posicao, int qtd){
    // Bubble Sort básico
    for(int i = 0; i < qtd - 1; i++){
        for(int j = 0; j < qtd - i - 1; j++){
            if(pontos_ordenado[j] < pontos_ordenado[j+1]){
                swap(&pontos_ordenado[j],&pontos_ordenado[j+1]);
                swap(&posicao[j],&posicao[j+1]);
            }
        }
    }
    /*
    Ex:
    Antes:
        pontos:  [10,3,8,9,4] ***
        posicao:  [0,1,2,3,4]
    Depois:
        pontos:  [10,9,8,4,3]
        posicao:  [0,3,2,3,1]

    O primeiro colocado é o atleta de índice posicao[0] no vetor de pontos (pontos[posicao[0]]) ***antes da ordenação***
    O segundo colocado é o atleta de índice posicao[1] no vetor de pontos (pontos[posicao[1]]) ***antes da ordenação***
    .
    .
    .
    */
}

void rank_atletas(int *rank, int *posicao, int qtd){
    /* Vetor 'rank' armazena colocação de cada atleta */
    
    /*
    A ordem como o vetor de pontos foi preenchido determina a ordem dos atletas
    
    O atleta 1 é aquele que possui pontos[0] ***antes da ordenação***
    O atleta 2 é aquele que possui pontos[1] ***antes da ordenação***
    .
    .
    .
    */
    
    for(int i = 0; i < qtd; i++){
        rank[posicao[i]] = i + 1;
    }
}

void imprimir_saida(int *rank, int *pontos, int qtd){
    for(int i = 0; i < qtd; i++){
        printf("%dº Atleta, %d Pontos, %dº Colocado\n",i+1,pontos[i],rank[i]);
    }  
}

int main(){
    int qtd_atletas;
    scanf("%d",&qtd_atletas);

    int pontos[qtd_atletas]; // Não será ordenado
    int pontos_ordenado[qtd_atletas]; // Será ordenado para determinar ordem dos pontos
    int posicao[qtd_atletas]; // Necessário armazenar posição dos atletas no vetor 

    // A ordem de preenchimento é essencial
    preencher_vetores(pontos,pontos_ordenado,posicao,qtd_atletas);

    // Ordem decrescente (maiores pontos primeiro)
    ordenando_vetores(pontos_ordenado,posicao,qtd_atletas);

    // Determinação da colocação dos atletas
    int rank[qtd_atletas];
    rank_atletas(rank,posicao,qtd_atletas);
    
    // Imprimindo saída no formato correto
    imprimir_saida(rank,pontos,qtd_atletas);
    
    return 0;
}