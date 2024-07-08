#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

#include "RenderWindow.h"

RenderWindow::RenderWindow(const char* p_title, int p_w, int p_h)
    :window(NULL), renderer(NULL)
{
    window = (SDL_CreateWindow(p_title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, p_w, p_h, SDL_WINDOW_SHOWN));

    if (window == NULL)
    {
        std::cout << "Window failed to init. Error:" << SDL_GetError << std::endl;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}

SDL_Texture* RenderWindow::loadTexture(const char* p_filePath)
{
    SDL_Texture* texture = NULL;
    texture = IMG_LoadTexture(renderer, p_filePath);

    if (texture == NULL)
    {
        std::cout << "Failed to load texture. Error:" << SDL_GetError << std::endl;

    }

    return texture;
}

void RenderWindow::cleanUp()
{
    SDL_DestroyWindow(window);
}

void RenderWindow::clear()
{
    SDL_RenderClear(renderer);
}

void RenderWindow::render(SDL_Texture* p_tex)
{
    SDL_Rect src;
    src.x = 0;
    src.y = 0;
    src.w = 32;
    src.h = 32;

    SDL_Rect dest;
    dest.x = 640;
    dest.y = 320;
    dest.w = 32;
    dest.h = 32;

    SDL_RenderCopy(renderer, p_tex, &src, &dest);
}

void RenderWindow::display()
{
    SDL_RenderPresent(renderer);
}