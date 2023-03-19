#ifndef PLAYER_H
#define PLAYER_H

#include <SDL2/SDL.h>
#include "Spritesheet.hpp"

class Player{

    public:

        enum class Direction{
            NONE,
            UP,
            DOWN,
            LEFT,
            RIGHT,
        };

        Player();
        ~Player() = default;

        void update(double delta_time, int screen_width, int screen_height);
        void draw(SDL_Surface *window_surface);
        void handle_events(SDL_Event const &event);

    private:

        Spritesheet  spritesheet;
        int          spritesheet_column;
        Direction    direction;

        SDL_Rect     sprite;
        double       position_x;
        double       position_y;
};

#endif