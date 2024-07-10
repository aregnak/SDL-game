#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "entity.h"

class RenderWindow
{
public:
    RenderWindow(const char* p_title, int p_w, int p_h);
    SDL_Texture* loadTexture(const char* p_filePath);

    int getRefRate();

    void cleanUp();
    void clear();
    void render(Entity& p_entity);
    void display();
    void rendPlayer(SDL_Rect p_playerRect);

private:
    SDL_Window* window;
    SDL_Renderer* renderer;
};