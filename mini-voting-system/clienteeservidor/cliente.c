#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

struct Votes {
    int cpf;
    int user_major_vote;
    int user_deputado_vote;
    int user_prefeito_vote;
};

struct Votes* init_list() {
    struct Votes* users_votes = NULL;
    users_votes = (struct Votes*)malloc(sizeof(struct Votes));
    if (users_votes == NULL) {
        perror("Erro na alocação de memória.\n");
        exit(EXIT_FAILURE);
    }
    return users_votes;
}

struct Votes* new_user(struct Votes* users_votes) {
    int new_num_votes = 2; // Você pode definir o tamanho que desejar aqui

    struct Votes* temp = (struct Votes*)realloc(users_votes, new_num_votes * sizeof(struct Votes));
    if (temp == NULL) {
        perror("Erro na realocação de memória.\n");
        free(users_votes); // Libera a memória previamente alocada
        exit(EXIT_FAILURE);
    }
    users_votes = temp;

    return users_votes;
}

struct Votes* vote_func(struct Votes* users_votes, int qtd_user_votes) {
    int i = qtd_user_votes;

    printf("============ VOTING SYSTEM ============\n");

    printf("Seu CPF:");
    scanf("%d", &users_votes[i].cpf);

    printf("Candidato para presidente:");
    scanf("%d", &users_votes[i].user_major_vote);

    printf("\nCandidato para deputado:");
    scanf("%d", &users_votes[i].user_deputado_vote);

    printf("\nCandidato para prefeito:");
    scanf("%d", &users_votes[i].user_prefeito_vote);

    return users_votes;
}

int main() {
    int client_socket;
    struct sockaddr_in server_addr;

    // Criação do socket
    client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket == -1) {
        perror("Erro ao criar socket do cliente");
        exit(EXIT_FAILURE);
    }
    
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");  // Endereço IP do servidor
    server_addr.sin_port = htons(12345);  // Porta de comunicação
    
    // Conectar ao servidor
    if (connect(client_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        perror("Erro ao conectar ao servidor");
        exit(EXIT_FAILURE);
    }
    
    printf("Conectado ao servidor\n");
    

    printf("Conectado ao servidor\n");

    // Trocar dados com o servidor
    char message[256]; // Defina o tamanho apropriado
    struct Votes* user_votes = init_list();
    int qtd_user_votes = 0;
    
    while (1) {
        struct Votes* user_votes_realloc = new_user(user_votes);
        struct Votes* current_user_vote = vote_func(user_votes_realloc, qtd_user_votes);

        // Usar sprintf para criar a mensagem formatada
        sprintf(message, "CPF: %d | Presidente: %d | Deputado: %d | Prefeito: %d",
                current_user_vote[qtd_user_votes].cpf, current_user_vote[qtd_user_votes].user_major_vote,
                current_user_vote[qtd_user_votes].user_deputado_vote, current_user_vote[qtd_user_votes].user_prefeito_vote);

        printf("%s\n", message);

        // Enviar a mensagem
        send(client_socket, message, strlen(message), 0);

        qtd_user_votes++;
    }

    // Fechar o socket
    close(client_socket);

    // Liberar a memória alocada
    free(user_votes);

    return 0;
}

