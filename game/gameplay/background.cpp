#include "background.h"

using namespace std;

	SDL_Texture* background:: loadImage(string fileAnh, SDL_Renderer* renderer)
	{
		SDL_Surface* surf = IMG_Load(fileAnh.c_str());
		SDL_Texture* tex;
		tex = SDL_CreateTextureFromSurface(renderer, surf);
		return tex;
	}
	void background::startload(SDL_Renderer* renderer)
	{
		start.x = 0, start.y = 0, start.w = 900, start.h = 600;
		start1.x = 0, start1.y = 0, start1.w = 900, start1.h = 600;
		SDL_RenderCopy(renderer, loadImage("start.png", renderer), &start, &start1);
		SDL_RenderPresent(renderer);
		SDL_RenderClear;
	}
	void background::howtoplay(SDL_Renderer* renderer)
	{
		start.x = 0, start.y = 0, start.w = 900, start.h = 600;
		start1.x = 0, start1.y = 0, start1.w = 900, start1.h = 600;
		SDL_RenderCopy(renderer, loadImage("howtoplay.png", renderer), &start, &start1);
		SDL_RenderPresent(renderer);
		SDL_RenderClear;
	}
	void background::phahuy()
	{
		SDL_DestroyTexture(texture);
	}
	void background::loadback(SDL_Renderer* renderer)
	{
		back.x = 0, back.y = 0, back.w = 5000, back.h = 600;
		back1.y = 0, back1.w = 5000, back1.h = 600;
		SDL_RenderCopy(renderer, texture, &back, &back1);
	}
	void background::dichuyenback()
	{
		if (back1.x < -4090) back1.x = 0;
		else back1.x -= step;
	}
	void background::lose(SDL_Renderer* renderer)
	{
		start.x = 0, start.y = 0, start.w = 700, start.h = 491;
		start1.x = 100, start1.y = 40, start1.w = 700, start1.h = 491;
		SDL_RenderCopy(renderer, loadImage("lose.png", renderer), &start, &start1);
	}
	void background::timeout(SDL_Renderer* renderer)
	{
		start.x = 0, start.y = 0, start.w = 701, start.h = 491;
		start1.x = 100, start1.y = 40, start1.w =701 , start1.h = 491;
		SDL_RenderCopy(renderer, loadImage("timeout.png", renderer), &start, &start1);
	}