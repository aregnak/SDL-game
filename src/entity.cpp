#include "entity.h"

Entity::Entity(float p_x, float p_y, SDL_Texture* p_tex)
:x(p_x), y(p_y), texture(p_tex)
{
    frame.x = 0;
    frame.y = 0;
    frame.w = 32;
    frame.h = 32;
}

float Entity::getx()
{
    return x;
}

float Entity::gety()
{
    return y;
}

SDL_Texture* Entity::getTex()
{
    return texture;
}

SDL_Rect Entity::getCurrentFrame()
{
    return frame;
}