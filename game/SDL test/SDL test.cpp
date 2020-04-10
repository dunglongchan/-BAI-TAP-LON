#include <iostream>

#include <SDL.h>
#include <SDL_image.h>

const int WIDTH = 1360, HEIGHT = 600;

int main(int argc, char* argv[])
{
    SDL_Surface* imageSurface = NULL;
    SDL_Surface* windowSurface = NULL;

    SDL_Init(SDL_INIT_EVERYTHING);

    SDL_Window* window = SDL_CreateWindow("Hello SDL World", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_ALLOW_HIGHDPI);
    windowSurface = SDL_GetWindowSurface(window);
    if (NULL == window)
    {

        std::cout << "Could not create window: " << SDL_GetError() << std::endl;
        return 1;
    }

    if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG))
    {
        std::cout << "Could not create window: " << IMG_GetError() << std::endl;
        return 1;
    }

    SDL_Event windowEvent;

    imageSurface = IMG_Load("backgrtest.png");

    if (NULL == imageSurface)
    {
        std::cout << "SDL could not load image! SDL Error: " << SDL_GetError() << std::endl;
    }

    while (true)
    {
        if (SDL_PollEvent(&windowEvent))
        {
            if (SDL_QUIT == windowEvent.type)
            {
                break;
            }
        }

        SDL_BlitSurface(imageSurface, NULL, windowSurface, NULL);

        SDL_UpdateWindowSurface(window);
    }

    SDL_FreeSurface(imageSurface);
    SDL_FreeSurface(windowSurface);

    imageSurface = NULL;
    windowSurface = NULL;

    SDL_DestroyWindow(window);
    SDL_Quit();

    return EXIT_SUCCESS;
}