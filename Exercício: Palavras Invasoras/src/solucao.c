#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void toString(char **buffer, int qtd_chr){
    // Transformando um buffer de chars em uma string

    // Alocando mais um char para adição do '\0'
    *buffer = realloc(*buffer,(qtd_chr + 1) * sizeof(char));

    // Adição do '\0' que torna um vetor de chars em string
    (*buffer)[qtd_chr] = '\0';
}

void addStringToText(char **texto, char *buffer, int *qtd_chrBuffer, int *qtd_chrTexto){
    /* Realocando o tamanho do texto para o tamanho do texto anterior + tamanho 
    da nova palavra */
    (*texto) = realloc( (*texto) , ( (*qtd_chrBuffer) + (*qtd_chrTexto) ) * sizeof(char));
    
    // Copiando a palavra para o final do texto
    memcpy(&( (*texto)[*qtd_chrTexto] ), buffer, *qtd_chrBuffer);
    
    // Atualizando a quantidade de caracteres do texto
    *qtd_chrTexto += *qtd_chrBuffer;

}

int main(){

    /* Nesse exercício será necessário 2 ponteiros para chars, um buffer que 
    armazenará as palavras conforme o usuário for digitando (a cada palavra nova,
    o buffer reseta), e outro que representará o texto por completo, onde as palavras 
    do buffer serão armazenadas */

    char *buffer = NULL, *texto = NULL;

    // Armazenar a quantidade de chars de cada vetor de chars será essencial
    int qtd_chrBuffer = 0, qtd_chrTexto = 0;

    // Contador da quantidade de palavras invasoras encontradas
    int qtd_NonGrata = 0;

    // Usuário deve informar a palavra invasora
    char tabu[21]; // Nunca terá mais do que 20 caracteres
    scanf("%s ",tabu); // Ignorando espaços em branco após leitura (essencial)

    /* Loop de leitura do input do usuário */
    char c;
    c = getchar();
    while( c != EOF){
        // Lendo char a char, alocando espaço e armazenando no buffer
        buffer = realloc(buffer,(++qtd_chrBuffer) * sizeof(char));
        buffer[qtd_chrBuffer-1] = c;
        c = getchar(); 

        // Caso seja ' ', '\n', ou EOF, então completou uma palavra
        if(c == ' ' || c == '\n' || c == EOF){
            // Converte o buffer para uma string para posterior comparação com a palavra invasora 
            toString(&buffer,qtd_chrBuffer);

            // Se a palavra do buffer for diferente da palavra invasora, adiciona no texto
            if(strcasecmp(buffer,tabu) != 0){ // 'strcasecmp' compara strings de forma case-insensitive 

                addStringToText(&texto,buffer,&qtd_chrBuffer,&qtd_chrTexto);

                /* Adicionando o próximo caracter imediamente depois da palavra 
                ao texto, podendo ser ' ', '\n' ou EOF */                
                texto = realloc(texto,(++qtd_chrTexto)*sizeof(char));
                texto[qtd_chrTexto-1] = c;
            }
            else{
                // Caso a palavra seja igual à palavra invasora, incrementa contador
                qtd_NonGrata++;
            }

            // Resetando o buffer para a leitura da próxima palavra
            qtd_chrBuffer = 0;
            free(buffer);
            buffer = NULL;

            /* Visto que é adicionado o caracter imediatamente após a palavra 
            manualmente, deve-se ler o próximo caracter do usuário para que o 
            mesmo caracter não seja adicionado duas vezes */
            c = getchar(); 
        }
    }
    // Tornando o texto em string imprimível
    texto[qtd_chrTexto-1] = '\0';

    // Imprimindo sainda de forma desejada
    printf("[Palavras invasoras: %d]\n\n",qtd_NonGrata);
    printf("%s",texto);

    // Desalocando memória alocada
    free(texto);

    return EXIT_SUCCESS;
}