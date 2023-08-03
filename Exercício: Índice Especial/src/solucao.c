#include <stdio.h>

void preencher_vetor(int *vet, int qtd_num){
    for(int i = 0; i < qtd_num; i++){
        scanf("%d",&vet[i]);
    }
}

int soma_vetor(int *vet, int qtd_num){
    int soma = 0;
    for(int i=0; i < qtd_num; i++){
        soma += vet[i];
    }
    return soma;
}

int indice_especial(int *vet, int qtd_num, int soma){
    /*
    Ex: 
        [1,3,7,6,5,6]
        
        índice 0:
            soma_esq = 0  (começa como 0)
            soma_dir = 28 (soma de todos os elementos do vetor)

            soma_dir = soma_dir - vet[i] (O elemento no índice em análise não é contado para nenhuma das somas)
            soma_dir = 27

            soma_dir(27) == soma_esq(0) (F)

            soma_esq = soma_esq + vet[i] (Soma esquerda recebe o elemento do índice analisado e o índice é incrementado)
            soma_esq = 1

        indice 1:
            soma_esq = 1
            soma_dir = 27 (soma de todos os elementos do vetor)

            soma_dir = soma_dir - vet[i] (O elemento no índice em análise não é contado para nenhuma das somas)
            soma_dir = 24

            soma_dir(24) == soma_esq(1) (F)

            soma_esq = soma_esq + vet[i] (Soma esquerda recebe o elemento do índice analisado e o índice é incrementado)
            soma_esq = 4
    */
    
    int soma_esq = 0, soma_dir = soma;

    for(int i = 0; i < qtd_num; i++){
        soma_dir -= vet[i];
        if(soma_esq == soma_dir){ // Achou o índice
            return i;
        }
        soma_esq += vet[i];
    }

    // Não achou
    return -1;
}

int main(){

    int qtd_num;
    scanf("%d", &qtd_num);

    int vet[qtd_num];
    preencher_vetor(vet,qtd_num);
    
    int soma;
    soma = soma_vetor(vet,qtd_num);

    int indice;
    indice = indice_especial(vet,qtd_num,soma);

    printf("%d\n",indice);

    return 0;
}