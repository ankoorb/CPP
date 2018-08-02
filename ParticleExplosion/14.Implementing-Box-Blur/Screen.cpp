//
// Created by Ankoor Bhagat on 7/2/18.
//

#include "Screen.h"


namespace explosion {

    Screen::Screen(): m_window(NULL), m_renderer(NULL), m_texture(NULL), m_buffer1(NULL), m_buffer2(NULL) {

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
                                      SDL_PIXELFORMAT_RGBA8888,  // R, G, B, Alpha
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
        m_buffer1 = new Uint32[SCREEN_WIDTH * SCREEN_HEIGHT];  // Window area
        m_buffer2 = new Uint32[SCREEN_WIDTH * SCREEN_HEIGHT];  // Window area

        // Clearing buffer
        memset(m_buffer1, 0, SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(Uint32));
        memset(m_buffer2, 0, SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(Uint32));

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
        delete [] m_buffer1;
        delete [] m_buffer2;

        // Destroy Renderer and Texture
        SDL_DestroyRenderer(m_renderer);
        SDL_DestroyTexture(m_texture);

        // Close and destroy the window
        SDL_DestroyWindow(m_window);

        // Clean up resources that SDL is using
        SDL_Quit();
    };

    void Screen::setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue) {

        /*
         * If statement: Make setPixel refuse to plot pixel off the edges of the screen
         */
        if(x < 0 || x >= SCREEN_WIDTH || y < 0 || y >= SCREEN_HEIGHT) {
            return;
        }

        Uint32 color = 0;

        // RGBA
        color += red;
        color <<= 8;
        color += green;
        color <<= 8;
        color += blue;
        color <<= 8;
        color += 0xFF;  // alpha

        m_buffer1[(y * SCREEN_WIDTH) + x] = color;

    }

    void Screen::update() {
        // 1. Updating texture
        SDL_UpdateTexture(m_texture, NULL, m_buffer1, SCREEN_WIDTH * sizeof(Uint32));

        // 2. Clear renderer
        SDL_RenderClear(m_renderer);

        // 3. Copy texture to the renderer
        SDL_RenderCopy(m_renderer, m_texture, NULL, NULL);

        // 4. Rendering
        SDL_RenderPresent(m_renderer);
    }

    void Screen::boxBlur() {

        // Swap the buffers, so the pixel info is in m_buffer2 and we are drawing to m_buffer1
        // i.e. Copy from one buffer (2) and write to another (1)
        Uint32 *temp = m_buffer1;  // Store the location of buffer 1 was pointing at
        m_buffer1 = m_buffer2;  // Change buffer 1 to point at buffer 2 memory
        m_buffer2 = temp;  // Change buffer 2 to point at stored original value of buffer 1 which is now at temp

        for(int y=0; y<SCREEN_HEIGHT; y++) {
            for(int x=0; x<SCREEN_WIDTH; x++) {

                /* Bit shifting to get the colors of pixels
                 *
                 * 0 0 0
                 * 0 1 0  -> 1: Pixel we are interested in
                 * 0 0 0
                 *
                 * sum the color 9 pixel values and divide by 9 and set the pixel value for pixel
                 * we are interested in setting. So the setting value will be average of color values of
                 * all of pixels around it.
                 */

                int redTotal = 0;
                int greenTotal = 0;
                int blueTotal = 0;

                for(int row=-1; row<=1; row++) {
                    for(int col=-1; col<=1; col++) {
                        int current_x = x + col;
                        int current_y = y + row;

                        if(current_x >= 0 && current_x < SCREEN_WIDTH && current_y >=0 && current_y < SCREEN_HEIGHT) {
                            Uint32 color = m_buffer2[current_y * SCREEN_WIDTH + current_x];

                            Uint8 red = color >> 24;
                            Uint8 green = color >> 16;
                            Uint8 blue = color >> 8;

                            redTotal += red;
                            greenTotal += green;
                            blueTotal += blue;

                        }
                    }
                }

                Uint8 red = redTotal/9;
                Uint8 green = greenTotal/9;
                Uint8 blue = blueTotal/9;

                setPixel(x, y, red, green, blue);

            }
        }
    }
}