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

struct Votes* add_new_user(struct Votes* users_votes, int qtd_votes) {
    int new_num_votes = qtd_votes; // Você pode definir o tamanho que desejar aqui

    struct Votes* temp = (struct Votes*)realloc(users_votes, new_num_votes * sizeof(struct Votes));
    if (temp == NULL) {
        perror("Erro na realocação de memória.\n");
        free(users_votes); // Libera a memória previamente alocada
        exit(EXIT_FAILURE);
    }
    users_votes = temp;

    return users_votes;
}

struct Votes* add_vote(struct Votes* user_vote, int qtd_votes, int cpf, int major, int deputado, int prefeito){

    for (size_t i = 0; i < qtd_votes; i++) {
        user_vote[i].cpf = cpf;
        user_vote[i].user_major_vote = major;
        user_vote[i].user_deputado_vote = deputado;
        user_vote[i].user_prefeito_vote = prefeito;
    }

}

int qtd_user_votes = 0;


int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_addr_len = sizeof(client_addr);

    struct Votes* user_votes_init = init_list();
    
    
    // Criação do socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("Erro ao criar socket do servidor");
        exit(EXIT_FAILURE);
    }
    
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(1234);  // Porta de comunicação
    
    // Associação do socket com o endereço
    if (bind(server_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        perror("Erro ao associar socket ao endereço");
        exit(EXIT_FAILURE);
    }
    
    // Habilitar o servidor para receber conexões
    if (listen(server_socket, 5) == -1) {
        perror("Erro ao habilitar o servidor para receber conexões");
        exit(EXIT_FAILURE);
    }
    
    printf("Servidor aguardando conexões...\n");
    
    // Aguardar conexões
    client_socket = accept(server_socket, (struct sockaddr*)&client_addr, &client_addr_len);
    if (client_socket == -1) {
        perror("Erro ao aceitar conexão do cliente");
        exit(EXIT_FAILURE);
    }
    
    printf("Cliente conectado\n");
    
    // Trocar dados com o cliente
    
    while (1) {
        char buffer[1024];
        qtd_user_votes++;
        user_votes_init = add_new_user(user_votes_init, qtd_user_votes); // Atualize o ponteiro aqui

        memset(buffer, 0, sizeof(buffer));
        ssize_t bytes_received = recv(client_socket, buffer, sizeof(buffer), 0);
        if (bytes_received == -1) {
            perror("Erro ao receber dados do cliente");
            exit(EXIT_FAILURE);
        } else if (bytes_received == 0) {
            printf("Cliente desconectado\n");
            break;
        } else {
            printf("\nCliente: %s", buffer);
            for (size_t i = 0; i < 100; i++)
            {
                printf("\nbuffer = %c", buffer[i]);
            }
        }

        
        
    }

    // Fechar os sockets
    close(client_socket);
    close(server_socket);
    
    return 0;
}
