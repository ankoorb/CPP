#include <iostream>
using namespace std;

int main() {

    // Variables
    int num_cats = 5;
    int num_dogs = 10;
    int num_animals = num_cats + num_dogs;

    cout << "Number of cats: " << num_cats << endl;
    cout << "Number of dogs: " << num_dogs << endl;

    // Adding
    cout << "Total number of animals: " << num_cats + num_dogs << endl;
    cout << "Total number of animals: " << num_animals << endl;

    // Reassigning value
    cout << "New dog acquired." << endl;
    num_dogs = num_dogs + 1;
    cout << "Number of dogs: " << num_dogs << endl;

    return 0;
}