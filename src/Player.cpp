#include "headers/Player.hpp"
#include "headers/helpers.hpp"
#include "headers/Game.hpp"
#include <iostream>

int const SPRITESHEET_UP = 0;
int const SPRITESHEET_LEFT = 1;
int const SPRITESHEET_RIGHT = 2;
int const SPRITESHEET_DOWN = 3;


Player::Player()
: spritesheet("spritesheet.bmp", 4, 9)
{
    
    sprite.x = 0;
    sprite.y = 0;
    sprite.w = 48;
    sprite.h = 48;

    position_x = 0.0;
    position_y = 0.0;

    direction = Direction::NONE;

    spritesheet.select_sprite(0,0);

}

void Player::update(double delta_time, int screen_width, int screen_height){
    switch(direction){

        case Direction::NONE:
            position_x += 0.0;
            position_y += 0.0;
            spritesheet.select_sprite(0,0);
            break;
        case Direction::UP:
            if(position_y > 0){
                position_y = position_y - (MOVEMENT_SPEED * delta_time);
                spritesheet.select_sprite(spritesheet_column, SPRITESHEET_UP);
            }
            break;
        case Direction::DOWN:
            if(position_y < screen_height - sprite.h){
                position_y = position_y + (MOVEMENT_SPEED * delta_time);
                spritesheet.select_sprite(spritesheet_column, SPRITESHEET_DOWN);
            }
            break;
        case Direction::LEFT:
            if(position_x > 0){
                position_x = position_x - (MOVEMENT_SPEED * delta_time);
                spritesheet.select_sprite(spritesheet_column, SPRITESHEET_LEFT);
            }
            break;
        case Direction::RIGHT:
            if(position_x < screen_width - sprite.w){
                position_x = position_x + (MOVEMENT_SPEED * delta_time);
                spritesheet.select_sprite(spritesheet_column, SPRITESHEET_RIGHT);
            }
            break;
    }

    sprite.x = position_x;
    sprite.y = position_y;  

    spritesheet_column++;

    if(spritesheet_column > 8){
        spritesheet_column = 1;
    }  
}

void Player::draw(SDL_Surface *window_surface){
    spritesheet.draw_selected_sprite(window_surface, &sprite);
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