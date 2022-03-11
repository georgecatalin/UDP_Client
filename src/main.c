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

	/* -----------------------------------------------------------------------------------------------------------
	 *  Playing with the json library
	/*
	//How to parse a JSON String
	cJSON *json=cJSON_Parse(sample);

	//How to print the JSON File
	char *this_string=cJSON_Print(json);

	printf("%s.\n",this_string);


	//How to free the allocated memory to handle the json object
	cJSON_Delete(json);

	if(supports_full_hd(sample))
		{
		puts("Indeed, it is a HD monitor.");
		}
		* ----------------------------------------------------------------------------------------------------------------- */

	return EXIT_SUCCESS;
}

int supports_full_hd(const char * monitor)
{
	cJSON *resolution=NULL;
	cJSON *resolutions=NULL;
	cJSON *name=NULL;

	int status=0;

	cJSON *monitor_json=cJSON_Parse(monitor);

	if(monitor_json==NULL)
	{
		char *error_pointer=cJSON_GetErrorPtr();
		if(error_pointer!=NULL)
		{
			fprintf(stderr,"Error before: %s \n", error_pointer);
		}
		status=0;
		goto end;
	}

	name=cJSON_GetObjectItemCaseSensitive(monitor_json, "name");

	if(cJSON_IsString(name) && (name->valuestring !=NULL))
	{
		printf("The monitor brand is \t \" %s \" \n", name->valuestring);
	}

   resolutions=cJSON_GetObjectItemCaseSensitive(monitor_json, "resolutions");

   cJSON_ArrayForEach(resolution,resolutions)
   {
	   cJSON *width=cJSON_GetObjectItemCaseSensitive(resolution, "width");
	   cJSON *height=cJSON_GetObjectItemCaseSensitive(resolution, "height");

	   if(!cJSON_IsNumber(width) || !cJSON_IsNumber(height))
	   {
		   status=0;
		   puts("One of the values for width and height are not numbers.");
		   goto end;
	   }

	   if(width->valuedouble==1920 && height->valuedouble==1080)
	   {
		   status=1;
		   goto end;
	   }


   }


	end:
	cJSON_Delete(monitor_json);
	return status;

}
