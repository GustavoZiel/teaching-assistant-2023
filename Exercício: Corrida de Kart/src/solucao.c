#include <stdio.h>

int main(){

    int qtd_corridas;
    scanf("%d",&qtd_corridas);

    float velocidade_A, velocidade_B, distancia_A, distancia_B;
    int tempo_decorrido;

    while(qtd_corridas > 0){
        scanf("%f %f %d", &velocidade_A, &velocidade_B, &tempo_decorrido);

        distancia_A = velocidade_A * tempo_decorrido;
        distancia_B = velocidade_B * tempo_decorrido;
        
        if(tempo_decorrido == 0){
            printf("A corrida ainda nao comecou\n");
        }
        else if(velocidade_A == 0 && velocidade_B == 0){
            printf("Os dois pilotos nao querem competir\n");
        }
        else if(velocidade_A != 0 && velocidade_B == 0){
            printf("O piloto B desistiu inesperadamente\n");
        }
        else if(velocidade_A == 0 && velocidade_B != 0){
            printf("O piloto A desistiu inesperadamente\n");
        }
        else if(tempo_decorrido < 0){
            printf("De alguma forma os pilotos voltaram no tempo\n");
        }
        else if(distancia_A > distancia_B){
            printf("O kart A venceu e percorreu %.2fkm a mais que o kart B\n", distancia_A - distancia_B);
        }
        else if (distancia_B > distancia_A){
            printf("O kart B venceu e percorreu %.2fkm a mais que o kart A\n", distancia_B - distancia_A);
        }   
        else{
            printf("Os karts empataram, percorrendo cada %.2fkm\n", distancia_A);
        }
        qtd_corridas--;
    }

    return 0;
}