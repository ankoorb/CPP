#include <iostream>
#include <SDL2/SDL.h>
#include <math.h>  // For using trignometric function to change color
#include <time.h>  // time
#include "Screen.h"
#include "Swarm.h"

using namespace std;
using namespace explosion;

// Check SDL API Documentation using Google when coding

int main() {

    srand(time(NULL));

    Screen screen;

    if(screen.init() == false) {
        cout << "Error initializing SDL." << endl;
    }

    Swarm swarm;

    // Program or game loop
    while(true) {
        // Update particles

        // Draw particles
        int elapsed = SDL_GetTicks();

        unsigned char blue = (unsigned char)(1 + sin(elapsed * 0.001)) * 128;
        unsigned char green = (unsigned char)(1 + sin(elapsed * 0.002)) * 128;
        unsigned char red = (unsigned char)(1 + sin(elapsed * 0.003)) * 128;

        const Particle * const pParticles = swarm.getParticles();  // const pointer to Particle is const
        for(int i=0; i<Swarm::nParticles; i++) {
            Particle particle = pParticles[i];

            // Mapping particle space
            int x = (particle.m_x + 1) * Screen::SCREEN_WIDTH/2;
            int y = (particle.m_y + 1) * Screen::SCREEN_HEIGHT/2;

            screen.setPixel(x, y, blue, green, red);
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