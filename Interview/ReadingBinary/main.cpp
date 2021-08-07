#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int main() {

    int rows = 0;
    int cols = 0;
    vector<float> image(rows * cols, 0.0f);

    string file_name = "../image.dat";
    ifstream file(file_name, ios_base::in | ios_base::binary);

    if (! file) { return EXIT_FAILURE; }

    file.read(reinterpret_cast<char*>(&rows), sizeof(rows));
    file.read(reinterpret_cast<char*>(&cols), sizeof(cols));
    file.read(reinterpret_cast<char*>(&image.front()),
              image.size() * sizeof(image.front()));

    cout << "Image dimension: " << rows << " x " << cols << endl;
    cout << image[0] << endl;

    return 0;
}