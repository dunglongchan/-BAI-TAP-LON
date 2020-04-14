#define SDL_MAIN_HANDLED
#include "logicgame.h"

using namespace std;

int main() {
	SDL_Renderer* render;
	SDL_Window* window;
	SDL_Surface* surf;
	SDL_CreateWindowAndRenderer(840, 464,0, &window, &render);
	SDL_SetWindowTitle(window, "GREY GAMING");
	SDL_RenderCopy(render, loadImage("backgrtest.png", render), NULL, NULL);
	waitUntilKeyPressed();
	SDL_Rect back, back1;
	SDL_Rect car, car1;
	back.x = 0, back.y = 0,back.w = 1291, back.h = 464;
	back1.x = 0, back1.y = 0, back1.w = 1291, back1.h = 464;
	car.x = 0, car.y = 0, car.w = 600, car.h = 239; 
	car1.x = -100, car1.y = 230, car1.w = 600, car1.h = 239;
	bool running = 1;
	int time = 0;
	string path1 = "carfinal.png";
	string path2 = "carfinal1.png";
	string path;
	while (running) {
		if (car1.x > 50) {
			if (back1.x < -440) back1.x += 0;
			else back1.x -= 50;
		}
		SDL_RenderCopy(render, loadImage("backgr.png", render), &back, &back1);
		SDL_RenderPresent(render);
		car1.x += 40;
		if (time % 2 == 0) path = path1;
		else path = path2;
		time++;
		SDL_RenderCopy(render, loadImage(path, render), &car, &car1);
		SDL_RenderPresent(render);
		if (back1.x < -400) running = 0;
		waitUntilKeyPressed();
		SDL_RenderClear(render);
		
	}
	SDL_Quit;
	return 0;
}