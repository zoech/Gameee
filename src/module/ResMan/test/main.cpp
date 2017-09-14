#include<stdio.h>
#include<stdlib.h>

#include"ResTypeDef.h"
#include"Resource.h"


int main(int argc, char** args){
	Resource* c = new Resource(res_type_text);
	c->path = "hello world!";
	
	Resource* i = new Resource(res_type_int);
	i->path = "hh";
	
	char* cData = (char*) c->get_data();
	int* iData = (int*) i->get_data();
	
	printf("the c data is %s\n", cData);
	for(int x = 0; x < i->data_block_num; ++x){
		printf("the i data at position %i is %i\n", x, iData[x]);
	}
}