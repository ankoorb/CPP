#include <iostream>
#include <vector>
using namespace std;

int main() {

    vector<double> numbers(0);

    cout << "Size of vector: " << numbers.size() << endl;

    long int capacity = numbers.capacity();
    cout << "Initial capacity: " << capacity << endl;

    for(int i=0; i<10; i++){
        numbers.push_back((double)i);
        if(numbers.capacity() != capacity) {
            capacity = numbers.capacity();
            cout << "capacity (after adding elements): " << capacity << endl;
        }
    }

    cout << "Size of vector: " << numbers.size() << endl;
    cout << "capacity: " << capacity << endl;
//    numbers.clear();
//    numbers.resize(3);
    numbers.reserve(100000);
//    cout << numbers[5] << endl;  // for resize
    cout << "Size of vector (after reserve): " << numbers.size() << endl;
    cout << "capacity (after reserve): " << capacity << endl;

//    for(vector<double>::iterator it = numbers.begin(); it != numbers.end(); it++){
//        cout << *it << endl;
//    }

    return 0;
}

/*
 * 2 ways of iterating through vector: (1) Index based; (2) Iterator based
 * Using Index based to iterate through a vector is not necessarily less
 * efficient that using the iterator based. One can use const iterator to
 * ensure that the elements can not be changed because elements can be changed
 * in index based (also iterator based), however vector provides with methods to
 * get const iterator which ensures elements can not be changed.
 *
 * vectorObject.capacity() returns size of internal array that the vector is
 * using, this size will increase as elements are added
 *
 * vector<int> number(num_elements, initial_value) -> Gives a vector with size 3 and every element
 * initialized to 0
 *
 * vectorObject.clear() removes all the elements and size becomes 0, however the
 * capacity does not change.
 *
 * vectorObject.resize(n) re-sizes the vector to n elements so lot of elements are
 * discarded, however the capacity does not change because internal array is not
 * altered.
 *
 * vectorObject.reserve(n) reserves memory in the internal array of the vector
 * for the value less than it already has. The idea behind reserve is to increase
 * the capacity, in other words increase the size of the internal array of the
 * array
 */

