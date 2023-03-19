#include "SDL2/SDL.h"
#include "headers/helpers.hpp"
#include "iostream"

SDL_Surface* load_bmp(char const *path){
    
    SDL_Surface *image_surface = SDL_LoadBMP(path);

    if(!image_surface){
        SDL_Log("Failed to load image: %s", SDL_GetError());
        SDL_FreeSurface(image_surface);        
        return nullptr;
    }


    return image_surface;
}
