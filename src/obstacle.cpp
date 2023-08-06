#include <SDL2/SDL.h>
#include "obstacle.h"
#include <iostream>

using namespace std;

obstacle::obstacle(Window& window) : Window(window) {
    SDL_Surface *loadedSurface = SDL_LoadBMP("resources/obstacle.bmp");
    obstacleTexture = SDL_CreateTextureFromSurface(_renderer, loadedSurface);
    if (!obstacleTexture) cout << "Failed to create obstacle";
    SDL_FreeSurface(loadedSurface);
}

obstacle::~obstacle() {
    SDL_DestroyTexture(obstacleTexture);
}

void obstacle::draw(float ox, Window& window, float oy) {
    x = ox + window._x;
    y = 560 - oy;
    w = 30;
    h = 80;
    SDL_RenderCopy(_renderer, obstacleTexture, nullptr, this);
}