#include <iostream>
using namespace std;

int y = 0;

int funStatic(int n){
    static int x = 0;
    if (n > 0){
        x++;
        return funStatic(n-1) + x;
    }
    return 0;
}

int funGlobal(int n){
    if (n > 0){
        y++;
        return funGlobal(n-1) + y;
    }
    return 0;
}

int main() {

    int a = 3;

    cout << "Static: " << funStatic(a) << endl;
    cout << "Global: " << funGlobal(a) << endl;

    return 0;
}