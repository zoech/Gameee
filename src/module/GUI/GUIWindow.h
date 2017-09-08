#ifndef GAMEEE_GUIWINDOW_H
#define GAMEEE_GUIWINDOW_H

#include<interface/RendererInt.h>
#include"GUILayer.h"

class GUIWindow {
public:
	EE_Window* pWnd;
	EE_Renderer* pRenderer;
	EE_Texture* pCanvas;
	int w;
	int h;

	GUILayer* layers;

	GUIWindow();
	GUIWindow(int w, int h);
	~GUIWindow();
	void update();

protected:

private:
};

#endif
