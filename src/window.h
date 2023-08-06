#pragma once
#include <SDL2/SDL.h>
#include "SDL_ttf.h"


class Window {
    int width, height;
    bool closed;
    SDL_Window *_window = nullptr;
    const float gravity = 0.8;
    float vx, vy;
    SDL_Event e;
    bool dead;
    TTF_Font* font;
    SDL_Texture* text_texture;
    SDL_Rect text_rect;
    SDL_Surface* text_surface;
    int score;
public:
    float _x = 160, _y = 630;
    inline void addscore() {score++;}
    Window();
    ~Window();
    inline bool isClosed() const { return closed; }
    inline bool isDead() const { return dead; }
    bool init();
    void pollEvent();
    void clear() const;
    void render() const;
    void motion();
    void collisionrock(SDL_Rect*, SDL_Rect*);
    void collisionobstacle(SDL_Rect*, SDL_Rect*);
    void gameEnd();
    void renderScore();
protected:
    SDL_Renderer *_renderer = nullptr;
};
