#include<SDL.h>
#include<SDL_image.h>
#include<string>
#include<iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <fstream>

using namespace std;

SDL_Texture* loadImage(std::string fileAnh, SDL_Renderer* render);

void waitUntilKeyPressed();

string getText();
