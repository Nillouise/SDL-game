#pragma once
#include "SDL.h"
#include "TextureManager.h"
#include<iostream>
#include "Maze.h"

//char *imgPath = "assets/rider.bmp";

class Game
{
public:
	Game() {}
	~Game() {}
	// simply set the running variable to true
	
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
	Maze* maze = nullptr;
	int m_currentFrame;
	//数值越小，速度越快。
	int m_speed = 500;
	bool m_bRunning;
	long long m_pauseTime;
	long long m_init_pauseTime = 5000;
	int m_snakeColor[3] = { 255,0,0 };
	int m_ballColor[3] = { 255,255,0 };
};

bool load(std::string fileName, std::string id, SDL_Renderer *pRenderer);
void draw(std::string id, int x, int y, int width, int height,
	SDL_Renderer *pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);
void drawFrame(std::string id, int x, int y, int width,
	int height, int currentRow, int currentFrame, SDL_Renderer* pRenderer,
	SDL_RendererFlip flip = SDL_FLIP_NONE);