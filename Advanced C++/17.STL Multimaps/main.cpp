#include <iostream>
#include <map>
using namespace std;

int main() {

    // Declare multimap
    multimap<int, string> lookup;

    lookup.insert(make_pair(6, "Crush"));
    lookup.insert(make_pair(6, "Spot"));  // Duplicate key
    lookup.insert(make_pair(1, "Kona"));

    for(multimap<int, string>::iterator it = lookup.begin(); it != lookup.end(); it++){
        cout << it->first << ": " << it->second << endl;
    }
    cout << endl;

    // Finding value of a key - Doesn't work well because it print outs
    for(multimap<int, string>::iterator it = lookup.find(1); it != lookup.end(); it++){
        cout << it->first << ": " << it->second << endl;
    }


    cout << endl;

    // Create a pair of iterators
    pair<multimap<int, string>::iterator, multimap<int, string>:: iterator> iters = lookup.equal_range(6);  // Try 1

    for(multimap<int, string>::iterator it = iters.first; it != iters.second; it++){
        cout << it->first << ": " << it->second << endl;
    }

    cout << endl;

    // C++ 11 is backward compatible with C++ 98
    // Feature that simplifies creating pair of iterators

    auto its = lookup.equal_range(1);
    for(multimap<int, string>::iterator it = its.first; it != its.second; it++){
        cout << it->first << ": " << it->second << endl;
    }



    return 0;
}


/*
 * multimap allows to store values with duplicate keys.
 *
 * multimap does not have an overloaded array subscript type operator so to add values we need to use
 * `object.insert()` method, and insert values using pairs
 *
 * `multimapObject.find(key)` is used to check if a key is in a map. How to get a range of elements in
 * in a map: Create a pair of iterators of type multimap and set it equal to `multimapObject.equal_range(key)` and then
 * iterate from one iterator to the other
 *
 * iterator_pair.first - It gives iterator to the start of the range
 * iterator_pair.second - It gives iterator that is off the end of the map
 *
 *
 */