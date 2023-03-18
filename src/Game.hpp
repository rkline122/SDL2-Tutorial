#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>

class Game {
    public:
        // Constructor/Destructor
        Game();
        ~Game();

        // Variables
        double image_x;
        double image_y;

        // Methods
        bool Init();
        void Run();
        void Draw();
        void Clean();
        void update(double delta_time);

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
