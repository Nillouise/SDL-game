#pragma once
#include "SDL.h"
class Game
{
public:
	Game() {}
	~Game() {}
	// simply set the running variable to true
	void init() { m_bRunning = true; }
	bool init(const char* title, int xpos, int ypos, int width, int height, bool fullScreen);
	void render();
	void update() {}
	void handleEvents();
	void clean();
	// a function to access the private running variable
	bool running() { return m_bRunning; }
private:
	SDL_Window* m_pWindow;
	SDL_Renderer* m_pRenderer;

	bool m_bRunning;
};