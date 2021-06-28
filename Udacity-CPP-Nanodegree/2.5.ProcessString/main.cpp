#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main() {

    string s("199 2 3");
    istringstream s_stream(s);

    int n;
    s_stream >> n;
    cout << n << endl;
    cout << endl;

    string t("199 2 3");
    istringstream t_stream(t);

    int m;
    while (t_stream){
        t_stream >> m;
        if (t_stream){
            cout << "That stream was successful: " << m << endl;
        } else {
            cout << "That stream was not successful" << endl;
        }
    }
    cout << endl;

    string u("199 2 3");
    istringstream u_stream(u);
    int o;

    while (u_stream >> o){
        cout << "That stream was successful: " << o << endl;
    }
    cout << "The stream has failed." << endl;
    cout << endl;

    // Strings with Mixed Types
    string v("1,2,3");
    istringstream v_stream(v);
    char c;
    int p;

    while (v_stream >> p >> c){
        cout << "That stream was successful: " << p << " " << c << endl;
    }
    cout << "The stream has failed." << endl;

    return 0;
}