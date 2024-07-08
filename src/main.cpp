#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <vector>

#include "RenderWindow.h"
#include "entity.h"
#include "utils.h"


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

    std::vector<Entity> entities = {Entity(Vec2f(0, 0), grassTexture),
                                    Entity(Vec2f(32, 32), grassTexture),
                                    Entity(Vec2f(64, 64), grassTexture)};

    bool isRunning = true;

    SDL_Event event;

    const float timestep = 0.1f;
    float accumulator = 0.0f;
    float currentTime = utils::hireTime();

    while (isRunning)
    {
        int startTick = SDL_GetTicks64();

        float newTime = utils::hireTime();
        float frameTime = newTime - currentTime;

        currentTime = newTime;

        accumulator += frameTime;

        while (accumulator >= timestep)
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

            accumulator -= timestep;
        }
        
        const float alpha = accumulator / timestep;

        window.clear(); // clear screen

        for (Entity& i : entities)
        {
            window.render(i);
        }
        window.display(); // display rendered texture

        int frameTicks = SDL_GetTicks64() - startTick;

        if (frameTicks < window.getRefRate())
        {  
            SDL_Delay(1000 / window.getRefRate() - frameTicks);
        }
    }

    window.cleanUp(); // destroy window
    SDL_Quit();
    
    return 0;
}

