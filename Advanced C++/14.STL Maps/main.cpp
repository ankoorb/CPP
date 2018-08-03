#include <iostream>
#include <map>
using namespace std;

int main() {

    map<string, int> dict;  // key type: string and value type: int

    // Adding items to the map
    dict["Crush"] = 7;
    dict["Kona"] = 1;

    // Overriding existing key value
    dict["Kona"] = 15;  // Overrides the original value of 1 to 15

    // Accessing map value
    cout << "Value associated with 'Crush' key: " << dict["Crush"] << endl;

    // Iterating through maps
    for(map<string, int>::iterator it=dict.begin(); it != dict.end(); it++){
        cout << it->first << ": " << it->second << endl;
    }

    // Testing if a value is in the map
    if(dict.find("Spot") != dict.end()){
        cout << "Key found!";
    } else {
        cout << "Key not found!" << endl;
    }

//    // Another way of iterating through map
//    for(map<string, int>::iterator it=dict.begin(); it != dict.end(); it++){
//
//        pair<string, int> d = *it;  // pair of the right type
//
//        cout << d.first << ": " << d.second << endl;
//    }

    // Another way of inserting value into the map is create a pair and insert it to map
    pair<string, int> add_to_map("Midas", 30);
    dict.insert(add_to_map);
    dict.insert(pair<string, int>("Spot", 6));

    // Handy function that returns a pair of right type
    dict.insert(make_pair("Paroh", 70));

    // Iterating through maps
    for(map<string, int>::iterator it=dict.begin(); it != dict.end(); it++){
        cout << it->first << ": " << it->second << endl;
    }


    return 0;
}

/*
 * After vectors maps are the next most useful collection
 *
 * Maps allows to store key value pairs, it is like a lookup table (Python dict). All
 * the keys are unique.
 *
 * If a key is not in the map and the map is accessed with that key, it creates key with
 * value = 0 in the map
 *
 * mapObject.find(key) returns an iterator which will point at right element if key is
 * found or point at the end of the mapObject if key is not found
 *
 * What is actually stored in a map? What is iterator actually referring to? -> What we
 * actually store in map is of type pair, which is another template class
 *
 * Exercise: Use cin to create a simple menu system, that allows to enter string and value,
 * and stores them in a map which will allow you to search the map
 *
 */