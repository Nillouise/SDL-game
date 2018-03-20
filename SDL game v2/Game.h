#pragma once
#include "SDL.h"
#include "TextureManager.h"
#include<iostream>
#include "Maze.h"
#include "Interact.h"

//char *imgPath = "assets/rider.bmp";


class Game
{
public:
	Game() {}
	~Game() {}
	//加载图形等
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
	Interact *m_interact = nullptr;

	int m_currentFrame;
	//数值越小，速度越快。
	int m_speed = 500;
	int m_gameStage = 1;
	std::string m_inputText;
	bool m_bRunning;
	long long m_pauseTime;
	long long m_init_pauseTime = 500;
	bool m_newRound = false;
	int m_snakeColor[3] = { 255,0,0 };
	int m_ballColor[3] = { 255,255,0 };
private:
	SDL_Window* m_pWindow;
	SDL_Renderer* m_pRenderer;
	//返回要跳转的游戏阶段
	int handleStage0Key(const std::string& key);
	void startGameMonitor(const std::string&key);
	bool reset();

//	Maze* m_maze = nullptr;
};

bool load(std::string fileName, std::string id, SDL_Renderer *pRenderer);
void draw(std::string id, int x, int y, int width, int height,
	SDL_Renderer *pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);
void drawFrame(std::string id, int x, int y, int width,
	int height, int currentRow, int currentFrame, SDL_Renderer* pRenderer,
	SDL_RendererFlip flip = SDL_FLIP_NONE);