#include <iostream>
#include <string>
#include "Universe.h"

using namespace std; // For fast coding during test

int main(int argc, const char* argv[]) {

    string object_A;
    string object_B;
    string input_file;
    const char delimiter = '|';

    if (argc == 4){
        input_file = argv[1];
        object_A = argv[2];
        object_B = argv[3];

        Universe universe(0.0f, 0.0f, input_file, delimiter);
        universe.PrintInfo(object_A, object_B);

    } else {
        cout << "Use the following command format " << flush;
        cout << "Usage: [executable] [filename.txt] [key_A] [key_B]" << endl;
        cout << "Example: ./Cosmos ../sample.txt Alpha_Dra E465D" << endl;
    }

    // TODO: Bonus - Convex Hull: https://www.geeksforgeeks.org/maximum-distance-between-two-points-in-coordinate-plane-using-rotating-calipers-method/

    return 0;
}
