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

    // Renderer and Texture
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);
    SDL_Texture *texture = SDL_CreateTexture(renderer,
                                             SDL_PIXELFORMAT_ABGR8888,  // R, G, B, Alpha
                                             SDL_TEXTUREACCESS_STATIC,
                                             SCREEN_WIDTH,
                                             SCREEN_HEIGHT);

    if(renderer == NULL) {
        cout << "Could not create renderer" << endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 3;
    }

    if(texture == NULL) {
        cout << "Could not create texture" << endl;
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 4;
    }

    // Allocate memory for pixels on the screen (every pixel -> 4 bytes for R, G, B, Alpha)
    // Uint32: Type declared by SDL
    Uint32 *buffer = new Uint32[SCREEN_WIDTH * SCREEN_HEIGHT];  // Window area


    // Writing pixel information into buffer
    /*
     * IMPORTANT Function: memset - Allows to set a block of memory with a particular value
     */
    memset(buffer, 0, SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(Uint32));  // 0x Prefix -> Hexadecimal in C++

    // Setting an individual pixel color
    // Max index in the array is (SCREEN_WIDTH * SCREEN_HEIGHT - 1)
    buffer[30000] = 0xFFFFFFFF;  // FF -> Sets 1 byte for R, FFFF -> Sets 2 bytes for R and G, and so on

    // Setting pixel color for the whole window screen
    for (int i=0; i<SCREEN_WIDTH * SCREEN_HEIGHT; i++) {
        buffer[i] = 0x000000FF;  // alpha, blue, green, red
    }


    // 1. Updating texture
    SDL_UpdateTexture(texture, NULL, buffer, SCREEN_WIDTH * sizeof(Uint32));

    // 2. Clear renderer
    SDL_RenderClear(renderer);

    // 3. Copy texture to the renderer
    SDL_RenderCopy(renderer, texture, NULL, NULL);

    // 4. Rendering
    SDL_RenderPresent(renderer);

    // Program or game loop
    bool quit = false;
    SDL_Event event;

    while(!quit) {
        // Update particles
        // Draw particles
        // Check of messages/events

        while(SDL_PollEvent(&event)) {  // Checking multiple events, e.g. User closing window
            if(event.type == SDL_QUIT) {
                quit = true;
            }
        }
    }


    // De-allocate memory
    delete [] buffer;

    // Destroy Renderer and Texture
    SDL_DestroyTexture(texture);  // Destroy first as texture is using renderer
    SDL_DestroyRenderer(renderer);

    // Close and destroy the window
    SDL_DestroyWindow(window);

    // Clean up resources that SDL is using
    SDL_Quit();

    return 0;
}