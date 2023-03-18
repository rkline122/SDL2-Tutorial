#include "Game.hpp"
#include "helpers.hpp"

Game::Game() : isRunning(false), window(nullptr){
    image_position.x = 0;
    image_position.y = 0;
    image_position.w = 64;
    image_position.h = 64;
    image_x = 0.0;
    image_y = 0.0;
}

Game::~Game(){
    SDL_FreeSurface(window_surface);
    SDL_FreeSurface(image);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

bool Game::Init(){
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        SDL_Log("Failed to initialize SDL: %s", SDL_GetError());
        return false;
    }

    window = SDL_CreateWindow(
            "SDL2 Test", 
            SDL_WINDOWPOS_CENTERED, 
            SDL_WINDOWPOS_CENTERED, 
            SCREEN_WIDTH, 
            SCREEN_HEIGHT, 
            0
        );
    if (!window) {
        SDL_Log("Failed to create window: %s", SDL_GetError());
        return false;
    }

    window_surface = SDL_GetWindowSurface(window);
    if (!window_surface) {
        SDL_Log("Failed to get the surface from the window: %s", SDL_GetError());
        return false;
    }

    image = load_surface("src/Untitled.bmp");

    isRunning = true;
    return true;
}

void Game::Run(){
    while (isRunning) {
        while (SDL_PollEvent(&event) > 0) {
            switch(event.type){
                case SDL_QUIT:
                    isRunning = false;
                    break;
            }
        }

        update(1.0/60.0);
        Draw();
    }
}

void Game::Draw(){
    SDL_FillRect(window_surface, NULL, SDL_MapRGB(window_surface->format, 255, 255, 255));
    SDL_BlitSurface(image, NULL, window_surface, &image_position);
    SDL_UpdateWindowSurface(window);
}

void Game::update(double delta_time){
    image_x = image_x + (5 * delta_time);
    image_position.x = image_x;
}
