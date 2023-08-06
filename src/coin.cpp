#include "coin.h"
#include <iostream>

using namespace std;

coin::coin( Window& window) : Window(window) {
    spawn = true;
    w = 30;
    h = 30;
    SDL_Surface *loadedSurface = SDL_LoadBMP("resources/gold.bmp");
    coinTexture = SDL_CreateTextureFromSurface(_renderer, loadedSurface);
    SDL_FreeSurface(loadedSurface);
}

coin::~coin() {
    SDL_DestroyTexture(coinTexture);
}

void coin::draw(float cx, float cy, Window& window, SDL_Rect& d) {
    x = cx + window._x;
    y = cy;
    w = 30;
    h = 30;
    if (SDL_HasIntersection(this, &d)){
        if(spawn) window.addscore();
        spawn = false;
    }
    if (spawn) {
        SDL_RenderCopy(_renderer, coinTexture, NULL, this);
    }
}

