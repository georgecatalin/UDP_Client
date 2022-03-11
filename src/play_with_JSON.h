/*
 ============================================================================
 Name: play_with_JSON.h
 Author: George Calin
 Email: george.calin@gmail.com
 Created on: Mar 11, 2022
 Description : 
 ============================================================================
 */
#ifndef SRC_PLAY_WITH_JSON_H_
#define SRC_PLAY_WITH_JSON_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <errno.h>
#include "macro_definitions.h"
#include "cJSON.h"
#include "json_sample.h"

int supports_full_hd(char * monitor);

void do_stuff();

#endif /* SRC_PLAY_WITH_JSON_H_ */
