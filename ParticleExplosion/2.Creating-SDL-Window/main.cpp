#include <iostream>
#include <SDL2/SDL.h>

using namespace std;

// Check SDL API Documentation when coding

int main() {

    // Define window width and height
    const int SCREEN_WIDTH = 800;
    const int SCREEN_HEIGHT = 600;

    if(SDL_Init(SDL_INIT_VIDEO) < 0) {
        cout << "SDL Init failed." << endl;
        return 0;
    }

    // Create a window
    SDL_Window *window = SDL_CreateWindow("Particle Fire Explosion",  // title of window
                                          SDL_WINDOWPOS_UNDEFINED,  // x position of window
                                          SDL_WINDOWPOS_UNDEFINED,  // y position of window
                                          SCREEN_WIDTH,  // width of window
                                          SCREEN_HEIGHT,  // height of window
                                          SDL_WINDOW_SHOWN);  // flag

    // Check if window was successfully created
    if(window == NULL) {
        cout << "Could not create window: " << SDL_GetError() << endl;
        SDL_Quit();
        return 2;
    }

    // Program or game loop
    bool quit = false;
    SDL_Event event;

    while(!quit) {
        // Update particles
        // Draw particles
        // Check of messages/events

        while(SDL_PollEvent(&event)) {  // Checking multiple events
            if(event.type == SDL_QUIT) {
                quit = true;
            }
        }
    }

    // Close and destroy the window
    SDL_DestroyWindow(window);

    // Clean up resources that SDL is using
    SDL_Quit();

    return 0;
}