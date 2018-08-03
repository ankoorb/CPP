#include <iostream>
#include <vector>
using namespace std;

class Test {
    int id;
    string name;

public:
    Test(int id, string name): id(id), name(name){};
    void print(){ cout << id << ": " << name << endl;}
    friend bool comparator(const Test &x, const Test &y);

//    // Overriding < operator
//    bool operator<(const Test &other) const {
//        if(name == other.name){
//            id < other.id;
//        }
//        return name < other.name;
//    }
};

// Comparison function
bool comparator(const Test &x, const Test &y) {  // const used because function is not going to change the objects
    return x.name < y.name;
}

int main() {

    vector<Test> tests;

    tests.push_back(Test(7, "Spot"));
    tests.push_back(Test(6, "Crush"));
    tests.push_back(Test(1, "Kona"));
//    tests.push_back(Test(2, "Paroh"));

//    sort(tests.begin(), tests.end());

    sort(tests.begin(), tests.end(), comparator);

//    sort(tests.begin(), tests.begin()+3, comparator);  // sorts first 3 elements
//
    for(vector<Test>::iterator it = tests.begin(); it != tests.end(); it++){
        it->print();
    }




    return 0;
}

/*
 * Sorting vector in 2 ways using `std::sort()` method
 *
 * It is not efficient to sort a vector
 *
 * 1. sort(vectorObject.begin(), vectorObject.end()) -> Sorts the whole vector. Sort method arguments
 * Iterator to the first element to start sorting with and iterator to the element where sorting
 * should finish, for this need to override < operator
 *
 * 2. Sometimes you have classes that were written by others and you want to store those objects
 * in a vector and want to be able to compare them -> Create a derived class and implement the operator or
 * an easier way is to do this is to supply a comparison function (a comparator) to the sort method
 *
 *
 * comparator function can not access private members of class so, add prototype of comparator in the
 * class and them make the comparator `friend` of the class.
 *
 * `friend` is allowed to access private members
 *
 * deque -> Double ended queue [Reference](http://www.cplusplus.com/reference/deque/deque/)
 *
 */