/*
 ============================================================================
 Name: get_JSON_from_sources.h
 Author: George Calin
 Email: george.calin@gmail.com
 Created on: Mar 11, 2022
 Description : 
 ============================================================================
 */
#ifndef SRC_GET_JSON_FROM_SOURCES_H_
#define SRC_GET_JSON_FROM_SOURCES_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <errno.h>
#include <string.h>
#include "macro_definitions.h"

char *read_from_file_to_string(char *path_to_file);
char *enter_JSON_from_keyboard();

#endif /* SRC_GET_JSON_FROM_SOURCES_H_ */
