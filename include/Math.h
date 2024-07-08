#pragma once

#include <iostream>

struct Vec2f
{
    Vec2f()
    :x(0.0f), y(0.0f)
    {}

    Vec2f(float p_x, float p_y)
    :x(p_x), y(p_y)
    {}
    float x, y;

    void print()
    {
        std::cout << x << ", " << y << std::endl;
    }

};