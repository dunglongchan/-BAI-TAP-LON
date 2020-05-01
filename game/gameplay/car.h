#pragma once
#include <SDL.h>
#include <iostream>
#include <SDL_image.h>
#include <stdio.h>
#include "background.h"

using namespace std;

class nhanvat :public background
{
public:
	SDL_Rect srccar, descar;
	void phahuy();
	void loadcar(SDL_Renderer* renderer);
	void dichuyen();
	void loadtialua(SDL_Renderer* renderer);
private:
	
};

