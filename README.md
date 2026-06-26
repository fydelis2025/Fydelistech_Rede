## 🌐 Módulo de Resolução Dinâmica de DNS e Conectividade (`url.c`)

Este componente demonstra os fundamentos de engenharia de redes em ambientes POSIX, ilustrando como aplicações em C interagem com o subsistema de resolução de nomes (DNS) do sistema operacional para estabelecer conexões de rede confiáveis (TCP).

### 🧠 Como Funciona o Fluxo de Rede:
1. **Abstração de Protocolo (`getaddrinfo`):** O programa utiliza critérios de busca (`hints`) para mapear de forma segura o domínio em texto para um endereço IPv4 utilizável na porta HTTP padrão (80).
2. **Criação do Descritor de Socket:** É gerado um endpoint de comunicação (`socket_desc`) baseado no protocolo resolvido pelo DNS (TCP/IP).
3. **Handshake TCP (`connect`):** Inicia-se a conexão ativa com o servidor web alvo.

---

### 🛠️ Como Compilar e Executar o Módulo de Rede

Para compilar nativamente no Linux utilizando o compilador GCC:
```bash
gcc url.c -o modulo_rede
./modulo_rede
