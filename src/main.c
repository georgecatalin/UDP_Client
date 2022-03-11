/*
 ============================================================================
 Name        : An interpreter for JSON data files
 Author      : George Calin
 Description : The solution can be used to parse JSON data files.
 Date: 2022-03-09
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "cJSON.h"
#include "json_sample.h"
#include "udp_client.h"

int supports_full_hd(const char * monitor);

int main(int argc, char **argv)
{
	int port_number=0;
	char *host_address=NULL;


	if(argc!=3)
	{
		printf("The usage of this client is : \t >> %s  <host address>  <port> \n", argv[0]);
		exit(EXIT_FAILURE);
	}

	port_number=atoi(argv[2]);
    host_address=argv[1];

	client_listen_udp(host_address, port_number);

	return EXIT_SUCCESS;
}

