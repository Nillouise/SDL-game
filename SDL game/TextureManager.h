#pragma once
#include<iostream>
#include<SDL.h>
#include <map>

class TextureManager
{
public:
	bool load(std::string fileName, std::string id, SDL_Renderer *pRenderer);
	bool loadRect(std::string id, SDL_Renderer *pRenderer,int width,int height,int r,int g,int b);
	void draw(std::string id, int x, int y, int width, int height,
		SDL_Renderer *pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);
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
	TextureManager(){}

	

	static TextureManager* s_pInstance;
	std::map<std::string, SDL_Texture*> m_textureMap;
};
typedef TextureManager TheTextureManager;