#pragma once
#include <SDL2/SDL.h>
#include "window.h"

class dinosaur: public SDL_Rect, public Window{
    SDL_Texture *dinoTexture = nullptr;
public:
    explicit dinosaur(Window&);
    ~dinosaur();
    void draw (Window&);
};