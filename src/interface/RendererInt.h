#ifndef GAMEEE_RENDERERINT_H
#define GAMEEE_RENDERERINT_H

#include<SDL.h>

typedef SDL_Window		EE_Window;
typedef SDL_Renderer	EE_Renderer;
typedef SDL_Surface		EE_Surface;
typedef SDL_Texture		EE_Texture;
typedef	SDL_Rect		EE_Rect;


#define EE_WNDSHOWN_NONE		0
#define	EE_WNDSHOWN_CENTER		1
#define EE_WNDSHOWN_FULLSCREEN	2

/*************** window **********************/
extern EE_Window* EE_CreateWindow(char*	wnd_title,		// window's title
								  int	w,
								  int	h,
								  int	xpos,
								  int	ypos,
								  int	shown_flag		// EE_WNDSHOWN_CENTER or EE_WNDSHOWN_FULLSCREEN or EE_WNDSHOWN_NONE
								 );

extern void EE_DestroyWindow(EE_Window* pWnd);

/******************************* renderer **********************************/
extern EE_Renderer*	EE_CreateRenderer(EE_Window *	pWnd,
									  int			index
									 );

extern int EE_SetRenderTarget(EE_Renderer* pRenderer, EE_Texture* pTexture);

/*********************** surface ****************************/
extern EE_Surface* EE_LoadBMP(const char* file);

extern EE_Surface* EE_LoadPNG(const char* file);

extern EE_Surface* EE_LoadJPG(const char* file);

extern EE_Surface* EE_loadImg(const char* file);

extern void EE_FreeSurface(EE_Surface* pSurface);


/**************** texture ******************/
extern EE_Texture* EE_CreateTextureFromSurface(EE_Renderer* pRenderer, EE_Surface* pSurface);

extern EE_Texture* EE_CreateTextureFromFile(EE_Renderer* pRenderer, const char* file);

extern EE_Texture* EE_CreateTargetTextureFromFile(EE_Renderer* pRenderer, const char* file);

extern void EE_DestroyTexture(EE_Texture* pTexture);

extern int EE_QueryTexture(EE_Texture*		pTexture,
						   Uint32*			format,
						   int*				access,
						   int*				w,
						   int*				h
						  );

/**************** render present ***********************/
extern int EE_RenderCopy(EE_Renderer*		pRenderer,
						  EE_Texture*		pTexture,
						  EE_Rect*			pSrcRect,
						  EE_Rect*			pDstRect
						  );

extern void EE_RenderPresent(EE_Renderer* pRenderer);


/**************** utils ************************/
extern void EE_Delay(Uint32 ms);

/**************** system init and quit ******************/
extern int EE_Init();
extern void EE_Quit();

/**************** error *******************/
extern const char* EE_GetError();




#endif
