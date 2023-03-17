#include "Game.hpp"
#include "helpers.hpp"

Game::Game() :
    isRunning(false),
    window(nullptr)
{}

Game::~Game(){
    
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
            688, 
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

        SDL_Event event;
        while (SDL_PollEvent(&event) > 0) {
            switch(event.type){
                case SDL_QUIT:
                    isRunning = false;
                    break;
            }
        }

        Draw();
    }
}

void Game::Draw(){
    SDL_BlitSurface(image, NULL, window_surface, NULL);
    SDL_UpdateWindowSurface(window);
}


void Game::Clean(){
    SDL_FreeSurface(window_surface);
    SDL_FreeSurface(image);
    SDL_DestroyWindow(window);
    SDL_Quit();
}
