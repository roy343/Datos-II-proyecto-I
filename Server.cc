#include <unistd.h> 
#include <stdio.h> 
#include <sys/socket.h> 
#include <stdlib.h> 
#include <netinet/in.h> 
#include <string.h> 
#define PORT 8080 

int main(int argc, char const *argv[]){
    int server, new_socket, valueR;
    struct sockaddr_in address;
    int opt = 1;
    int lenghtaddr = sizeof(address);
    char buffer[1024] = {0};
    char *hello = "hola cliente";


    //Socket file descriptor
    if((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0){
        perror("fallo del socket");
        exit(EXIT_FAILURE);
    }
    //Asigna el socket al puerto 8080
    if(setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))){
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    if(bind(server_fd, (struct sockaddr *)&address, sizeof(address))< 0){
        perror("bind fallido");
        exit(EXIT_FAILURE);
    }
    if(listen(server_fd, 3) < 0){
        perror("escucha");
        exit(EXIT_FAILURE);
    }
    if((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0){
        perror("acepta");
        exit(EXIT_FAILURE);
    }
    valueR = read(new_socket, buffer, 1024);
    printf("%s\n",buffer);
    send(new_socket, hello, strlen(hola), 0);
    printf("Mensaje de saludo enviado\n");
    return 0;
}