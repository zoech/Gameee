#ifndef GAMEEE_GUILAYER_H
#define GAMEEE_GUILAYER_H

#include<interface/RendererInt.h>

class GUILayer {
public:
	EE_Texture* pCanvas;
	EE_Rect *pSrcRect;
	EE_Rect *pDstRect;

	EE_Renderer* pRenderer;

	GUILayer();
	GUILayer(EE_Renderer* pRenderer);
	~GUILayer();

	render();

protected:

private:
}

#endif
