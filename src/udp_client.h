/*
 * udp_client.h
 *
 *  Created on: Mar 9, 2022
 *  Author: George Calin
 */

#ifndef UDP_CLIENT_H_
#define UDP_CLIENT_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include "macro_definitions.h"
#include "get_JSON_from_sources.h"

int client_listen_udp(char *host_address, short unsigned port_number);
char *get_user_input();

#endif /* UDP_CLIENT_H_ */

