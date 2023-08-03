#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Função que recebe uma palvra, e uma lista de letras
// Verifica se palavra contém apenas as letras da lista
bool is_inRow(char *word, char *letters){
    for(int i = 0; word[i] != '\0'; i++){
        // Tratando caso de letra maiuscula
        if(word[i] < 97){
            if(strchr(letters,(word[i]+32)) == NULL){
                return false;
            }
        }
        // 'strchr()' dado uma string e char, se char não estiver na string, return NULL
        else if (strchr(letters,word[i]) == NULL){
            return false;
        }
    }
    return true;
}

int main(){

    // Input, máximo 100 letras
    char input[101];
    
    // Sequência de letras dadas
    char first_row[] = "qwertyuiop";
    char second_row[] = "asdfghjkl";
    char third_row[] = "zxcvbnm";
    
    while((scanf("%s",input) != EOF)){ // Enquando usuário não digitar EOF
        if(is_inRow(input, first_row) || is_inRow(input, second_row) || is_inRow(input, third_row)){
            printf("%s\n",input);
        }
    }

    return EXIT_SUCCESS;
}