#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <time.h>

int main(void){
    while(1){

        int opcao;
        char tarefa[128];
        int contador;
        char texto_str[61];
        FILE *pont_arq;

        contador = 0;
        system("cls");
        printf("===================");
        printf("LISTA DE AFAZERES\n");
        printf("1 - ADICIONAR TAREFA\n");
        printf("2 - EXCLUIR TAREFA\n");
        printf("3 - VER TODAS AS TAREFAS\n");
        printf("4 - SAIR\n>> ");
        scanf("%d",&opcao);

        if(opcao == 1){
                while(1){
                    system("cls");
                    printf("ADICIONAR TAREFA\n");
                    printf("===================\n");
                    printf("Escreva a tarefa abaixo ou para sair digite 1\n>> ");
                    gets(tarefa);

                    int sair = atoi(tarefa);
                    if(sair == 1){

                        break;
                    }else{
                        pont_arq = fopen("LISTA-DE-AFAZERES.txt","a");
                        fprintf(pont_arq,"%s\n",tarefa);
                        fclose(pont_arq);
                        printf("\n'%s' Registrada com Sucesso!!\n",tarefa);
                        system("pause");

                    }

                }

        }

        if(opcao == 3){
            system("cls");
                printf("EXIBIR TAREFAS\n");
                printf("===================\n");
                pont_arq = fopen("LISTA-DE-AFAZERES.txt","r");
                while(fgets(texto_str, 128, pont_arq) != NULL)
                    printf("%d - %s\n", contador+=1,texto_str);
                system("pause");
                fclose(pont_arq);
        }


        if(opcao == 4){
            system("cls");
            printf("Ate Logo!");
            break;
        }
    }


    return 0;
}
