//
// Created by Ankoor Bhagat on 7/12/18.
//

#ifndef INC_15_TWEAKING_PARTICLE_MOTION_FINAL_SCREEN_H
#define INC_15_TWEAKING_PARTICLE_MOTION_FINAL_SCREEN_H


#include <SDL2/SDL.h>

namespace explosion {

    class Screen {
    private:
        // Instance variables
        SDL_Window *m_window;  // Convention: member variables prefixed with m to make it clear that they are instance variables
        SDL_Renderer *m_renderer;
        SDL_Texture *m_texture;
        Uint32 *m_buffer1;
        Uint32 *m_buffer2;

    public:
        // Define window width and height
        static const int SCREEN_WIDTH = 800;
        static const int SCREEN_HEIGHT = 600;

    public:
        Screen();  // Constructor
        bool init();  // Returns true if it succeeds or false if it fails
        bool processEvents();
        void close();  // De-allocation

        // Setting pixel values
        void setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue);
        void update();
        void clear();
        void boxBlur();


    };

}



#endif //INC_15_TWEAKING_PARTICLE_MOTION_FINAL_SCREEN_H
