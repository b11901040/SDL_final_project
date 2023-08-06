#pragma once
#include <SDL2/SDL.h>
#include "window.h"

class coin: public SDL_Rect, public Window {
    SDL_Texture *coinTexture = nullptr;
    bool spawn;
public:
    inline void respawn() { spawn = true;}
    coin(Window&);
    ~coin();
    void draw(float , float, Window&, SDL_Rect&);
};