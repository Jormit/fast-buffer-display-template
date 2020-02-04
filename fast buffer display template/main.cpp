#include <cstdio>
#include <cstdint>
#include <iostream>
#include <SDL2/SDL.h>
using namespace std;

#define SCREEN_WIDTH 1000
#define SCREEN_HEIGHT 400

//SDL.
SDL_Event event; //Create Event Handler.
SDL_Renderer *renderer; //Create Renderer.
SDL_Window *window; //Create Window.
SDL_Texture *texture; //Create a texture to store framebuffer.

// Create frame buffer.
struct RGB {
    uint8_t red;
    uint8_t green;
    uint8_t blue;
} frameBuffer[400000];

void init_sdl ();
void update_screen ();


int main(int argv, char** args){
    init_sdl();

    int running = 1;

    while (running) {
        update_screen ();
        while(SDL_PollEvent( &event )) {
            if (SDL_PollEvent(&event) && event.type == SDL_QUIT){ //If close button pressed.
                running = 0;
            }
        }
    }
}

void init_sdl (){
    //Start SDL.
    SDL_Init( SDL_INIT_VIDEO );

    //Initialize the window and renderer.
    SDL_CreateWindowAndRenderer(SCREEN_WIDTH, SCREEN_HEIGHT, 0, &window, &renderer);

    SDL_RenderSetLogicalSize(renderer, SCREEN_WIDTH, SCREEN_HEIGHT);

    //Create Texture for buffering.
    texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGB24,SDL_TEXTUREACCESS_STREAMING, SCREEN_WIDTH, SCREEN_HEIGHT);

    //Set the render Draw Color to White.
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

    //Clear Screen (White).
    SDL_RenderClear(renderer);

    //Display on screen.
    SDL_RenderPresent(renderer);
}

void update_screen (){
    for (long i = 0; i < 400000; i++) {
        frameBuffer[i].red = (float)(i % 1000)/1000.0f * 255;
        frameBuffer[i].green = (float)(i/1000 % 400)/400.0f * 255;
        frameBuffer[i].blue = (float)(1000 - (i % 1000))/1000.0f * 255;
    }

    SDL_Delay(15); //Wait for 15 milliseconds.
    SDL_UpdateTexture(texture, NULL, frameBuffer, SCREEN_WIDTH * sizeof(uint8_t) * 3);
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, texture, NULL, NULL);
    SDL_RenderPresent(renderer);
}