#include "rock.h"
#include <iostream>

using namespace std;

rock::rock(Window& window) : Window(window) {
    SDL_Surface *loadedSurface = SDL_LoadBMP("resources/rock.bmp");
    rockTexture = SDL_CreateTextureFromSurface(_renderer, loadedSurface);
    if (!rockTexture) cout << "Failed to create rock";
    SDL_FreeSurface(loadedSurface);
}

rock::~rock() {
    SDL_DestroyTexture(rockTexture);
}

void rock::draw(float rx, Window& window, float ry) {
    x = rx + window._x;
    y = 550 - ry;
    w = 90;
    h = 90;
    SDL_RenderCopy(_renderer, rockTexture, NULL, this);
}

