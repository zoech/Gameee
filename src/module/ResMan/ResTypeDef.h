#ifndef GAMEEE_RESTYPEDEF_H
#define GAMEEE_RESTYPEDEF_H

#include"Resource.h"
#include<string.h>
#include<stdio.h>


#include<interface/RendererInt.h>
#include<Service/Service.h>

/* define the used resource type as short form for easy use */
#define res_type_texture (t_res_array)

/* load function for required resource type */
void	load_tex(Resource* res);
void free_tex_data(Resource* res);

/* global resource type struct array */
const t_res t_res_array[] = {
	t_res{"texture", load_tex, free_tex_data}
};


void load_tex(Resource* res){
	if(res->path == NULL)
		return;
	
	res->data = sv_load_tex(res->path);
}

void free_tex_data(Resource* res){
	EE_DestroyTexture((EE_Texture*)(res->data));
}

#endif
