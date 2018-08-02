//
// Created by Ankoor Bhagat on 7/2/18.
//

#include "Screen.h"


namespace explosion {

    Screen::Screen(): m_window(NULL), m_renderer(NULL), m_texture(NULL), m_buffer(NULL) {

    };

    bool Screen::init() {

        if(SDL_Init(SDL_INIT_VIDEO) < 0) {
            return false;
        }

        // Create a window
        m_window = SDL_CreateWindow("Particle Fire Explosion",  // title of window
                                    SDL_WINDOWPOS_UNDEFINED,  // x position of window
                                    SDL_WINDOWPOS_UNDEFINED,  // y position of window
                                    SCREEN_WIDTH,  // width of window
                                    SCREEN_HEIGHT,  // height of window
                                    SDL_WINDOW_SHOWN);  // flag

        // Check if window was successfully created
        if(m_window == NULL) {
            SDL_Quit();
            return false;
        }

        // Renderer and Texture
        m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_PRESENTVSYNC);
        m_texture = SDL_CreateTexture(m_renderer,
                                      SDL_PIXELFORMAT_ABGR8888,  // R, G, B, Alpha
                                      SDL_TEXTUREACCESS_STATIC,
                                      SCREEN_WIDTH,
                                      SCREEN_HEIGHT);

        if(m_renderer == NULL) {
            SDL_DestroyWindow(m_window);
            SDL_Quit();
            return false;
        }

        if(m_texture == NULL) {
            SDL_DestroyRenderer(m_renderer);
            SDL_DestroyWindow(m_window);
            SDL_Quit();
            return false;
        }

        // Allocate memory for pixels on the screen (every pixel -> 4 bytes for R, G, B, Alpha)
        // Uint32: Type declared by SDL
        m_buffer = new Uint32[SCREEN_WIDTH * SCREEN_HEIGHT];  // Window area

        return true;
    };

    bool Screen::processEvents() {
        SDL_Event event;
        while(SDL_PollEvent(&event)) {  // Checking multiple events, e.g. User closing window
            if(event.type == SDL_QUIT) {
                return false;
            }
        }
        return true;
    };

    void Screen::close() {

        // De-allocate memory
        delete [] m_buffer;

        // Destroy Renderer and Texture
        SDL_DestroyTexture(m_texture);  // Destroy this first as texture is using renderer
        SDL_DestroyRenderer(m_renderer);

        // Close and destroy the window
        SDL_DestroyWindow(m_window);

        // Clean up resources that SDL is using
        SDL_Quit();
    };

    void Screen::setPixel(int x, int y, Uint8 blue, Uint8 green, Uint8 red) {

        /*
         * If statement: Make setPixel refuse to plot pixel off the edges of the screen
         */
        if(x < 0 || x >= SCREEN_WIDTH || y < 0 || y >= SCREEN_HEIGHT) {
            return;
        }

        Uint32 color = 0;

        color += 0xFF;  // alpha
        color <<= 8;
        color += blue;
        color <<= 8;
        color += green;
        color <<= 8;
        color += red;

        m_buffer[(y * SCREEN_WIDTH) + x] = color;

    }

    void Screen::update() {
        // 1. Updating texture
        SDL_UpdateTexture(m_texture, NULL, m_buffer, SCREEN_WIDTH * sizeof(Uint32));

        // 2. Clear renderer
        SDL_RenderClear(m_renderer);

        // 3. Copy texture to the renderer
        SDL_RenderCopy(m_renderer, m_texture, NULL, NULL);

        // 4. Rendering
        SDL_RenderPresent(m_renderer);
    }

}