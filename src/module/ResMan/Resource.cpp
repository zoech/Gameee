/* created by zoey */

#include"Resource.h"

Resource::Resource(const char* res_id, const t_res* pT){
	this->id = res_id;
	this->res_type = pT;
	this->data_block_num = 0;
	this->path = NULL;
	this->data = NULL;
}

Resource::~Resource(){
	if(this->path != NULL)
		delete [] (this->path);

	if(this->data != NULL)
		this->res_type->free_data(this);
}

void Resource::set_res_path(char* p){
	/* if the resource is already set, then release the old path */
	if(this->path != NULL)
		delete [] (this->path);

	this->path = p;

	/* if the resource is already set, then reload the data */
	if(this->data != NULL){
		this->res_type->free_data(this);
		this->res_type->load(this);
	}
}

void* Resource::get_data(){
	if(this->data == NULL)
		this->res_type->load(this);
	return this->data;
}

/*
void Resource::set_res_type(t_res* t){
	if(this->res_type != NULL)
		return;
	this->res_type = t;
}
*/

