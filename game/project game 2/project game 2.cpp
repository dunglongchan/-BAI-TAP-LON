#define SDL_MAIN_HANDLED
#include "logicgame.h"

using namespace std;

int main(int argc,char* argv[]) {
	
	SDL_Renderer* render1;
	SDL_Window* window;
	

	SDL_CreateWindowAndRenderer(900, 600, 0, &window, &render1);
	SDL_SetWindowTitle(window,"GREY 5TING");
	SDL_Texture* tex = loadImage("back1.png", render1);
	SDL_Texture* tex2 = loadImage("car final .png", render1);
	SDL_Event e;
	start(render1);
	waitUntilKeyPressed();
	SDL_RenderClear(render1);

	SDL_Rect car, car1, back, back1;
	car.x = 0, car.y = 0, car.w = 300, car.h = 150;
	car1.x = -100, car1.y = 460, car1.w = 300, car1.h = 150;
	back.x = 0, back.y = 0, back.w = 2500, back.h = 600;
	back1.x = 0, back1.y = 0, back1.w = 2500, back1.h = 600;

	bool running = 1;
	string text = getText();
	int dodaitext = text.length();
	cout << text << endl;
	int dem = 0;
	int luot = 5;
	int checker = 0;
	SDL_PollEvent(&e);
	while (running) {
		while (SDL_PollEvent(&e)) {
			if (e.type == SDL_KEYDOWN) {
				bool check = cheker(e, text, dem);
				if (check == true) {
					if (car1.x <= 250) car1.x += 10;
					else back1.x -= 30;
					dem++;
					cout << dem << ' ';
					if (luot < 5) checker++;
					cout << checker << ' ';
				}
				else luot--;
				if (checker == 10 and luot!=5) {
					luot++;
					checker = 0;
				}
				cout << luot <<endl;
			}
		}
		if (luot == 0) {
			cout << endl <<"lose";
			running = 0;
		}
		if (dem == dodaitext) {
			cout << endl << "win";
			running = 0;
		}
		SDL_RenderCopy(render1, tex, &back, &back1);
		SDL_RenderCopy(render1, tex2, &car, &car1);
		SDL_RenderPresent(render1);
		if (back1.x < -1500) back1.x = 0;
		SDL_RenderClear(render1);
	} 

	SDL_DestroyRenderer(render1);
	SDL_DestroyTexture(tex);
	SDL_DestroyTexture(tex2);
	SDL_Quit;

	return 0;
}