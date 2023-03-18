#include "headers/Player.hpp"
#include "headers/helpers.hpp"
#include "headers/Game.hpp"
#include <iostream>

Player::Player(){
    image = load_surface("src/Untitled.bmp");
    
    sprite.x = 0;
    sprite.y = 0;
    sprite.w = 64;
    sprite.h = 64;

    position_x = 0.0;
    position_y = 0.0;
}

void Player::update(double delta_time, int screen_width, int screen_height){
    switch(direction){

        case Direction::NONE:
            position_x += 0.0;
            position_y += 0.0;
            break;
        case Direction::UP:
            if(position_y > 0)
                position_y = position_y - (5.0 * delta_time);
            break;
        case Direction::DOWN:
            if(position_y < screen_height - sprite.h)
                position_y = position_y + (5.0 * delta_time);
            break;
        case Direction::LEFT:
            if(position_x > 0)
                position_x = position_x - (5.0 * delta_time);
            break;
        case Direction::RIGHT:
            if(position_x < screen_width - sprite.w)
                position_x = position_x + (5.0 * delta_time);
            break;
    }

    sprite.x = position_x;
    sprite.y = position_y;    
}

void Player::draw(SDL_Surface *window_surface){
    SDL_BlitSurface(image, nullptr, window_surface, &sprite);
}

void Player::handle_events(SDL_Event const &event){

    switch(event.type){
        case SDL_KEYDOWN:{
            Uint8 const *keys = SDL_GetKeyboardState(nullptr);

            if(keys[SDL_SCANCODE_W] == 1)
                direction = Direction::UP;
            else if(keys[SDL_SCANCODE_S] == 1)
                direction = Direction::DOWN;
            else if(keys[SDL_SCANCODE_A] == 1)
                direction = Direction::LEFT;
            else if(keys[SDL_SCANCODE_D] == 1)
                direction = Direction::RIGHT;
            break;
        }
            
        case SDL_KEYUP:
            direction = Direction::NONE;
            break;
        
    }
}