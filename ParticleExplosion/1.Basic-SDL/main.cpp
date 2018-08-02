#include <iostream>
#include <SDL2/SDL.h>

using namespace std;

int main() {

    if(SDL_Init(SDL_INIT_VIDEO) < 0) {
        cout << "SDL Init failed." << endl;
        return 0;
    }
    cout << "SDL Init succeeded." << endl;

    SDL_Quit();

    return 0;
}