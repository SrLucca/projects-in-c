#include <stdio.h>

struct Votes
{
    int cpf;
    int user_major_vote;
    int user_deputado_vote;
    int user_prefeito_vote;
};



int main(){

    int major_vote;
    int deputado_vote;
    int prefeito_vote;
    int cpf;
    int i = 0;

    struct Votes users_votes[3];
    

    while (i < 3)
    {
        printf("============ VOTING SYSTEM ============\n");

        printf("Seu CPF:");
        scanf("%d", &users_votes[i].cpf);
        fflush(stdin);

        printf("Candidato para presidente:");
        scanf("%d", &users_votes[i].user_major_vote);
        fflush(stdin);
        
        printf("\nCandidato para deputado:");
        scanf("%d", &users_votes[i].user_deputado_vote);
        fflush(stdin);
        
        printf("\nCandidato para prefeito:");
        scanf("%d", &users_votes[i].user_prefeito_vote);
        fflush(stdin);

        i++;
    }

    printf("Resultados:\n");
    for (size_t i = 0; i < 3; i++)
    {
        printf("CPF: %d\nVoto Presidente: %d\nVoto Deputado: %d\nVoto prefeito: %d\n",users_votes[i].cpf, users_votes[i].user_major_vote, users_votes[i].user_deputado_vote, users_votes[i].user_prefeito_vote);
    }
    
    

    return 0;
}