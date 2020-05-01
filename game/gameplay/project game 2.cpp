#include <iostream>
#include "car.h"
#include "gameplay.h"
#include "background.h"


using namespace std;

int main(int argc, char* argv[]) {
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) return -1;
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) == -1) return -1;
	SDL_Renderer* renderer;
	SDL_Window* window;
	window = SDL_CreateWindow("Gray say hello", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 900, 600, SDL_WINDOW_SHOWN);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	SDL_Event event;
	SDL_PollEvent(&event);
	background back;
	nhanvat car;
	back.texture = back.loadImage("back1.png", renderer);
	car.texture = car.loadImage("car.png", renderer);
	SDL_PollEvent(&event);
	bool running = true;
	back.startload(renderer);
	waitUntilKeyPressed();
	back.howtoplay(renderer);
	waitUntilKeyPressed();
	vector<int> highscore;

	do {
		string ptr;
		Uint32 timeout = SDL_GetTicks() + 20000;
		int score = 0;
		backgrmusic();
		bool gameplay = true;
		car.descar.x = -50;
		back.back1.x = 0;
		back.step = 5;
		string text = getText();
		int dodaitext = text.length();
		int dem = 0;
		int luot = 5;
		int checker = 0;
		do {
			SDL_RenderClear(renderer);
			while (SDL_PollEvent(&event))
			{
				if (event.type == SDL_QUIT)
				{
					gameplay = false;
					running = false;
					SDL_Quit();
					break;
				}
				if (event.type == SDL_KEYDOWN)
				{
					bool check = kiemtrakitu(event, text, dem);
					if (check == true)
					{
						if (car.descar.x <= 250) car.dichuyen();
						else back.step += 0.5;
						if (back.step > 8)back.step = 8;
						dem++;
						checker++;
						ptr += char(event.key.keysym.sym);
					}
					else
					{
						luot--;
						checker = 0;
						back.step -= 0.3;
						policesound();
					}
					if ((checker >= 10 and checker % 10 == 0) and luot < 5)
					{
						luot++;
						buff();
					}
				}
			}

			switch (checker)
			{
			case 10:
			{
				back.step = 9;
				score += 100;
				break;
			}
			case 20:
			{
				back.step = 10;
				score += 200;
				timeout += 125;
				break;
			}
			case 30:
			{
				back.step = 11;
				score += 300;
				break;
			}
			case 40:
			{
				score += 400;
				timeout += 100;
				break;
			}
			case 50:
			{
				score += 500;
				timeout += 100;
			}
			default:
				break;
			}

			score += checker * 0, 5;

			back.dichuyenback();
			back.loadback(renderer);
			car.loadcar(renderer);
			if (checker >= 25) car.loadtialua(renderer);
			if (luot < 5 and checker < 10) police(renderer, 5 - luot);
			SDL_Color fg = { 255,255,255,255 };
			drawtext(renderer, text, 30, 80, 140, fg, "font-chu-cua-zopa.otf");
			SDL_Color fg2 = { 0,0,0,0 };
			drawtext(renderer, ptr, 30, 80, 140, fg2, "font-chu-cua-zopa.otf");

			int timepassed = timeout - SDL_GetTicks();
			if (timepassed < 5000) ticktock();
			string tmp = to_string(timepassed / 1000);
			drawtext(renderer, tmp, 40, 10, 10, fg, "font-chu-cua-habbo.otf");

			health(renderer, luot);
			SDL_RenderPresent(renderer);

			if (dem == dodaitext)
			{
				police(renderer, 5 - luot);
				text = getText();
				dodaitext = text.length();
				ptr = "";
				dem = 0;
			}

			if (luot == 0)
			{
				back.lose(renderer);
				gameplay = false;
			}
			if (SDL_TICKS_PASSED(SDL_GetTicks(), timeout))
			{
				back.timeout(renderer);
				gameplay = false;
			}
			if (gameplay == false)
			{
				Mix_PauseMusic();
				highscore.push_back(score);
				int n = highscore.size();
				if (score == gethighest(highscore, n)) endgamesound();
				else endgamesound2();
				string tmp3 = to_string(gethighest(highscore, n));
				string tmp2 = to_string(score);
				drawtext(renderer, tmp2, 40, 400, 295, fg, "font-chu-cua-yelp.otf");
				drawtext(renderer, tmp3, 40, 400, 395, fg, "font-chu-cua-yelp.otf");
				SDL_RenderPresent(renderer);
				playagian();
			}
		} while (gameplay == true);
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
			{
				SDL_Quit();
				gameplay = false;
				running = false;
				break;
			}
		}
		playagian();
		Mix_PauseMusic();
		running == true;
		SDL_RenderClear(renderer);
		back.startload(renderer);
		waitUntilKeyPressed();
	} while (running == true);

	back.phahuy();
	car.phahuy();
	SDL_DestroyRenderer(renderer);
	Mix_CloseAudio();
	SDL_Quit();
	return 0;
}