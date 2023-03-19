#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>
#include "Player.hpp"

class Game {
    public:
        Game();
        ~Game();

        void run();
        void draw();
        void update(double delta_time);
        int get_screen_width();
        int get_screen_height();

    private:
        bool isRunning;
        Player player;

        SDL_Window *window;
        SDL_Surface *window_surface;
        SDL_Event event;

        const int SCREEN_WIDTH = 680;
        const int SCREEN_HEIGHT = 480;
};

#endif
