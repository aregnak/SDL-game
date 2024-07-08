#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Math.h"

class Entity
{
public:
    Entity(Vec2f p_pos, SDL_Texture* p_tex);

    Vec2f& getPos()
    {
        return pos;
    }
    SDL_Texture* getTex();
    SDL_Rect getCurrentFrame();
    
private:
    Vec2f pos;

    SDL_Rect frame;
    SDL_Texture* texture;
};