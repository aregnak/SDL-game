#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_timer.h>
#include <iostream>
#include <vector>

#include "RenderWindow.h"
#include "entity.h"

#define SW 1280
#define SH 720

std::vector<Entity> createPlatform(SDL_Texture* grassTexture)
{
    int plat_x = 0;
    int plat_y = 688;

    std::vector<Entity> platform = { Entity(Vec2f(plat_x, plat_y), grassTexture) };

    while (plat_x <= (SW - 32))
    {
        plat_x += 32;

        platform.emplace_back(Vec2f(plat_x, plat_y), grassTexture);
    }

    return platform;
}

int main(int argc, char* args[])
{
    const int FPS = 60;
    const int frameDelay = 1000 / FPS;

    Uint32 frameStart;
    int frameTime;

    if (SDL_Init(SDL_INIT_VIDEO) > 0) // sdl init error
    {
        std::cout << "SDL_Init failed..." << SDL_GetError() << std::endl;
    }

    if (!(IMG_Init(IMG_INIT_PNG))) // image init error
    {
        std::cout << "IMG_Init failed..." << SDL_GetError() << std::endl;
    }

    RenderWindow window("SDL Game v0.1", SW, SH);

    SDL_Texture* grassTexture = window.loadTexture("res/gfx/ground_grass_1.png"); // grass texture

    SDL_Rect playerRect = { 20, 20, 1, 1 };

    SDL_Texture* playerModel = window.loadTexture("res/gfx/player.png"); // player texture

    bool isRunning = true;

    SDL_Event event;

    while (isRunning)
    {
        while (SDL_PollEvent(&event))
        {
            frameStart = SDL_GetTicks64();

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

            switch (event.key.keysym.sym)
            {
                case SDLK_UP:
                    playerRect.y -= 5;
                    break;

                case SDLK_DOWN:
                    playerRect.y += 5;
                    break;

                case SDLK_RIGHT:
                    playerRect.x += 5;
                    break;

                case SDLK_LEFT:
                    playerRect.x -= 5;
                    break;
            }
        }

        window.clear(); // clear screen

        for (Entity& i : createPlatform(grassTexture))
        {
            window.render(i);
        }

        Entity player = Entity(Vec2f(playerRect.x, playerRect.y), playerModel);

        window.render(player);

        window.rendPlayer(playerRect);

        window.display(); // display rendered texture

        frameTime = SDL_GetTicks64() - frameStart;

        if (frameDelay > frameTime)
        {
            SDL_Delay(frameDelay - frameTime);
        }
    }

    window.cleanUp(); // destroy window
    SDL_Quit();
    
    return 0;
}

