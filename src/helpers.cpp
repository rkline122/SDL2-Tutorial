#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "headers/helpers.hpp"
#include "iostream"

SDL_Surface *load_image(char const *path)
{
    int flags = IMG_INIT_PNG | IMG_INIT_JPG;
    int initiated_flags = IMG_Init(flags);

    if((initiated_flags & flags) != flags)
    {
        std::cout << "Failed to initialize all image loaders\n";
        std::cout << "IMG Error: " << IMG_GetError() << "\n";
    }

    SDL_Surface *image_surface = IMG_Load(path);

    if(!image_surface)
    {
        std::cout << "Failed to open image\n";
        std::cout << "IMG Error: " << IMG_GetError() << "\n";
    }

    return image_surface;
}

