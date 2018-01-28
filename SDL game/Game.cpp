#include "Game.h"
#include "GlobalVariable.h"
#include <iostream>
#include <SDL_image.h>
#include"Robot.h"
#include<string>
const char* imgPath = "assets/animate-alpha.png";

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
				SDL_SetRenderDrawColor(m_pRenderer, 100, 255, 255, 255);
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
	if (!TheTextureManager::Instance()->load("assets/animate-alpha.png", "animate", m_pRenderer))
	{
		std::cout << "load assets folder error";
		return false;
	}
	if (!TheTextureManager::Instance()->loadRect("snakeUnit", m_pRenderer, 20, 20, m_snakeColor[0], m_snakeColor[1], m_snakeColor[2]))
	{
		return false;
	}
	if (!TheTextureManager::Instance()->loadRect("ball", m_pRenderer, 20, 20, m_ballColor[0], m_ballColor[1], m_ballColor[2]))
	{
		return false;
	}

	return reset();
}

void Game::render()
{
	switch (m_gameStage)
	{
	case 0:
		SDL_RenderClear(m_pRenderer); // clear the renderer to the draw color
		TheTextureManager::Instance()->drawText(m_inputText, 0, 0, m_pRenderer);
		SDL_RenderPresent(m_pRenderer); // draw to the screen
		break;
	case 1:
		SDL_RenderClear(m_pRenderer); // clear the renderer to the draw color
		//暂停时，绘制相应的信息
		if (g_starter->is_set_my_computer_to_server())
		{
			if (m_pauseTime > 0)
			{
				TheTextureManager::Instance()->drawText("press S to start game", 10, 60, m_pRenderer, { 255,255,255,100 });
				TheTextureManager::Instance()->drawText("press Q to quit game",10, 90, m_pRenderer,{255,255,255,100});
			}
		}
		else
		{
			if (m_pauseTime > 0)
			{
				TheTextureManager::Instance()->drawText("wait for server to start game", 5, 5, m_pRenderer);
			}
		}
		//绘制ball
		for (auto a : m_interact->m_maze->balls)
		{
			TheTextureManager::Instance()->draw("ball", a.c * 20, a.r * 20, 20, 20, m_pRenderer);
		}
		//绘制snake
		for (auto a : m_interact->m_snakeMap)
		{
			auto b = a.second;
			for (auto a : b->body)
			{
				TheTextureManager::Instance()->draw("snakeUnit", a.c * 20, a.r * 20, 20, 20, m_pRenderer);
			}
		}
		SDL_RenderPresent(m_pRenderer); // draw to the screen
		break;
	}
}

void Game::update()
{
	switch (m_gameStage)
	{
	case 0:
		break;
	case 1:
		//主服务器的逻辑
		if (g_starter->is_set_my_computer_to_server())
		{
			robotInput();
			static Uint32 preTime = 0;
			//配合startGameMonitor，监听是否应该新开游戏
			if (m_pauseTime > 0)
			{
				if (m_newRound)
				{
					reset();
					m_pauseTime = 0;
					m_newRound = false;
				}
				else
				{
					return;
				}
			}
			//这里用时间getTick去控制显示动画的速度。
			//m_sourceRectangle.x = 128 * int(((SDL_GetTicks() / 100) % 6));
			//这里设置更新速度
			Uint32 curTime = SDL_GetTicks();
			m_currentFrame = int(((curTime / 100) % 6));
			if (curTime / m_speed != preTime / m_speed)
			{
				preTime = curTime;
				Status curSnakeStatus;
				Status gameStatus = m_interact->forward(curSnakeStatus);
				if (gameStatus == Status::finished)
				{
					m_pauseTime = m_init_pauseTime;
					m_newRound = false;
					return;
				}
				m_interact->setNewTurn();
			}
		}
		break;
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
	int direct = 0;
	if (SDL_PollEvent(&event))
	{
		std::string keyname;
		switch (m_gameStage)
		{
		case 0:
			switch (event.type)
			{
			case SDL_KEYDOWN:
				SDL_GetKeyName(event.key.keysym.sym);
				break;
			case SDL_QUIT:
				m_bRunning = false;
				break;
			default:
				break;
			}
			break;
		case 1:
			switch (event.type)
			{
			case SDL_KEYDOWN:
				keyname = SDL_GetKeyName(event.key.keysym.sym);
				direct = keyToDirect(keyname);
				printf("key %s down！code %d\n", keyname.c_str(), direct);
				//			m_maze->changeDirection(keyCode);
				m_interact->input(0, direct);
				startGameMonitor(keyname);
				break;
			case SDL_QUIT:
				m_bRunning = false;
				break;
			default:
				break;
			}
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

int Game::handleStage0Key(const std::string& key)
{
	if (key == "Backspace")
	{
		std::cout << m_inputText << " pop back to";
		m_inputText.pop_back();
		std::cout << m_inputText << std::endl;
		return 0;
	}
	else if (key == "Return")
	{
		return 1;
	}
	else
	{
		if (key.length() > 0)
		{
			m_inputText.push_back(key[0]);
		}
		return 0;
	}
}

void Game::startGameMonitor(const std::string& key)
{
	if (g_starter->is_set_my_computer_to_server() && m_pauseTime > 0)
	{
		if (key == "S")
		{
			m_newRound = true;
		}
		else if (key == "Q")
		{
			m_bRunning = false;
		}
	}
}

bool Game::reset()
{
	m_pauseTime = m_init_pauseTime;
	delete m_interact;
	m_interact = new Interact();
	m_interact->m_maze = new Maze(25, 25);

	m_interact->m_maze->balls.push_back(Ball(4, 4));
	m_interact->m_maze->balls.push_back(Ball(10, 10));
	m_interact->m_maze->balls.push_back(Ball(15, 15));


	m_interact->m_aliveSnakeCount = 1;
	m_interact->m_snakeMap[0] = new Snake(Point());
	if (g_starter->robot_start())
	{
		m_interact->m_aliveSnakeCount += g_starter->robot_number();
		for (int i = 1; i <= g_starter->robot_number(); i++)
		{
			m_interact->m_snakeMap[i] = new Snake(Point(i + 3, i + 3));
			addRobot(i);
		}
	}
	m_interact->m_oriAliveSnakeCount = m_interact->m_aliveSnakeCount;
	return true;
}
