#include <iostream>
#include <string>

using namespace std;

class Car {
public:
    string color;
    int distance = 0;
    int number;

    void printCarData(){
        cout << "The distance that the " << color << " car " << number << " has traveled is " << distance << endl;
    }

    void incrementDistance(){
        distance++;
    }
};

int main() {

    // Without Class
    string car_1_color = "green";
    string car_2_color = "red";
    string car_3_color = "blue";

    int car_1_distance = 0;
    int car_2_distance = 0;
    int car_3_distance = 0;

    car_1_distance++;

    cout << "The distance that the " << car_1_color << " car 1 has traveled is: " << car_1_distance << endl;
    cout << "The distance that the " << car_2_color << " car 2 has traveled is: " << car_2_distance << endl;
    cout << "The distance that the " << car_3_color << " car 3 has traveled is: " << car_3_distance << endl;
    cout << endl;

    // With Class
    Car car1, car2, car3;

    car1.color = "green";
    car2.color = "red";
    car3.color = "blue";

    car1.incrementDistance();

    car1.printCarData();
    car2.printCarData();
    car3.printCarData();


    return 0;
}