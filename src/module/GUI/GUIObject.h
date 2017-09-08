#ifndef GAMEEE_GUIOBJECT_H
#define GAMEEE_GUIOBJECT_H

#include<interface/RendererInt.h>

class GUIObject;
typedef struct _RenderTarget {
	GUIObject*	pCanvas;
	EE_Rect*	pSrcRect;
	EE_Rect*	pDstRect;
} RenderTarget


class GUIObject {
public:
	EE_Texture* pCanvas;
	EE_Texture** imgs;
	int img_num;
	int cur_img_index;

	EE_Renderer* pRenderer;
	RenderTarget* pRenderTarget;

	GUIObject();
	GUIObject(int imgNum);
	~GUIObject();
	int render();

	//void addImg(char* file);
	void setImg(int index, const char* file);
	void setCurImgIndex(int index);
	void imgNext();
	void setRenderer(EE_Renderer* pRenderer);
	void setRenderTarget(RenderTarget* pTarget);

protected:

privte:
};

#endif
