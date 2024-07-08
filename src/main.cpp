#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_render.h>
#include <iostream>
#include <vector>

#include "RenderWindow.h"
#include "entity.h"

std::vector<Entity> createPlatform(SDL_Texture* grassTexture)
{
    int plat_x = 0;
    int plat_y = 688;

    std::vector<Entity> platform = { Entity(Vec2f(plat_x, plat_y), grassTexture) };

    while (plat_x <= 1248)
    {
        plat_x += 32;

        platform.emplace_back(Vec2f(plat_x, plat_y), grassTexture);
    }

    return platform;
}

int main(int argc, char* args[])
{
    if (SDL_Init(SDL_INIT_VIDEO) > 0) // sdl init error
    {
        std::cout << "SDL_Init failed..." << SDL_GetError() << std::endl;
    }

    if (!(IMG_Init(IMG_INIT_PNG))) // image init error
    {
        std::cout << "IMG_Init failed..." << SDL_GetError() << std::endl;
    }

    RenderWindow window("SDL Game v0.1", 1280, 720);

    SDL_Texture* grassTexture = window.loadTexture("res/gfx/ground_grass_1.png"); // grass texture

    bool isRunning = true;

    SDL_Event event;

    while (isRunning)
    {
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
                case SDL_QUIT: // you have a brain
                    isRunning = false;
                    break;

                case SDL_KEYDOWN: // press escape to close window
                    if (event.key.keysym.sym == SDLK_ESCAPE)
                    {
                        isRunning = false;
                    }
            }
        }

        window.clear(); // clear screen

        for (Entity& i : createPlatform(grassTexture))
        {
            window.render(i);
        }
        window.display(); // display rendered texture
    }

    window.cleanUp(); // destroy window
    SDL_Quit();
    
    return 0;
}

