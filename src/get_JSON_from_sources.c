/*
 ============================================================================
 Name: get_JSON_from_sources.c
 Author: George Calin
 Email: george.calin@gmail.com
 Created on: Mar 11, 2022
 Description : 
 ============================================================================
 */

#include "get_JSON_from_sources.h"

char *read_from_file_to_string(char *path_to_file)
{
	static char buffer[MAXLINES];

	return buffer;
}


char *enter_JSON_from_keyboard()
{
	static char get_input[MAXLINES];

	printf("Enter what you wish to transmit: \n");
	fgets(get_input, sizeof(get_input), stdin);

	return get_input;
}
