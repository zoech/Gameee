#include"RendererInt.h"
#include<SDL_image.h>


extern int EE_Init(){
	return SDL_Init(SDL_INIT_EVERYTHING);
}


extern void EE_Quit(){
	SDL_Quit();
}


extern EE_Window* EE_CreateWindow(char* wnd_title,
								  int w,
								  int h,
								  int xpos,
								  int ypos,
								  int shown_flag){
	if (shown_flag == EE_WNDSHOWN_NONE ||
		shown_flag == EE_WNDSHOWN_CENTER){
		xpos = ypos = SDL_WINDOWPOS_CENTERED;
	}

	Uint32 flag = SDL_WINDOW_SHOWN;
	if (shown_flag == EE_WNDSHOWN_FULLSCREEN){
		flag = SDL_WINDOW_FULLSCREEN;
	}

	return SDL_CreateWindow(wnd_title, xpos, ypos, w, h, flag);

}

extern void EE_DestroyWindow(EE_Window* pWnd){
	SDL_DestroyWindow(pWnd);
}

extern EE_Renderer* EE_CreateRenderer(EE_Window* pWnd, int index){
	Uint32 flag = 0;
	EE_Renderer* p = SDL_CreateRenderer(pWnd, index, flag);
	if(!p){
		flag = SDL_RENDERER_ACCELERATED;
		p = SDL_CreateRenderer(pWnd, index, flag);
	}

	if(!p){
		flag = SDL_RENDERER_SOFTWARE;
		p = SDL_CreateRenderer(pWnd, index, flag);
	}
	
	return p;
}

extern int EE_SetRenderTarget(EE_Renderer* pRenderer, EE_Texture* pTexture){
	return SDL_SetRenderTarget(pRenderer, pTexture);
}

extern EE_Surface* EE_LoadBMP(const char* file){
	return SDL_LoadBMP(file);
}

extern EE_Surface* EE_LoadPNG(const char* file){
	return IMG_Load(file);
}

extern EE_Surface* EE_LoadJPG(const char* file){
	return IMG_Load(file);
}

extern EE_Surface* EE_LoadImg(const char* file){
	return IMG_Load(file);
}

extern void EE_FreeSurface(EE_Surface* pSurface){
	SDL_FreeSurface(pSurface);
}

extern EE_Texture* EE_CreateTextureFromSurface(EE_Renderer* pRenderer, EE_Surface* pSurface){
	return SDL_CreateTextureFromSurface(pRenderer, pSurface);
}

extern EE_Texture* EE_CreateTextureFromFile(EE_Renderer* pRenderer, const char* file){
	EE_Surface* pSfcTmp = NULL;
	EE_Texture* pTexture = NULL;

	pSfcTmp = IMG_Load(file);
	if(!pSfcTmp){
		DebugLog("error loading file!");
		FDebugLog("load file %s failed!", file);
		return NULL;
	}
	
	pTexture = SDL_CreateTextureFromSurface(pRenderer, pSfcTmp);
	SDL_FreeSurface(pSfcTmp);
	return pTexture;
}

extern EE_Texture* EE_CreateTargetTextureFromFile(EE_Renderer* pRenderer, const char* file){
	EE_Surface* pSfcTmp = NULL;
	EE_Texture* pTexTmp = NULL;
	EE_texture* pTexReturn = NULL;

	pSfcTmp = IMG_Load(file);
	if(!pSfcTmp){
		DebugLog("error loading file!");
		FDebugLog("load file %s failed!", file);
		return NULL;
	}

	pTexTmp = SDL_CreateTextureFromSurface(pRenderer, pSfcTmp);
	SDL_FreeSurface(pSfcTmp);

	int w,h;
	SDL_QueryTexture(pTexTmp, NULL, NULL, &w, &h);
	pTexReturn = SDL_CreateTexture(pRenderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, w, h);

	EE_Texture* pTexTargetTmp = SDL_GetRenderTarget(pRenderer);
	
	if(SDL_SetRenderTarget(pRenderer, pTexReturn) == 0){
		/* success */
		int copyRest = SDL_RenderCopy(pRenderer, pTexTmp, NULL, NULL);
		if(copyRest != 0){
			/* copy failed */
			DebugLog("SDL_RenderCopy failed!");
		}
	} else {
		/* changed render target failed */
		DebugLog("SDL_SetRenderTarget failed!");
	}

	SDL_DestroyTexture(pTexTmp);

	if(SDL_SetRenderTarget(pRenderer, pTexTargetTmp) != 0){
		DebugLog("failed when exchanged to the original render target, exit!");
		SDL_Quit();
	}

	return pTexReturn;
}

extern void EE_DestroyTexture(EE_Texture* pTexture){
	SDL_DestroyTexture(pTexture);
}

extern int EE_QueryTexture(EE_Texture* pTexture,
						   Uint32* format,
						   int* access,
						   int* w,
						   int* h){
	return SDL_QueryTexture(pTexture, format, access, w, h);
}

extern int EE_RenderCopy(EE_Renderer*	pRenderer,
						 EE_Texture*	pTexture,
						 EE_Rect*		pSrcRect,
						 EE_Rect*		pDstRect){
	return SDL_RenderCopy(pRenderer, pTexture, pSrcRect, pDstRect);
}

extern void EE_RenderPresent(EE_Renderer* pRenderer){
	SDL_RenderPresent(pRenderer);
}

extern void EE_Delay(Uint32 ms){
	return SDL_Delay(ms);
}

extern const char* EE_GetError(){
	return SDL_GetError();
}
