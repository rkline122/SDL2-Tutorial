#include "headers/Spritesheet.hpp"

Spritesheet::Spritesheet(char const *path, int row, int column){
    spritesheet_image = load_bmp(path);

    if (spritesheet_image) {
        clip.w = spritesheet_image->w / column;
        clip.h = spritesheet_image->h / row;
    } else {
        clip.w = 0;
        clip.h = 0;
    }
}

Spritesheet::~Spritesheet(){
    if (spritesheet_image) {
        SDL_FreeSurface(spritesheet_image);
    }
}

void Spritesheet::select_sprite(int x, int y){
    if (spritesheet_image) {
        clip.x = x * clip.w;
        clip.y = y * clip.h;
    }
}

void Spritesheet::draw_selected_sprite(SDL_Surface *window_surface, SDL_Rect *position){
    if (spritesheet_image) {
            SDL_BlitSurface(spritesheet_image, &clip, window_surface, position);
    }
}