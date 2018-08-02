#include <iostream>
#include <SDL2/SDL.h>
#include <math.h>  // For using trignometric function to change color
#include "Screen.h"

using namespace std;
using namespace explosion;

// Check SDL API Documentation using Google when coding

int main() {

    Screen screen;

    if(screen.init() == false) {
        cout << "Error initializing SDL." << endl;
    }


    // Program or game loop
    while(true) {
        // Update particles

        // Draw particles
        int elapsed = SDL_GetTicks();
        //double green = (1 + sin(elapsed * 0.001)) * 128;
        //double green = (1 + sin(M_PI/2)) * 128;

        // unsigned char max is 255 so it restricts values more than 255
        //unsigned char green = (1 + sin(elapsed * 0.001)) * 128;

        unsigned char blue = (unsigned char)(1 + sin(elapsed * 0.001)) * 128;
        unsigned char green = (unsigned char)(1 + sin(elapsed * 0.002)) * 128;
        unsigned char red = (unsigned char)(1 + sin(elapsed * 0.003)) * 128;

        for(int y=0; y < Screen::SCREEN_HEIGHT; y++) {
            for(int x=0; x < Screen::SCREEN_WIDTH; x++) {
                screen.setPixel(x, y, blue, green, red);  // blue, green, red
            }
        }

        //cout << elapsed << " --> " << green << endl;

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