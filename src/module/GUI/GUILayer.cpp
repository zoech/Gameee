#include"GUILayer.h"

GUILayer::GUILayer(){
	pCanvas = NULL;
	pSrcRect = NULL;
	pDstRect = NULL;
	pRenderer = NULL;
}

GUILayer::GUILayer(EE_Renderer* pRenderer){
	this->pRenderer = pRenderer;
	pCanvas = NULL;
	pSrcRect = NULL;
	pDstRect = NULL;
}

GUILayer::~GUILayer(){

}
