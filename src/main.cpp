//
// Created by bily101 on 5/9/21.
//

#include <iostream>
#include <SDL2/SDL.h>
#include "Screen.h"
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include "Swarm.h"

using namespace std;
using namespace GameTUT;

int main() {

    srand(time(NULL));

    Screen screen;
    if (!screen.init()) {
        cout << "Error initalising SDL." << endl;
    }

    Swarm swarm;


    while (true) {
        const Particle * const pParticles = swarm.getParticles();

        int elapsed = SDL_GetTicks();
        unsigned char green = (1 + sin(elapsed * .001)) * 128;
        unsigned char red = (1 + sin(elapsed * .002)) * 128;
        unsigned char blue = (1 + sin(elapsed * .003)) * 128;

        swarm.update(elapsed);

        screen.clear();
        for (int i = 0; i<Swarm::NPARTICLES; i++) {
            Particle particle = pParticles[i];

            int x = (particle.m_x + 1) * Screen::SCREEN_WIDTH/2;
            int y = particle.m_y * Screen::SCREEN_WIDTH/2+ Screen::SCREEN_HEIGHT/2;
            screen.setPixel(x,y, red,green,blue);

//            screen.setPixel(x-1,y, red,green,blue);
//            screen.setPixel(x+1,y, red,green,blue);
//            screen.setPixel(x+2,y, red,green,blue);
//            screen.setPixel(x+3,y, red,green,blue);
//            screen.setPixel(x+4,y, red,green,blue);

        }


//        for (int y = 0; y < Screen::SCREEN_HEIGHT; y++) {
//            for (int x = 0; x < Screen::SCREEN_WIDTH; x++) {
//                screen.setPixel(x, y, red, green, blue);
//            }
//        }


//        screen.setPixel(400, 300, 255, 255, 255);

        screen.update();
        if (!screen.processEvents()) {
            break;
        }
    }

    screen.close();

    return 0;
}