#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(void){

    int x;
    int y;
    int soma;
    int sub;
    int mult;
    int opcao;
    int potencia;
    int div;
    int raiz;

    while(1){
        system("cls");
        printf("===================\n");
        printf("      Operacoes    \n");
        printf("1 - SOMA\n");
        printf("2 - SUBTRACAO\n");
        printf("3 - MULTIPLICACAO\n");
        printf("4 - DIVISAO\n");
        printf("5 - POTENCIA\n");
        printf("6 - RAIZ\n");
        printf("7 - SAIR\n>> ");
        scanf("%d",&opcao);

        if(opcao == 1){

            system("cls");
            printf("SOMA\n");

            printf("diga o valor de x: ");
            scanf("%d",&x);

            printf("diga o valor de y: ");
            scanf("%d",&y);


            soma = x + y;

            printf("%d + %d = %d\n",x,y,soma);
            system("pause");

        }


        if(opcao == 2){
            system("cls");
            printf("SUBTRACAO\n");

            printf("diga o valor de x: ");
            scanf("%d",&x);

            printf("diga o valor de y: ");
            scanf("%d",&y);

            sub = x - y;

            printf("%d - %d = %d\n",x,y,sub);
            system("pause");
        }

        if(opcao == 3){
            system("cls");
            printf("MULTIPLICACAO\n");

            printf("diga o valor de x: ");
            scanf("%d",&x);

            printf("diga o valor de y: ");
            scanf("%d",&y);

            mult = x * y;

            printf("%d x %d = %d\n",x,y,mult);
            system("pause");
        }

        if(opcao == 4){
            system("cls");
            printf("DIVISAO\n");

            printf("diga o valor de x: ");
            scanf("%d",&x);

            printf("diga o valor de y: ");
            scanf("%d",&y);

            div = x / y;

            printf("%d / %d = %d\n",x,y,div);
            system("pause");
        }


        if(opcao == 5){
            system("cls");
            printf("POTENCIA\n");

            printf("diga o valor de x: ");
            scanf("%d",&x);

            printf("diga o valor de y: ");
            scanf("%d",&y);

            potencia = pow(x,y);

            printf("%d ^ %d = %d\n",x,y,potencia);
            system("pause");
        }

        if(opcao == 6){
            system("cls");
            printf("ACHAR A RAIZ\n");

            printf("diga o valor de x: ");
            scanf("%d",&x);

            raiz = sqrt(x);

            printf("A raiz de %d = %d\n",x,raiz);
            system("pause");
        }


        if(opcao == 7){
            system("cls");
            printf("OBRIGADO POR USAR A CALCULADORA!!\n");
            break;
        }

    }

    return 0;
}
