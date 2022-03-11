/*
 ============================================================================
 Name: play_with_JSON.c
 Author: George Calin
 Email: george.calin@gmail.com
 Created on: Mar 11, 2022
 Description : 
 ============================================================================
 */

#include "play_with_JSON.h"

int supports_full_hd( char * monitor)
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

void do_stuff()
{
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
}
