#ifndef GAMEEE_RESTYPEDEF_H
#define GAMEEE_RESTYPEDEF_H

#include"Resource.h"
#include<string.h>
#include<stdio.h>

/* define the used resource type as short form for easy use */
#define res_type_text (t_res_array)
#define res_type_int (t_res_array + 1)

/* load function for required resource type */
void	load_text(Resource* res);
void free_text_data(Resource* res);

void	load_int(Resource* res);

/* global resource type struct array */
const t_res t_res_array[] = {
	t_res{"text", load_text, free_text_data},
	t_res{"int", load_int, free_text_data}
};


void load_text(Resource* res){
	if(res->path == NULL)
		return;
	
	char* tmp = new char[20];
	strcpy(tmp, res->path);
	
	res->data = tmp;
	res->data_block_num = 20;
}

void free_text_data(Resource* res){
	delete [] (res->data);
}

void load_int(Resource* res){
	if(res->path == NULL)
		return;
	
	int* tmp = new int[10];
	for(int i = 0; i < 10; ++i){
		tmp[i] = i;
	}
	
	res->data = tmp;
	res->data_block_num = 10;
}


#endif
