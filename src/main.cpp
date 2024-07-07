#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

#include "RenderWindow.h"

int main(int argc, char* args[])
{
    if (SDL_Init(SDL_INIT_VIDEO) > 0)
    {
        std::cout << "SDL_Init failed..." << SDL_GetError() << std::endl;
    }

    if (!(IMG_Init(IMG_INIT_PNG)))
    {
        std::cout << "IMG_Init failed..." << SDL_GetError() << std::endl;
    }

    RenderWindow window("SDL Game v0.1", 1280, 720);

    SDL_Texture* grassTexture = window.loadTexture("res/gfx/ground_grass_1.png");

    bool isRunning = true;

    SDL_Event event;

    while (isRunning)
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
                isRunning = false;
        }

        window.clear();
        window.render(grassTexture);
        window.display();
    }

    window.cleanUp();
    SDL_Quit();
    
    return 0;
}

