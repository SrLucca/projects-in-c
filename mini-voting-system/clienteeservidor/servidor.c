#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_addr_len = sizeof(client_addr);
    
    // Criação do socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("Erro ao criar socket do servidor");
        exit(EXIT_FAILURE);
    }
    
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(12345);  // Porta de comunicação
    
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
    char buffer[1024];
    while (1) {
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
        }
    }
    
    // Fechar os sockets
    close(client_socket);
    close(server_socket);
    
    return 0;
}
