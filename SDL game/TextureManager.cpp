#include "TextureManager.h"
#include <SDL_image.h>
#include <SDL.h>
TextureManager* TextureManager::s_pInstance = nullptr;

bool TextureManager::load(const std::string &fileName, const std::string
	&id, SDL_Renderer* pRenderer)
{
	SDL_Surface* pTempSurface = IMG_Load(fileName.c_str());
	if (pTempSurface == 0)
	{
		return false;
	}
	SDL_Texture* pTexture =
		SDL_CreateTextureFromSurface(pRenderer, pTempSurface);
	SDL_FreeSurface(pTempSurface);
	// everything went ok, add the texture to our list
	if (pTexture != 0)
	{
		m_textureMap[id] = pTexture;
		return true;
	}
	// reaching here means something went wrong
	return false;
}

bool TextureManager::loadRect(const std::string &id, SDL_Renderer* pRenderer, int width, int height, int r, int g, int b)
{
	SDL_Surface *pTempSurface = nullptr;
	pTempSurface = SDL_CreateRGBSurface(0, width, height, 32, 0, 0, 0, 0);
	SDL_FillRect(pTempSurface, NULL, SDL_MapRGB(pTempSurface->format, r, g, b));
	SDL_Texture* pTexture =
		SDL_CreateTextureFromSurface(pRenderer, pTempSurface);
	SDL_FreeSurface(pTempSurface);
	if (pTexture!=nullptr)
	{
		m_textureMap[id] = pTexture;
		return true;
	}
	return false;
}

void TextureManager::draw(const std::string &id, int x, int y, int
	width, int height, SDL_Renderer* pRenderer,
	SDL_RendererFlip flip)
{
	SDL_Rect srcRect;
	SDL_Rect destRect;
	srcRect.x = 0;
	srcRect.y = 0;
	srcRect.w = destRect.w = width;
	srcRect.h = destRect.h = height;
	destRect.x = x;
	destRect.y = y;
	SDL_RenderCopyEx(pRenderer, m_textureMap[id], &srcRect,
		&destRect, 0, 0, flip);
}

void TextureManager::drawText(const std::string& text, int x, int y, SDL_Renderer* pRenderer,SDL_Color White)
{
	//std::cout << "ERROR:" << TTF_GetError() << std::endl; //此函数可以获得TTF执行过程中的错误
	
	SDL_Surface* surfaceMessage = TTF_RenderText_Solid(Sans, text.c_str(), White); // as TTF_RenderText_Solid could only be used on SDL_Surface then you have to create the surface first

	SDL_Texture* Message = SDL_CreateTextureFromSurface(pRenderer, surfaceMessage); //now you can convert it into a texture

	SDL_Rect Message_rect; //create a rect
	Message_rect.x = x;  //controls the rect's x coordinate 
	Message_rect.y = y; // controls the rect's y coordinte
	Message_rect.w = text.length()*20; // controls the width of the rect
	Message_rect.h = 100; // controls the height of the rect

						  //Mind you that (0,0) is on the top left of the window/screen, think a rect as the text's box, that way it would be very simple to understance

						  //Now since it's a texture, you have to put RenderCopy in your game loop area, the area where the whole code executes

	SDL_RenderCopy(pRenderer, Message, NULL, &Message_rect); //you put the renderer's name first, the Message, the crop size(you can ignore this if you don't want to dabble with cropping), and the rect which is the size and coordinate of your texture

															//Don't forget too free your surface and texture
}

void TextureManager::drawFrame(std::string id, int x, int y, int
	width, int height, int currentRow, int currentFrame, SDL_Renderer
	*pRenderer, SDL_RendererFlip flip)
{
	SDL_Rect srcRect;
	SDL_Rect destRect;
	srcRect.x = width * currentFrame;
	srcRect.y = height * (currentRow - 1);
	srcRect.w = destRect.w = width;
	srcRect.h = destRect.h = height;
	destRect.x = x;
	destRect.y = y;
	SDL_RenderCopyEx(pRenderer, m_textureMap[id], &srcRect,
		&destRect, 0, 0, flip);
}
