#include <iostream>
#include <SDL2/SDL.h>
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
        for(int y=0; y < Screen::SCREEN_HEIGHT; y++) {
            for(int x=0; x < Screen::SCREEN_WIDTH; x++) {
                screen.setPixel(x, y, 128, 0, 255);
            }
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