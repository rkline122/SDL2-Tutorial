#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>

class Game {
    public:
        Game();
        ~Game();

        bool Init();
        void Run();
        void Draw();
        void Clean();

    private:
        bool isRunning;

        SDL_Surface *image;
        SDL_Rect    image_position;

        SDL_Window *window;
        SDL_Surface *window_surface;
        SDL_Event event;

        const int SCREEN_WIDTH = 680;
        const int SCREEN_HEIGHT = 480;
};

#endif
