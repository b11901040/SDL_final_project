#pragma once
#include <SDL2/SDL.h>
#include "window.h"

class obstacle: public SDL_Rect, public Window {
    SDL_Texture *obstacleTexture = nullptr;
public:
    explicit obstacle(Window& window);
    ~obstacle();
    void draw(float ox, Window& window, float oy=0);
};