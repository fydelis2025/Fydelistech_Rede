#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h> // Biblioteca necessária para a resolução de nomes (DNS)

int main(){
    int socket_desc;
    struct sockaddr_in servidor;
    struct addrinfo hints, *res;

    // 1. Configurar os critérios de busca do DNS
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;       // IPv4
    hints.ai_socktype = SOCK_STREAM; // TCP

    // 2. Resolver o domínio para obter o IP
    // Substitua pelo seu domínio ou qualquer URL (sem o http://)
    if (getaddrinfo("adielfontes.blogspot.com", "80", &hints, &res) != 0) {
        perror("Erro ao resolver o domínio (DNS)");
        return 1;
    }

    // 3. Criar o socket
    socket_desc = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
    if(socket_desc < 0){
        perror("Erro ao criar socket");
        freeaddrinfo(res); // Libera a memória da busca
        return 1;
    }

    // 4. Tentar conectar usando as informações resolvidas pelo DNS
    if(connect(socket_desc, res->ai_addr, res->ai_addrlen) < 0 ){
        perror("Não foi possível conectar");
        close(socket_desc);
        freeaddrinfo(res);
        return 1;
    }

    printf("Conexão estabelecida com sucesso usando DNS!\n");

    // Limpeza necessária
    close(socket_desc);
    freeaddrinfo(res); // Sempre liberar a memória alocada pelo getaddrinfo
    return 0;
}
