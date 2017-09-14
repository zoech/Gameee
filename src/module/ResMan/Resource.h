/* created by zoey */
#include<stdio.h>

#ifndef GAMEEE_RESOURCE_H
#define GAMEEE_RESOURCE_H

class Resource;
struct t_res;
typedef struct t_res t_res;

typedef struct t_res {
	char*	type_name;
	void	(*load)(Resource*);
	void	(*free_data)(Resource*);
} t_res;

class Resource {
public:
	const t_res*	res_type;
	char*	path;
	void*	data;

	Resource(const t_res*);
	~Resource();

	void	set_res_path(char*);
	//void	set_res_type(t_res*);
	void*	get_data();

protected:

private:
};

#endif
