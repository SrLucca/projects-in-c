#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>


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
    server_addr.sin_port = htons(1234);  // Porta de comunicação
    
    // Conectar ao servidor
    if (connect(client_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        perror("Erro ao conectar ao servidor");
        exit(EXIT_FAILURE);
    }
    
    printf("Conectado ao servidor\n");

    // Trocar dados com o servidor
    char message[256]; // Defina o tamanho apropriado
    int qtd_user_votes = 0;
    
    while (1) {
        int user_major_vote;
        int cpf;
        int user_deputado_vote;
        int user_prefeito_vote;

        printf("\n============ VOTING SYSTEM ============\n");

        printf("Seu CPF:");
        scanf("%d", &cpf);
        fflush(stdin);

        printf("Candidato para presidente:");
        scanf("%d", &user_major_vote);
        fflush(stdin);

        printf("\nCandidato para deputado:");
        scanf("%d", &user_deputado_vote);
        fflush(stdin);

        printf("\nCandidato para prefeito:");
        scanf("%d", &user_prefeito_vote);
        fflush(stdin);
        // Usar sprintf para criar a mensagem formatada
        sprintf(message, "CPF:%d | Presidente:%d | Deputado:%d | Prefeito:%d", cpf, user_major_vote, user_deputado_vote, user_prefeito_vote);            
        printf("%s\n", message);
        

        // Enviar a mensagem
        send(client_socket, message, strlen(message), 0);
    }

    // Fechar o socket
    close(client_socket);

    return 0;
}

