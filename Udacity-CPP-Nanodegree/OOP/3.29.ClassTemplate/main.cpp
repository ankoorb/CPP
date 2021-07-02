#include <iostream>
#include <string>
#include <sstream>
#include <cassert>

using namespace std;

// TODO: Add the correct template specification

template <typename KeyType, typename ValueType>
class Mapping {
public:
    KeyType key;
    ValueType value;

    Mapping(KeyType key, ValueType value) : key(key), value(value) {}

    string Print() const {
        ostringstream stream;
        stream << key << ": " << value;
        return stream.str();
    }
};


int main() {

    Mapping<string, int> mapping("age", 34);
    assert(mapping.Print() == "age: 34");

    return 0;
}