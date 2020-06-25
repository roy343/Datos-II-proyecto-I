#include <stdio.h> //includes necesarios
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <unistd.h> 
#include <string.h> 
#define PORT 8080 
int main(int argc, char const *argv[]) 
{ 
    int sock = 0, valread; // Creacion de los enteros para la funcionalidad del socket
    struct sockaddr_in serv_addr; 
    char *hello = "Conexion exitosa"; //mensaje de comprobacion de conexion
    char buffer[1024] = {0}; // buffer
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) //If para la comprobacion de errores en la creacion
    { 
        printf("\n Socket creation error \n"); 
        return -1; 
    } 
   
    serv_addr.sin_family = AF_INET; //Familia y puerto
    serv_addr.sin_port = htons(PORT); 
       
    // Convierte IPv4 e IPv6 (Direcciones) de texto a binario
    if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0)  
    { 
        printf("\nInvalid address/ Address not supported \n"); 
        return -1; 
    } 
   
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) //Mensaje de error en caso de fallo de conexion
    { 
        printf("\nConnection Failed \n"); 
        return -1; 
    } 
    send(sock , hello , strlen(hello) , 0 ); //Envia el mensaje
    printf("Conexion encontrada con server\n"); //Avisa sobre una conexion encontrada
    valread = read( sock , buffer, 1024); 
    printf("%s\n",buffer ); 
    return 0; 
} 