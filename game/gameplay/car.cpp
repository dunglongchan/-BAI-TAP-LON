#include "car.h"

using namespace std;

void nhanvat::loadcar(SDL_Renderer* renderer)
{
	srccar.x = 0, srccar.y = 0, srccar.w = 300, srccar.h = 120;
	descar.y = 420, descar.w = 300, descar.h = 120;
	SDL_RenderCopy(renderer,texture, &srccar, &descar);
}
void nhanvat::dichuyen()
{
	descar.x += 10;
}
void nhanvat:: loadtialua(SDL_Renderer* renderer)
{
	SDL_Rect src, des;
	src.x = 0, src.y = 0, src.w = 100, src.h = 30;
	des.x = 140, des.y = 480, des.w = 100, des.h = 30;
	SDL_Surface* surf = IMG_Load("fire .png");
	SDL_Texture* tex = SDL_CreateTextureFromSurface(renderer, surf);
	SDL_RenderCopy(renderer, tex, &src, &des);
	SDL_DestroyTexture(tex);
}
void nhanvat::phahuy()
{
	SDL_DestroyTexture(texture);
}