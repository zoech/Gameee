#include<interface/RendererInt.h>

EE_Window* pWnd = NULL;
EE_Renderer* pRenderer = NULL;

EE_Texture* pTex = NULL;
int main(int argc, char** args){
	
	EE_Init();
	pWnd = EE_CreateWindow("test", 640, 480, 0, 0, EE_WNDSHOWN_CENTER);
	pRenderer = EE_CreateRenderer(pWnd, -1);

	EE_Surface* pSfc = EE_LoadJPG("Penguins.jpg");
	pTex = EE_CreateTextureFromSurface(pRenderer, pSfc);
	EE_FreeSurface(pSfc);

	EE_RenderCopy(pRenderer, pTex, NULL, NULL);

	EE_RenderPresent(pRenderer);

	EE_Delay(5000);

	EE_Quit();

	return 0;
}
