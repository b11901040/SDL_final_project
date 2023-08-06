#pragma once
#include <SDL2/SDL.h>
#include "window.h"

class rock: public SDL_Rect, public Window {
    SDL_Texture *rockTexture = nullptr;
public:
    explicit rock(Window&);
    ~rock();
    void draw (float rx, Window&, float ry = 0);
};
