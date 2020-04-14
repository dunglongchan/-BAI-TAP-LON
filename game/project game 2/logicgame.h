#include<SDL.h>
#include<SDL_image.h>
#include<string>
#include<iostream>

using namespace std;

SDL_Texture* loadImage(std::string fileAnh, SDL_Renderer* render);

void waitUntilKeyPressed();