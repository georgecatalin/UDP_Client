/*
 * udp_client.c
 *
 *  Created on: Mar 9, 2022
 *  Author: George Calin
 */

#include "udp_client.h"
#include "macro_definitions.h"

int client_listen_udp(char *host_address, short unsigned port_number)
{
	int socket_file_descriptor=0;
	char buffer[MAXLINES];
	char *hello="Hello, I am the client and you are supposed to service my requests.";

	struct sockaddr_in server_address;
	struct sockaddr_in client_address;

	//initialize the structures just declared
	memset(&server_address,0, sizeof(server_address));
	memset(&client_address,0, sizeof(client_address));

	//Set the server information
	server_address.sin_family=AF_INET;
	server_address.sin_addr.s_addr=inet_addr(host_address);
	server_address.sin_port=htons(port_number);

	//Create the socket file descriptor
    socket_file_descriptor=socket(AF_INET,SOCK_DGRAM,0);

    if(socket_file_descriptor<0)
    {
    	perror("Socket creation failed");
    	exit(EXIT_FAILURE);
    }

    //Send the message to the UDP Server. Server will recognize the address of the client from the datagram
    sendto(socket_file_descriptor, hello, strlen(hello), MSG_CONFIRM, (struct sockaddr *) &server_address, sizeof(server_address));

#if DEBUG_LEVEL >=1
    puts("I have sent the hello message to the server");
#endif

    //Receive the message from the UDP Server
    int number_of_bytes=0;
    int length_of_server_address=sizeof(server_address);

    number_of_bytes=recvfrom(socket_file_descriptor,  buffer, MAXLINES,MSG_WAITALL, (struct sockaddr *)  &server_address, &length_of_server_address);

    //TODO Add handling for the escape characters onto quotation marks
    int j=0;


    while(buffer[j])
    {
    	if(buffer[j]=='"')
    	{
    		buffer[j]='\\';
    		buffer[j+1]='"';
    		j+=2;
    	}
    	j+=1;
    }

    buffer[j]='\0';

#if DEBUG_LEVEL >=1
    printf("Server responded >> \t %s.\n", buffer);
#endif

    //Close the file descriptor
    close(socket_file_descriptor);

	return EXIT_SUCCESS;
}
