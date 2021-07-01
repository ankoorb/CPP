#include <iostream>
#include <string>
#include <cstring>

using namespace std;

class Car {

    // TODO: Declare private attributes
private:
    int horsepower;
    int weight;
    char brand [];

    // TODO: Declare getter and setter for brand
public:
    Car(int hp, int wt, string brand);
    int getHorespower() const;
    int getWeight() const;
    string getBrand() const;

    void setHorsepower(int hp);
    void setWeight(int wt);
    void setBrand(string brand);
};

int main() {

    Car car(400, 1000, "Renault");

    car.setBrand("Ferrari");
    cout << car.getBrand() << endl;

    return 0;
}


Car::Car(int hp, int wt, string brand) {
    setHorsepower(hp);
    setWeight(wt);
    setBrand(brand);
}

int Car::getHorespower() const {
    return horsepower;
}

int Car::getWeight() const {
    return weight;
}

string Car::getBrand() const {
    string output = "Brand name: ";
    output += brand;
    return output;
}

void Car::setHorsepower(int hp) {
    horsepower = hp;
}

void Car::setWeight(int wt) {
    weight = wt;
}

void Car::setBrand(string brand) {
    brand = new char [brand.size() + 1];
    strcpy(this->brand, brand.c_str());
}