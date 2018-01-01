#pragma once
#include "SDL.h"
#include <SDL_image.h>
class Game
{
public:
	Game() {}
	~Game() {}
	// simply set the running variable to true
	void init()
	{
		m_bRunning = true;
//		SDL_Surface* pTempSurface = SDL_LoadBMP("assets/rider.bmp");
		SDL_Surface* pTempSurface = IMG_Load("assets/rider.bmp");
		m_pTexture = SDL_CreateTextureFromSurface(m_pRenderer,
			pTempSurface);
		SDL_FreeSurface(pTempSurface);
		SDL_QueryTexture(m_pTexture, nullptr, nullptr,&m_sourceRectangle.w, &m_sourceRectangle.h);
	
		m_destinationRectangle.x = m_sourceRectangle.x = 0;
		m_destinationRectangle.y = m_sourceRectangle.y = 0;
		m_destinationRectangle.w = m_sourceRectangle.w;
		m_destinationRectangle.h = m_sourceRectangle.h;
	}
	bool init(const char* title, int xpos, int ypos, int width, int height, bool fullScreen);
	void render();
	void update();
	void handleEvents();
	void clean();
	// a function to access the private running variable
	bool running() { return m_bRunning; }
private:
	SDL_Window* m_pWindow;
	SDL_Renderer* m_pRenderer;

	SDL_Texture* m_pTexture; // the new SDL_Texture variable
	SDL_Rect m_sourceRectangle; // the first rectangle
	SDL_Rect m_destinationRectangle; // another rectangle

	bool m_bRunning;
};