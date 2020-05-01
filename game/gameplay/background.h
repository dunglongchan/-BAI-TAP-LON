#pragma once
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include "gameplay.h"

using namespace std;

class background
{
public:
	string fileAnh;
	int step;
	SDL_Rect start;
	SDL_Rect start1;
	SDL_Rect back;
	SDL_Rect back1;
	SDL_Texture* texture;

	SDL_Texture* loadImage(string fileAnh, SDL_Renderer* renderer);
	void startload(SDL_Renderer* renderer);
	void howtoplay(SDL_Renderer* renderer);
	void phahuy();
	void loadback(SDL_Renderer* renderer);
	void dichuyenback();
	void lose(SDL_Renderer* renderer);
	void timeout(SDL_Renderer* renderer);
private:
	
	

};

