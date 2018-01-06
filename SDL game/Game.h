#pragma once
#include "SDL.h"
#include "TextureManager.h"
#include<iostream>
//char *imgPath = "assets/rider.bmp";


class Game
{
public:
	Game() {}
	~Game() {}
	// simply set the running variable to true
	void init()
	{
	}
	bool init(const char* title, int xpos, int ypos, int width, int height, bool fullScreen);
	void render();
	void update();
	void handleEvents();
	void clean();
	// a function to access the private running variable
	bool running() { return m_bRunning; }
	bool load(std::string fileName, std::string id, SDL_Renderer *pRenderer);
	void draw(std::string id, int x, int y, int width, int height,
		SDL_Renderer *pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);
	void drawFrame(std::string id, int x, int y, int width,
		int height, int currentRow, int currentFrame, SDL_Renderer* pRenderer,
		SDL_RendererFlip flip = SDL_FLIP_NONE);
private:
	SDL_Window* m_pWindow;
	SDL_Renderer* m_pRenderer;
//
//	SDL_Texture* m_pTexture; // the new SDL_Texture variable
//	SDL_Rect m_sourceRectangle; // the first rectangle
//	SDL_Rect m_destinationRectangle; // another rectangle

	int m_currentFrame;
	TextureManager m_textureManager;

	bool m_bRunning;
};

bool load(std::string fileName, std::string id, SDL_Renderer *pRenderer);
void draw(std::string id, int x, int y, int width, int height,
	SDL_Renderer *pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);
void drawFrame(std::string id, int x, int y, int width,
	int height, int currentRow, int currentFrame, SDL_Renderer* pRenderer,
	SDL_RendererFlip flip = SDL_FLIP_NONE);