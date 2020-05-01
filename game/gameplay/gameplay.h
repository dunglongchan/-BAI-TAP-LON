#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <SDL.h>
#include <string>
#include <fstream>
#include <SDL_ttf.h>
#include <cstdlib>
#include <ctime>
#include <SDL_image.h>
#include <SDL_mixer.h>

using namespace std;

bool kiemtrakitu(SDL_Event e, string text, int dem);

string getText();

void waitUntilKeyPressed();

void drawtext(SDL_Renderer* renderer, string text, int size, int desX, int desY, SDL_Color fg, string fontname);

void health(SDL_Renderer* renderer, int n);

int gethighest(vector<int>a,int n);

void police(SDL_Renderer* renderer,int n);

void backgrmusic();

void ticktock();

void firesound();

void endgamesound();

void endgamesound2();

void policesound();

void buff();

void playagian();