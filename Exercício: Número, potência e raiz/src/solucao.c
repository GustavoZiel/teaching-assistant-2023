#include <stdio.h>
#include <math.h>

int main(){

    int num;
    scanf("%d",&num);

    double pot = pow(num,10),square_root = sqrt(num);

    printf("Numero:%3d\n%17.2e\n%13.2lf\n",num,pot,square_root);

    return 0;
}