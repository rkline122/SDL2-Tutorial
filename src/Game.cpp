#include "headers/Game.hpp"
#include "headers/helpers.hpp"

Game::Game() : isRunning(false), window(nullptr){
    
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        SDL_Log("Failed to initialize SDL: %s", SDL_GetError());
        return;
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
        return;
    }

    window_surface = SDL_GetWindowSurface(window);
    if (!window_surface) {
        SDL_Log("Failed to get the surface from the window: %s", SDL_GetError());
        return;
    }


}

Game::~Game(){
    SDL_FreeSurface(window_surface);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void Game::run(){
    isRunning = true;
    while (isRunning) {
        while (SDL_PollEvent(&event) > 0) {
            player.handle_events(event);
            switch(event.type){
                case SDL_QUIT:
                    isRunning = false;
                    break;
            }
        }
        update(1.0/60.0);
        draw();
    }
}

void Game::draw(){
    SDL_FillRect(window_surface, NULL, SDL_MapRGB(window_surface->format, 255, 255, 255));
    player.draw(window_surface);
    SDL_UpdateWindowSurface(window);
}

void Game::update(double delta_time){
    player.update(delta_time, get_screen_width(), get_screen_height());
}

int Game::get_screen_width(){
    return SCREEN_WIDTH;
}

int Game::get_screen_height(){
    return SCREEN_HEIGHT;
}
