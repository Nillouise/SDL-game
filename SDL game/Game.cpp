#include "Game.h"
#include <iostream>
#include <SDL_image.h>
char *imgPath = "assets/animate-alpha.png";
bool Game::init(const char* title, int xpos, int ypos, int width,
	int height,bool fullScreen )
{
	int flags = 0;
	if(fullScreen)
	{
		flags |= SDL_WINDOW_FULLSCREEN;
	}
	// attempt to initialize SDL
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		std::cout << "SDL init success\n";
		// init the window
		m_pWindow = SDL_CreateWindow(title, xpos, ypos,width, height, flags);
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
	m_textureManager.load("assets/animate-alpha.png",
		"animate", m_pRenderer);

//	SDL_Surface* pTempSurface = SDL_LoadBMP("assets/rider.bmp");//��������ĺ����ܼ��ظ������͵�ͼƬ��
//	SDL_Surface* pTempSurface = IMG_Load("assets/rider.bmp");
//	SDL_Surface* pTempSurface = IMG_Load("assets/animate-alpha.png");
//	SDL_Surface* pTempSurface = IMG_Load(imgPath);
	//�����õ���Renderer��������Ҫ�ڳ�ʼ�����render����ܻ�ȡTexture
//	m_pTexture = SDL_CreateTextureFromSurface(m_pRenderer,pTempSurface);
//	SDL_FreeSurface(pTempSurface);
//	SDL_QueryTexture(m_pTexture, nullptr, nullptr, &m_sourceRectangle.w, &m_sourceRectangle.h);
//	m_sourceRectangle.w = 128;
//	m_destinationRectangle.x = m_sourceRectangle.x = 0;
//	m_destinationRectangle.y = m_sourceRectangle.y = 0;
//	m_destinationRectangle.w = m_sourceRectangle.w;
//	m_destinationRectangle.h = m_sourceRectangle.h;
//	m_destinationRectangle.w = 128;
//	m_destinationRectangle.h = 82;


	return true;
}

void Game::render()
{
	SDL_RenderClear(m_pRenderer); // clear the renderer to the draw color
//	SDL_RenderCopy(m_pRenderer, m_pTexture, &m_sourceRectangle,&m_destinationRectangle);
	m_textureManager.draw("animate", 0, 0, 128, 82,
		m_pRenderer);
	m_textureManager.drawFrame("animate", 100, 100, 128, 82,
		1, m_currentFrame, m_pRenderer);
	SDL_RenderPresent(m_pRenderer); // draw to the screen
}

void Game::update()
{
	//������ʱ��getTickȥ������ʾ�������ٶȡ�
//	m_sourceRectangle.x = 128 * int(((SDL_GetTicks() / 100) % 6));
	m_currentFrame = int(((SDL_GetTicks() / 100) % 6));
}

void Game::handleEvents()
{
	SDL_Event event;
	if (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
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
