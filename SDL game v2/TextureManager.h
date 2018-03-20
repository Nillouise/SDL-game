#pragma once
#include<iostream>
#include<SDL.h>
#include <SDL_ttf.h>
#include <map>

class TextureManager
{
public:
	bool load(const std::string &fileName,const std::string &id, SDL_Renderer *pRenderer);
	bool loadRect(const std::string &id, SDL_Renderer *pRenderer,int width,int height,int r,int g,int b);
	void draw(const std::string &id, int x, int y, int width, int height,
		SDL_Renderer *pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);
	void drawText(const std::string &text, int x, int y, SDL_Renderer *pRenderer,SDL_Color White = { 255,255,255 });
	void drawFrame(std::string id, int x, int y, int width,
		int height, int currentRow, int currentFrame, SDL_Renderer* pRenderer,
		SDL_RendererFlip flip = SDL_FLIP_NONE);
	static TextureManager* Instance()
	{
		if (s_pInstance == nullptr)
		{
			s_pInstance = new TextureManager();
			return s_pInstance;
		}
		return s_pInstance;
	}
private:
	TextureManager()
	{
		TTF_Init();
		Sans = TTF_OpenFont("resource/ttf/OpenSans-Regular.ttf", 24); //this opens a font style and sets a size
	}

	static TextureManager* s_pInstance;
	std::map<std::string, SDL_Texture*> m_textureMap;
	TTF_Font* Sans = nullptr; 
};
typedef TextureManager TheTextureManager;