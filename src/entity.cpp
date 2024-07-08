#include "entity.h"

Entity::Entity(Vec2f p_pos, SDL_Texture* p_tex)
:pos(p_pos), texture(p_tex)
{
    frame.x = 0;
    frame.y = 0;
    frame.w = 32;
    frame.h = 32;
}

SDL_Texture* Entity::getTex()
{
    return texture;
}

SDL_Rect Entity::getCurrentFrame()
{
    return frame;
}