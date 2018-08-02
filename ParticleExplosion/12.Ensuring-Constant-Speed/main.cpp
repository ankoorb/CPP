#include <iostream>
#include <SDL2/SDL.h>
#include "Screen.h"
#include "Swarm.h"

using namespace std;
using namespace explosion;

int main() {

    srand(time(NULL));

    Screen screen;

    if(screen.init() == false) {
        cout << "Error initializing SDL." << endl;
    }

    Swarm swarm;

    // Program
    while(true) {
        // Update particles

        // Draw particles: We are re-drawing the screen many times per second -> Inefficient
        int elapsed = SDL_GetTicks();

        screen.clear();  // Commenting and running gives cool
        swarm.update(elapsed);

        unsigned char blue = (unsigned char)((1 + sin(elapsed * 0.001)) * 128);
        unsigned char green = (unsigned char)((1 + sin(elapsed * 0.002)) * 128);
        unsigned char red = (unsigned char)((1 + sin(elapsed * 0.003)) * 128);

        const Particle * const pParticles = swarm.getParticles();  // const pointer to Particle is const

        for(int i=0; i<Swarm::nParticles; i++) {
            Particle particle = pParticles[i];

            // Mapping particle space
            int x = (particle.m_x + 1) * Screen::SCREEN_WIDTH/2;
            int y = particle.m_y  * Screen::SCREEN_WIDTH/2 + Screen::SCREEN_HEIGHT/2;

            screen.setPixel(x, y, red, green, blue);
        }

        // Draw the screen
        screen.update();

        // Check of messages/events
        if(screen.processEvents() == false) {
            break;
        }
    }

    screen.close();

    return 0;
}