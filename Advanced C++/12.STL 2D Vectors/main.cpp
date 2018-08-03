#include <iostream>
#include <vector>
using namespace std;

int main() {

    // Vector of vector, initialize each row with a vector of int, initialized to 7
    vector<vector<int>> grid(3, vector<int>(4, 7));  // 3 rows x 4 columns

    grid[1].push_back(8);
    grid[0].push_back(88);

    for(int row=0; row<grid.size(); row++){
        for(int col=0; col<grid[row].size(); col++){
            cout << grid[row][col] << flush;
        }
        cout << endl;
    }

    // Creating 3 x 5 matrix
    // First create a vector with 5 elements initialized to 0
    vector<int> v_col(5, 0);

    // Create a vector of 3 elements, and each element is a copy of v_col
    vector< vector<int> > matrix(3, v_col);

    for(int row=0; row<matrix.size(); row++){
        for(int col=0; col<matrix[row].size(); col++){
            cout << matrix[row][col] << flush;
        }
        cout << endl;
    }

//    vector< vector<int>> mtx;
//    cout << mtx.size() << endl;



    return 0;
}

/*
 * Outer vector - Think of it as containing rows of grid
 * Inner vector - Particular row in the grid? Should'nt it be columns
 * NOTE: There should be space between < and vector<int>
 */