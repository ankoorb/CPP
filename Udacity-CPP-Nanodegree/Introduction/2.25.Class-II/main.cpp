#include <iostream>
#include <string>

using namespace std;

class Car {
public:
    string color;
    int distance = 0;
    int number;

    Car(string c, int n){
        color = c;
        number = n;
    }

    void printCarData(){
        cout << "The distance that the " << color << " car " << number << " has traveled is " << distance << endl;
    }

    void incrementDistance(){
        distance++;
    }
};


int main() {

    Car car1("green", 1);
    Car car2("red", 2);
    Car car3("blue", 3);

    car1.incrementDistance();

    car1.printCarData();
    car2.printCarData();
    car3.printCarData();


    return 0;
}