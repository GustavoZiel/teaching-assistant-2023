#include <stdio.h>

/* BIBLIOTECA MATH.H NÃO DEVE SER USADA */

double my_pow(double base, double power){
    double aux = 1;
    while(power > 0){
        aux = aux * base;
        power--;
    }
    return aux;
}
double fatorial(double num){
    double result = 1;
    while(num > 1){
        result = result * num;
        num--;
    }
    return result;
}

int main(){

    // TESTES DAS FUNÇÕES DE POTÊNCIA/FATORIAL
    // printf("%lf\n",my_pow(2,3));
    // printf("%lf\n",my_pow(3,3));
    // printf("%lf\n",my_pow(3,2));
    // printf("%lf\n",my_pow(5,2));
    
    // printf("%lf\n",my_pow(5,1));
    // printf("%lf\n",fatorial(2));

    // printf("%lf\n",fatorial(4));
    // printf("%lf\n",fatorial(3));
    // printf("%lf\n",fatorial(5));
    // printf("%lf\n",fatorial(2));

    double num;
    scanf("%lf",&num);

    /*
    Interessante raciocinar aqui sobre o tipo dos dados, por que double e
    não float ? Por que alguns podem ser inteiros ?
    https://learn.microsoft.com/en-us/cpp/c-language/storage-of-basic-types?view=msvc-170
    */

    double res_potencia, res_fatorial, resultado = 0;
    int potencia = 1, denominador = 1, aux_potencia, aux_fatorial, sinal = 0;
    for(int i = 0; i < 50; i++){

        // Calcular a potência
        res_potencia = 1;
        aux_potencia = potencia;
        while(aux_potencia > 0){
            res_potencia = res_potencia * num;
            aux_potencia--;
        }
        potencia += 2;
        
        // Calcular o fatorial
        res_fatorial = 1;
        aux_fatorial = denominador;
        while(aux_fatorial > 1){
            res_fatorial = res_fatorial * aux_fatorial;
            aux_fatorial--;
        }
        denominador += 2;

        // Realizar a soma/subtração de cada termo no resultado final
        if(sinal == 0){    
            resultado += res_potencia/res_fatorial;
            sinal++;
        }
        else if(sinal == 1){
            resultado -= res_potencia/res_fatorial;
            sinal--;
        }
    }

    printf("%.6f\n",resultado);

    return 0;
}