#pragma once

#include <SDL2/SDL.h>

namespace utils
{
    inline float hireTime()
    {
        float t = SDL_GetTicks64();
        t *= 0.001f;

        return t;
    }
}