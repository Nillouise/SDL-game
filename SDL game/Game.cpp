#include "Game.h"
#include <iostream>
#include <SDL_image.h>
char* imgPath = "assets/animate-alpha.png";

bool Game::init(const char* title, int xpos, int ypos, int width,
                int height, bool fullScreen)
{
	int flags = 0;
	if (fullScreen)
	{
		flags |= SDL_WINDOW_FULLSCREEN;
	}
	// attempt to initialize SDL
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		std::cout << "SDL init success\n";
		// init the window
		m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		if (m_pWindow != 0) // window init success
		{
			std::cout << "window creation success\n";
			m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);
			if (m_pRenderer != 0) // renderer init success
			{
				std::cout << "renderer creation success\n";
				SDL_SetRenderDrawColor(m_pRenderer,
				                       100, 255, 255, 255);
			}
			else
			{
				std::cout << "renderer init fail\n";
				return false; // renderer init fail
			}
		}
		else
		{
			std::cout << "window init fail\n";
			return false; // window init fail
		}
	}
	else
	{
		std::cout << "SDL init fail\n";
		return false; // SDL init fail
	}
	std::cout << "init success\n";
	m_bRunning = true; // everything inited successfully,start the main loop
	//	m_textureManager.load("assets/animate-alpha.png",
	//		"animate", m_pRenderer);
	if (!TheTextureManager::Instance()->load("assets/animate-alpha.png",
	                                         "animate", m_pRenderer))
	{
		return false;
	}
	if (!TheTextureManager::Instance()->loadRect("rect", m_pRenderer, 10, 10, 255, 0, 0))
	{
		return false;
	}
	maze = new Maze(25, 25);
	maze->init();
	return true;
}

void Game::render()
{
	SDL_RenderClear(m_pRenderer); // clear the renderer to the draw color
	//	SDL_RenderCopy(m_pRenderer, m_pTexture, &m_sourceRectangle,&m_destinationRectangle);
//	TheTextureManager::Instance()->draw("animate", 0, 0, 128, 82,
//	                                    m_pRenderer);
//	TheTextureManager::Instance()->draw("rect", 50, 100, 128, 82,
//	                                    m_pRenderer);
//	TheTextureManager::Instance()->drawFrame("animate", 100, 100, 128, 82,
//	                                         1, m_currentFrame, m_pRenderer);
	for(auto a:maze->getSanke())
	{
		TheTextureManager::Instance()->draw("rect", a.first*20, a.second*20, 20, 20, m_pRenderer);		
	}

	TheTextureManager::Instance()->draw("rect", maze->ball.first*20,maze->ball.second*20, 20, 20, m_pRenderer);

	SDL_RenderPresent(m_pRenderer); // draw to the screen
}

void Game::update()
{
	//这里用时间getTick去控制显示动画的速度。
	//	m_sourceRectangle.x = 128 * int(((SDL_GetTicks() / 100) % 6));
	static Uint32 preTime = 0;
	Uint32 curTime = SDL_GetTicks();
	m_currentFrame = int(((curTime / 100) % 6));
	if (m_pauseTime > 0)
	{
		m_pauseTime--;
		if (m_pauseTime <= 0)
		{
			maze->init();
		}
		return;
	}
	if (curTime / m_speed != preTime / m_speed)
	{
		preTime = curTime;
		if (!maze->forward())
		{
			m_pauseTime = 500;
			return;
		}
	}
}

int keyToDirect(std::string keyname)
{
	static std::map<std::string, int> convertor{{"Up",0},{"Right",1},{"Down",2},{"Left",3}};
	return convertor[keyname];
}

void Game::handleEvents()
{
	SDL_Event event;
	int keyCode = 0;
	if (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_KEYDOWN:
			keyCode = keyToDirect(SDL_GetKeyName(event.key.keysym.sym));
			printf("key %s down！code %d\n", SDL_GetKeyName(event.key.keysym.sym), keyCode);
			maze->changeDirection(keyCode);
			break;
		case SDL_QUIT:
			m_bRunning = false;
			break;
		default:
			break;
		}
	}
}

void Game::clean()
{
	std::cout << "cleaning game\n";
	SDL_DestroyWindow(m_pWindow);
	SDL_DestroyRenderer(m_pRenderer);
	SDL_Quit();
}


