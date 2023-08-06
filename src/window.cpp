#include "window.h"
#include <SDL2/SDL.h>
#include <iostream>
#include "SDL_ttf.h"

using namespace std;

Window::Window(): width(852), height(640), closed(false), vx(5), vy(0), dead(false), score(0) {
    closed = !init();
}

Window::~Window() {
    SDL_DestroyRenderer(_renderer);
    SDL_DestroyWindow(_window);
    SDL_Quit();
}

bool Window::init() {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        cout << "failed to init";
        return false;
    }
    _window = SDL_CreateWindow("game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height,SDL_WINDOW_SHOWN);

    if (!_window) {
        cout << "failed window";
        return false;
    }

    _renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if(_renderer == nullptr) {
        cout << "failed _renderer";
        return false;
    }
    SDL_Surface *startSurface = SDL_LoadBMP("resources/start.bmp");
    SDL_Texture *startTexture = SDL_CreateTextureFromSurface(_renderer, startSurface);
    SDL_RenderCopy(_renderer, startTexture, NULL, NULL);
    SDL_RenderPresent(_renderer);
    while (true) {
        if (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) {
                break;
            } else if (e.type == SDL_KEYDOWN) {
                break;
            }
        }
    }
    return true;
}

void Window::pollEvent() {
    while (SDL_PollEvent(&e)) {
        if (e.type == SDL_QUIT) {
            closed = true;
        } else if (e.type == SDL_KEYDOWN ) {
            switch (e.key.keysym.sym) {
                case SDLK_UP:
                    if(!dead && (_y == 630 || _y == 541)){
                        vy = -15;
                        _y -= 15;
                    }
                    break;

                case SDLK_RIGHT:
                    vx = 5;
                    break;
            }
        }
    }

}

void Window::clear() const {
    SDL_Texture *backgroundTexture = NULL;
    SDL_Surface *loadedSurface = NULL;
    loadedSurface = SDL_LoadBMP("resources/background.bmp");
    backgroundTexture = SDL_CreateTextureFromSurface(_renderer, loadedSurface);
    SDL_RenderCopy(_renderer, backgroundTexture, NULL, NULL);
    SDL_RenderCopy(_renderer, text_texture, NULL, &text_rect);
    SDL_FreeSurface(loadedSurface);
}

void Window::render() const {
    SDL_RenderPresent(_renderer);
}

void Window::motion() {
    _x -= vx;
    _y += vy;
    vy += gravity;

    if (_y >= 630) {
        vy = 0;
        _y = 630;
    }
}

void Window::collisionrock(SDL_Rect* r, SDL_Rect* d) {
    if (SDL_HasIntersection(r, d)){
        if(r->x >= 135 && _y > 545) {
            _x += 10;
            vx = 0;
            vy = 0;
            dead = true;
        }
        else {
            if(_y > 540) _y = 541;
        }
    }
}

void Window::collisionobstacle(SDL_Rect* o, SDL_Rect* d) {
    if (SDL_HasIntersection(o, d)) {
        dead = true;
        if (o->x >= 135) _x += 10;
        vx = 0;
        vy = 0;
    }
}


void Window::gameEnd() {
    SDL_DestroyTexture(text_texture);
    SDL_FreeSurface(text_surface);
    TTF_CloseFont(font);
    TTF_Quit();
    if (!dead && _x > -10000) {
        return;
    }
    SDL_Surface *gameOverSurface;
    if (dead) gameOverSurface = SDL_LoadBMP("resources/dead.bmp");
    else gameOverSurface = SDL_LoadBMP("resources/win.bmp");
    SDL_Texture *gameOverTexture = SDL_CreateTextureFromSurface(_renderer, gameOverSurface);
    SDL_RenderCopy(_renderer, gameOverTexture, NULL, NULL);
    SDL_RenderPresent(_renderer);
    while (true) {
        if (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) {
                closed = true;
                break;
            } else if (e.type == SDL_KEYDOWN) {
                _x = 160;
                dead = false;
                vx = 5;
                vy = 0;
                score = 0;
                break;
            }
        }
    }
}

void Window::renderScore() {
    TTF_Init();
    font = TTF_OpenFont("resources/square.ttf", 24);
    // Convert the number to a string
    char number_str[16] = {'s','c','o','r','e',':', ' ',char('0'+(score-score%10)/10),char('0'+score%10), '/', '1', '0', '0', ' '};
    // Render the number as a SDL_Surface
    SDL_Color black = {0, 0, 0};
    text_surface = TTF_RenderText_Solid(font, number_str, black);
    text_texture = SDL_CreateTextureFromSurface(_renderer, text_surface);
    text_rect.x = 300;
    text_rect.y = 10;
    text_rect.w = 300;
    text_rect.h = 60;
}
































