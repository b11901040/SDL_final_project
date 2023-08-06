#include "dinosaur.h"
#include <iostream>

using namespace std;


dinosaur::dinosaur(Window& window) : Window(window) {
    SDL_Surface *loadedSurface = SDL_LoadBMP("resources/dinosaur.bmp");
    dinoTexture = SDL_CreateTextureFromSurface(_renderer, loadedSurface);
    if (!dinoTexture) cout << "Failed to create dino";
    SDL_FreeSurface(loadedSurface);
}

dinosaur::~dinosaur() {
    SDL_DestroyTexture(dinoTexture);
}

void dinosaur::draw(Window& window) {
    x = 100;
    y = window._y - 70;
    w = 40;
    h = 80;
    SDL_RenderCopy(_renderer, dinoTexture, NULL, this);
}


