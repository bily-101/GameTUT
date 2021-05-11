//
// Created by bily101 on 5/10/21.
//

#ifndef GAMETUT_SCREEN_H
#define GAMETUT_SCREEN_H

#include <SDL2/SDL.h>
#include <iostream>

using namespace std;


namespace GameTUT {
    class Screen {
    public:
        static const int SCREEN_WIDTH = 800;
        static const int SCREEN_HEIGHT = 600;

    private:
        SDL_Window *m_window;
        SDL_Renderer *m_renderer;
        SDL_Texture *m_texture;
        Uint32 *m_buffer;
    public:
        Screen();

        bool init();

        bool processEvents();

        void setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue);

        void close();

        void update();

        void clear();
    };
};

#endif //GAMETUT_SCREEN_H
