#ifndef SPRITESHEET_H
#define SPRITESHEET_H

#include <SDL2/SDL.h>
#include "helpers.hpp"

class Spritesheet{
    public:
        Spritesheet(char const *path, int row, int column);
        ~Spritesheet();

        void select_sprite(int x, int y);
        void draw_selected_sprite(SDL_Surface *window_surface, SDL_Rect *position);

    private:
        SDL_Rect     clip;
        SDL_Surface *spritesheet_image;

        int start_x;
        int start_y;
};

#endif