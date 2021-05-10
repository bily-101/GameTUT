//
// Created by bily101 on 5/9/21.
//

#include <iostream>
#include <SDL2/SDL.h>

using namespace std;

int main() {

    const int SCREEN_WIDTH = 800;
    const int SCREEN_HEIGHT = 600;

    if(SDL_Init(SDL_INIT_VIDEO) < 0) {
        cout << "SDL init failed." << endl;
        return 1;
    }

    //Creating the window
    SDL_Window *window = SDL_CreateWindow("Particle Fire Explosion", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                                          SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_OPENGL);
    // Checking if window works
    if(window == NULL) {
        SDL_Quit();
        return 2;
    }

    // Setting Renderer and texture
    SDL_Renderer * renderer = SDL_CreateRenderer(window, -1 , SDL_RENDERER_PRESENTVSYNC);
    SDL_Texture *texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888
                                             ,SDL_TEXTUREACCESS_STATIC, SCREEN_WIDTH,SCREEN_HEIGHT);


    // Checking Renderer and Texture
    if(renderer == NULL) {
        cout << "Renderer Broken" << endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 3;
    }
    if(texture == NULL) {
        cout << "Texture Broken" << endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
        SDL_DestroyRenderer(renderer);
        return 4;
    }
    // Buffering memory
    Uint32 *buffer = new Uint32[SCREEN_WIDTH * SCREEN_HEIGHT];


    // Setting up memory

    memset(buffer, 0, SCREEN_WIDTH * SCREEN_HEIGHT *sizeof(Uint32));


    // Creating pixel
    buffer[30000] = 0xf50000;

    for(int i = 0; i<SCREEN_WIDTH*SCREEN_HEIGHT; i++) {
        buffer[i] = 0xf50000;
    }
    for(int i = 0; i<SCREEN_WIDTH*SCREEN_HEIGHT/2; i++) {
        buffer[i] = 0x000FFFF;
    }
    // Updating and setting event and quit values

    bool quit = false;
    SDL_Event event;

    SDL_UpdateTexture(texture, NULL, buffer, SCREEN_WIDTH * sizeof(Uint32));
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, texture, NULL, NULL);
    SDL_RenderPresent(renderer);

    // Main Game loop

    while (!quit) {


        // Check for quit && Quit
        while(SDL_PollEvent(&event)) {
            if(event.type == SDL_QUIT) {
                quit = true;
            }
        }
    }


    // Cleaning up
    delete [] buffer;
    SDL_DestroyRenderer(renderer);
    SDL_DestroyTexture(texture);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}