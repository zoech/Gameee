#include"GUIObject.h"
#include<interface/RendererInt.h>

GUIObject::GUIObject(){
	this->imgs = new EE_Texture*[1];
	this->img_num = 1;
	this->cur_img_index = 0;

	pRenderer = NULL;
	pRenderTarget = NULL;
}

GUIObject::GUIObject(int imgNum){
	this->img_num = imgNum;
	this->imgs = new EE_Texture*[this->img_num];
	this->cur_img_index = 0;

	pRenderer = NULL;
	pRenderTarget = NULL;
}

GUIObject::~GUIObject(){
	for(int i = 0; i < this->img_num; ++i){
		if( (this->imgs)[i] ) {
			delete (this->imgs)[i];
		}
	}
	delete [] imgs;
	
	if( this->pRenderTarget ){
		if( this->pRenderTarget->pSrcRect ){
			delete this->pRenderTarget->pSrcRect;
		}
		if( this->pRenderTarget->pDstRect ){
			delete this->pRenderTarget->pDstRect;
		}

		delete this->pRenderTarget;
	}
}

int GUIObject::render(){
	if (!this->pRenderer){
		DebugLog("GUIObject render error, the renderer is not set yet!");
		return -1;
	}

	if (!this->pRenderTarget || !this->pRenderTarget->pCanvas || !this->pRenderTarget->pCanvas->
}

void GUIObject::setImg(int index, const char* file){
	if(index >= this->img_num){ 
		DebugLog("the \"index\" is out of GUIObject's img_num!");
		return; 
	}

	if(this->pRenderer == NULL) {
		DebugLog("this GUIObject has not set proper renderer yet!");
		return;
	}
	
	EE_Texture* pTexTmp = (this->imgs)[index];

	(this->imgs)[index] = EE_CreateTextureFromFile(this->pRenderer, file);

	if(!((this->imgs)[index]) && pTexTmp){
		(this->imgs)[index] = pTexTmp;
	}
	
}

void GUIObject::setCurImgIndex(int index){
	if( index >= this->img_num ){ index = 0; }

	this->cur_img_index = index;
}

void GUIObject::imgNext(){
	++(this->cur_img_index);
	if( this->cur_img_index >= this->img_num ){
		this->cur_img_index = 0;
	}
}

void GUIObject::setRenderer(EE_Renderer* pRenderer){
	this->pRenderer = pRenderer;
}

void GUIObject::setRenderTarget(RenderTarget* pTarget){
	this->pRenderTarget = pTarget;
}
