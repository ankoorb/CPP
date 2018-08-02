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

        // Check of messages/events
        if(screen.processEvents() == false) {
            break;
        }
    }

    return 0;
}