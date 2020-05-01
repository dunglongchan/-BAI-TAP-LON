#include<SDL.h>
#include<SDL_image.h>
#include<string>
#include<iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <fstream>
#include <SDL_ttf.h>
#include <stdio.h>

using namespace std;

SDL_Texture* loadImage(std::string fileAnh, SDL_Renderer* render);
void waitUntilKeyPressed();
string getText();
bool check(string x, int y, char z);
void start(SDL_Renderer* render);
bool cheker(SDL_Event e, string text, int dem);
void drawtext( SDL_Renderer* renderer, string text);