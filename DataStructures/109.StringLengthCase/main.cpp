#include <iostream>
using namespace std;


int main() {

    // 1. Find length of a string
    char S[] = "python";

    int i;  // i should be declared outside loop
    for (i = 0; S[i] != '\0'; i++){};
    cout << "Length of S: " << i << endl;

    // 2. Upper case to lower case
    char A[] = "WELCOME";
    for (i = 0; A[i] != '\0'; i++){
        A[i]+= 32;
    }
    cout << A << endl;

    // 3. Toggle case
    char B[] = "WeLcOMe";
    for (i = 0; B[i] != '\0'; i++){
        if (B[i] >= 65 && B[i] <= 90){
            B[i]+= 32;
        } else if (B[i] >= 'a' && B[i] <= 122){
            B[i]-= 32;
        }
    }
    cout << B << endl;

    return 0;
}