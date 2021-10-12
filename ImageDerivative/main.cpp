#include <vector>
#include <chrono>
#include <string>
#include <random>
#include <limits>
#include <iostream>

using namespace std; // For fast coding

template<typename T>
void Display(vector<vector<T>>& M);

vector<vector<unsigned char>> GenerateImage(unsigned long m, unsigned long n);
vector<vector<int>> Convolution(vector<vector<unsigned char>>& M, vector<vector<int>>& K);

int main(int argc, const char* argv[]) {

    bool print = false; // Disable if do not want to print

    vector<vector<int>> Kx = {{-1, 0, 1}};
    vector<vector<int>> Ky = {{-1}, {0}, {1}};

    unsigned long width;
    unsigned long height;

    if (argc == 3){
        width = stoul(argv[1]);
        height = stoul(argv[2]);

        auto start = chrono::high_resolution_clock::now();

        // Generate Image
        vector<vector<unsigned char>> M = GenerateImage(width, height);

        // Convolve w/ Horizontal and Vertical kernels
        vector<vector<int>> Dx = Convolution(M, Kx);
        vector<vector<int>> Dy = Convolution(M, Ky);

        int min_dx = INT_MAX;
        int max_dx = INT_MIN;
        int min_dy = INT_MAX;
        int max_dy = INT_MIN;
        for (auto i = 0; i < width; i++){
            for (auto j = 0; j < height; j++){
                min_dx = min(min_dx, Dx[i][j]);
                min_dy = min(min_dy, Dy[i][j]);
                max_dx = max(max_dx, Dx[i][j]);
                max_dy = max(max_dy, Dy[i][j]);
            }
        }

        auto stop = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);

        cout << "dx min: " << min_dx << ", dx max: " << max_dx << endl;
        cout << "dy min: " << min_dy << ", dy max: " << max_dy << endl;
        cout << "Total time taken by program to compute (dx, dy, min and max values) is: " << duration.count() << " microseconds" << endl;

        if (print){
            cout << "Generated Image:" << endl;
            Display(M);
            cout << endl;

            cout << "dx:" << endl;
            Display(Dx);
            cout << endl;

            cout << "dy:" << endl;
            Display(Dy);
            cout << endl;
        }

    } else {
        cout << "Use the following command format " << flush;
        cout << "Usage: [executable] [width] [height]" << endl;
        cout << "Example: ./ImageDerivative 224 256" << endl;
    }

    return 0;
}

template<typename T>
void Display(vector<vector<T>>& M){
    auto m = M.size();
    auto n = M[0].size();
    for (auto i = 0; i < m; i++) {
        for (auto j = 0; j < n; j++) {
            cout << M[i][j] << ", " << flush;
        }
        cout << endl;
    }
}

vector<vector<unsigned char>> GenerateImage(unsigned long m, unsigned long n){
    random_device r_device;
    mt19937 gen(r_device());
    uniform_int_distribution<> u_distribution(0, 255);
    vector<vector<unsigned char>> image(m, vector<unsigned char>(n, 0));
    for (auto i = 0; i < m; i++){
        for (auto j = 0; j < n; j++){
            image[i][j] = static_cast<unsigned char>(u_distribution(gen));
        }
    }
    return image;
}

vector<vector<int>> Convolution(vector<vector<unsigned char>>& M, vector<vector<int>>& K){
    auto k = K.size();
    auto f = K[0].size();
    auto m = M.size();
    auto n = M[0].size();
    vector<vector<int>> D(m, vector<int>(n, 0));

    for (auto i = 1; i < m - 1; i++){
        for (auto j = 1; j < n - 1; j++){
            float value = 0.0;
            for (auto p = i - 1; p < i + k - 1; p++){
                for (auto q = j - 1; q < j + f - 1; q++){
                    value += M[p][q] * K[p - i + 1][q - j + 1];
                }
            }
            D[i][j] = static_cast<int>(value);
        }
    }
    return D;
}

