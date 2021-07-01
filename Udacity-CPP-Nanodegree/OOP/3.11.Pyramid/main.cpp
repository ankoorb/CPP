#include <iostream>
#include <cassert>
#include <stdexcept>
#include <cmath>

using namespace std;

class Pyramid {

private:
    int length;
    int width;
    int height;
    void validate();

public:
    Pyramid(int length, int width, int height);

    int getLength() const;
    int getWidth() const;
    int getHeight() const;

    void setLength(int length);
    void setWidth(int width);
    void setHeight(int height);

    float volume() const;
    double surfaceArea() const;
};

int main() {

    Pyramid pyramid(4, 5, 6);
    assert(pyramid.getLength() == 4);
    assert(pyramid.getWidth() == 5);
    assert(pyramid.getHeight() == 6);
    assert(pyramid.volume() == 40.0f);
    cout << "Surface area of pyramid: " << pyramid.surfaceArea() << endl;

    bool caught {false};
    try {
        Pyramid invalid(-1, 2, 3);
    } catch (...){
        caught = true;
    }
    assert(caught);

    return 0;
}


Pyramid::Pyramid(int length, int width, int height) : length(length), width(width), height(height){
    validate();
}

void Pyramid::validate() {
    if (length < 0 || width < 0 || height < 0){
        throw invalid_argument("Negative value for a dimension!");
    }
}

int Pyramid::getLength() const {
    return length;
}

int Pyramid::getWidth() const {
    return width;
}

int Pyramid::getHeight() const {
    return height;
}

void Pyramid::setLength(int length) {
    this->length = length;
    validate();
}

void Pyramid::setWidth(int width) {
    this->width = width;
    validate();
}

void Pyramid::setHeight(int height) {
    this->height = height;
    validate();
}

float Pyramid::volume() const {
    return getLength() * getWidth() * getHeight() / 3.0f;
}

double Pyramid::surfaceArea() const {
    auto a = getLength() * getWidth();
    auto b = getLength() * sqrt(pow(getWidth()/2.0, 2) + pow(getHeight(), 2));
    auto c = getWidth() * sqrt(pow(getLength()/2.0, 2) + pow(getHeight(), 2));
    return a + b + c;
}
















