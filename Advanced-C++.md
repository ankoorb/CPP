### Exceptions

- Exceptions are error handling mechanism
	- `throw`
	- `try`
	- `catch`

```c++
void goWrong() {
    bool error = true;
    if(error){ throw 8; }  // throwing an int
}

int main() {

    try { 
    	goWrong(); 
    }
    
    catch(int e) {  // This will catch int 8 thrown by goWrong()
    	cout << "Error code: " << e << endl; 
    }

    return 0;
}

>>> Error code: 8
```

```c++
void goWrong() {
    bool error = true;
    if(error){ throw "Something went wrong!"; }
}

int main() {

    try { 
    	goWrong(); 
    }
    
    catch(char const* e) {  // char const* because thrown string is primitive
    	cout << "Error message: " << e << endl; 
    }

    return 0;
}

>>> Error message: Something went wrong!
```

```c++
void goWrong() {
    bool error = true;
    if(error){ 
    	throw string("Something went wrong!");  // Creates an object
    }
}

int main() {

    try { 
    	goWrong(); 
    }
    
    // Catching object with reference, works without & too
    catch(string &e) {  // &e returns memory of object
        cout << "String error message: " << e << endl;
    }

    return 0;
}

>>> String error message: Something went wrong!
```

NOTE: `"This is primitive string."` and `string("This is non primitive string.")` because `string` is a class in `iostream`

### Standard Exceptions

- Always check error output and use information in it for `catch` function argument
- [Standard Exception Reference](http://www.cplusplus.com/reference/exception/exception/?kw=exception)

```c++
#include <iostream>
using namespace std;

class CanGoWrong {
public:
    CanGoWrong() {
        char *pMemory = new char[999999999999998];  // Allocating some memory
        delete [] pMemory;
    }
};

int main() {

    //CanGoWrong wrong;  // Error output -> std::bad_alloc

    try {
        CanGoWrong wrong;
    }
    catch(bad_alloc &e) {
        cout << "Caught exception: " << e.what() << endl;
    }

    cout << "Still running!" << endl;

    return 0;
}
```

### Creating Custiom Exceptions

- Use `#include <exception>` and inherit from `exception` class
- `exception` class methods for example `what()` can be overridden. [`exception`](http://www.cplusplus.com/reference/exception/exception/?kw=exception) class method reference. `const throw ()` means method can not throw an exception, and this allows compiler to optimize code, but disadvantages outweigh advantages so it is better to not use `const throw ()` in `virtual const char* what() const throw()`

```c++
#include <iostream>
#include <exception>
using namespace std;

class CustomException: public exception {  // Inherit from exception class
public:

    virtual const char* what() const throw() {
        return "Something bad happened!";
    };
};

class Test {
public:
    void goWrong() {
        throw CustomException();
    }
};

int main() {

    Test test;

    try {
        test.goWrong();
    }
    catch(CustomException &e) {  // Catching reference to CustomException
        cout << e.what() << endl;
    }

    return 0;
}
```

### Exception Catching Order

- Catching exception with subclasses before parent class will avoid errors due to polymorphism

```c++
#include <iostream>
#include <exception>
using namespace std;

void goWrong(){
    bool error1Detected = true;
    bool error2Detected = false;

    if(error1Detected) {
        throw bad_alloc();
    }

    if(error2Detected) {
        throw exception();
    }
}

int main() {

    try {
        goWrong();
    }

	// This will accept bad_alloc because bad_alloc is subclass of exception
    catch(exception &e) {  // Catching with parent class first
        cout << "Catching exception: " << e.what() << endl;
    }
    catch(bad_alloc &e) {  // Catching with child class second
        cout << "Catching bad_alloc: " << e.what() << endl;
    }

    return 0;
}

>>> Catching exception: std::bad_alloc  -> Error
```

```c++
#include <iostream>
#include <exception>
using namespace std;

void goWrong(){
    bool error1Detected = true;
    bool error2Detected = false;

    if(error1Detected) {
        throw bad_alloc();
    }

    if(error2Detected) {
        throw exception();
    }
}

int main() {

    try {
        goWrong();
    }

    catch(bad_alloc &e) {  // Catching with child class first
        cout << "Catching bad_alloc: " << e.what() << endl;
    }
    catch(exception &e) {  // Catching with parent class second
        cout << "Catching exception: " << e.what() << endl;
    }

    return 0;
}

>>> Catching exception: std::bad_alloc  -> Correct
```

### Writing/Reading Text Files

- Use `#include <fstream>`  for reading data or writing data
	- `ofstream` - Output file stream class
	- `ifstream` - Input file stream class

- Writing Text Files

```c++
#include <iostream>
#include <fstream>  // For reading data or writing data
using namespace std;

int main() {

    // ofstream -> Output file stream
    ofstream outFile;  // Object of type ofstream

    string outputFileName = "test.txt";
    outFile.open(outputFileName);  // Open the file

    if(outFile.is_open()) {
        outFile << "Hello there" << endl;
        outFile << 123456789 << endl;
        outFile.close();  // Must close file
    }
    else {
        cout << "Could not create file: " << outputFileName << endl;
    }

    return 0;
}
```

- Reading Text Files

```c++
#include <iostream>
#include <fstream>
using namespace std;

int main() {

    string inFileName = "/path/to/test.txt";
    ifstream  inFile;  // Input file stream

    inFile.open(inFileName);  // Open file

    if(inFile.is_open()) {

        string line;

        //inFile >> line;  // Get inFile into line using extraction operator
        //cout << line << endl;  // Prints only first word!

		 //getline(inFile, line);
        //cout << line << endl;  // Prints first line only

        // Using while loop
        while(!inFile.eof()){  // eof -> End of file
            getline(inFile, line);
            cout << line << endl;  // Prints the whole file
        }

        inFile.close();
    }
    else {
        cout << "Can not open file: " << inFileName << endl;
    }

    return 0;
}
```

### Parsing Text Files

- In C++ 11 built-in Regular Expression libraries or C function can be used to parse text files
	- Discarding new line character
		- `ifstream` object's `.get()` method
		- In C++ 11 `ifstream` object extracted to `ws` to remove white space

- `stats.txt` file content

```
Population UK: 64000000
Population France: 66400000
```

```c++
#include <iostream>
#include <fstream>
using namespace std;

int main() {

    string inFileName = "/path/to/stats.txt";

    ifstream inFile;
    inFile.open(inFileName);

    if(!inFile.is_open()){
        return 1;
    }

    // Parse file
    while(inFile){  // or use !inFile.eof()
        string line;
        
        // Get line from input into string up to delimiter ':'
        getline(inFile, line, ':');  // single quote because a single char used

        int population;
        inFile >> population;

        // Discarding new line character
        inFile >> ws;  // C++ 11 to remove white space

        cout << "'" << line << "'" << "---" << "'" << population << "'" << endl;
    }

    inFile.close();

    return 0;
}

>>> 'Population UK'->'64000000'
>>> 'Population France'->'66400000'
```

### `struct` and Packing

- The only difference between a `struct` and a `class` is that the members of the struct are public by default. `struct` is often used for writing to files.
- When variables are declared in C++, they are stored on an area of memory known as the stack  which is relatively small area of memory, used for storing local variables and keeping track of function calls.
- `string` is a class. Objects of `string` class contain pointers. Because `string` class does not know how much text one will want to store, it does not store text directly. What it does is that it has a pointer inside it and it uses `new` with that pointer to allocate some memory on the heap which is much bigger area of memory. Using `string text` if text is written to binary file, text will not get written, instead pointer to text will get written. And if a different copy of the program reads the file, a pointer address that no longer points anywhere will be read. Thus `string` can not be used so use `char` instead
- C++ packs `struct` to make it more efficient to transfer text to and from memory. It is better to write file by turning off packing using a preproessor directive `#pragma pack(push, 1)` and then using `#pragma pack(pop)` to turn packing on so it does not apply to everything

```c++
#include <iostream>
using namespace std;

#pragma pack(push, 1)  // Turning off packing
struct Person {
    //char c;  // Uncommenting still shows sizeof(Person) = 64
    char name[50];  // char array to store 50 characters
    int age;
    double weight;
};

// Undo directive so that it does not apply to every thing
#pragma pack(pop)  // Turning on packing

int main() {

    int w = sizeof(Person);
    int x = 50 * sizeof(char);
    int y = sizeof(int);
    int z = sizeof(double);
    int sum = x + y + z;
    cout << "Size of Person struct: " << w << endl;
    cout << "Total size of Person struct member types: " << sum << endl;
    cout << "Extra bytes due to struct padding: " << w - sum << endl;

    return 0;
}

>>> Size of Person struct: 62
>>> Total size of Person struct member types: 62
>>> Extra bytes due to struct padding: 0
```

### Writing/Reading Binary File

- NOTE: File extension does not have to be `.bin`
- Using `ios::binary` in `ofstream` object `open()` method prevents C++ from messing up file because of new line character
- NOTE: If using `struct` for writing binary file, it needs to be converted to `char*`
- New way of casting between pointers: `reinterpret_cast<char*>(memory-address)`
- Writing Binary File - `ofstream` object `write()` method needs data and size of data to be written

```c++
#include <iostream>
#include <fstream>
using namespace std;

#pragma pack(push, 1)
struct Person {
    char name[50];
    int age;
    double weight;
};
#pragma pack(pop)

// Initialize a struct
Person someone = {"Jon Snoe", 21, 175.5};

int main() {

    // Write Binary File
    string fileName = "test.bin";  // NOTE: File extension does not have to be bin

    ofstream outputFile;

    outputFile.open(fileName, ios::binary);  // It is important to use ios::binary

    if(outputFile.is_open()){
    
		 // Old way of casting between pointers
        outputFile.write((char *)&someone, sizeof(Person));  
        
        outputFile.close();
    } else {
        cout << "Could not create file: " << fileName << endl;
    }
    return 0;
}
```

- Reading Binary File


```c++
#include <iostream>
#include <fstream>
using namespace std;

#pragma pack(push, 1)
struct Person {
    char name[50];
    int age;
    double weight;
};
#pragma pack(pop)

// Initialize a struct
Person someone = {"Jon Snoe", 21, 175.5};

int main() {

    // Read Binary File
    Person someoneElse;

    ifstream inputFile;

    inputFile.open(fileName, ios::binary); 

    if(inputFile.is_open()){

        inputFile.read(reinterpret_cast<char*>(&someoneElse), sizeof(Person));

        inputFile.close();
    } else {
        cout << "Could not read file: " << fileName << endl;
    }

    cout << "name: " << someoneElse.name << endl;
    cout << "age: " << someoneElse.age << endl;
    cout << "weight: " << someoneElse.weight << endl;

    return 0;
}

>>> name: Jon Snoe
>>> age: 21
>>> weight: 175.5
```

### Standard Template Library (STL)

#### Vector

- Vector is a resizable array. Since vector is resizable it will automatically handle memory. Use `#include <vector>` to use `vector` template class.
- Declaring a vector of some type (int or float or string) containing `n` elements - `vector<type> vectorObject[n]` and declaring a vector of some type: `vector<type> vectorObject`
	- If a vector is pre-sized then do not use `vector[k] = value` to set element off the end of current size of vector. It is better to use `vectorObject.push_back(value)` method to add elements to vector 
- `vectorObject.size()` - Returns the size of the vector, i.e. number of elements in the vector


```c++
#include <iostream>
#include <vector>
using namespace std;

int main() {

    // Declaring vector of type string containing 3 elements
    vector<string> texts(3);  // If using push_back then no need to supply value 5

    // Setting elements in the vector
    texts[0] = "cat";
    texts[1] = "ant";
    texts[2] = "dog";

    cout << texts[2] << endl;

    // Adding extra string to vector
    texts.push_back("one");

    cout << "Size of texts: " << texts.size() << endl;  // Size of vector
    cout << texts[3] << endl;

    return 0;
}

>>> dog
>>> Size of texts: 4
>>> one
```

- There are 2 ways of iterating through vector
	- **Index** based
	- **Iterator** based (recommended)
- Using index based approach to iterate through a vector is not necessarily less efficient using the iterator based approach. `const` iterator can be used to ensure that the elements can not be changed because elements can be changed in index based approach as well as in iterator based approach. However, `vector` provides with methods to get `const` iterator which ensures that elements can not be changed.


- **Index** based approach for iterating through a vector

```c++
for(int i=0; i<texts.size(); i++){
        cout << texts[i] << endl;
    }
```

- **Iterator** based approach (recommended syntax) for iterating through a vector
	- `vectorObject.begin()` - Gives an iterator which points to the first element in the vector
	- `vectorObject.end()` - Gives an iterator which points after the end of the vector

```c++
// Get iterator from vector of strings
vector<string>::iterator it = texts.begin();  
    it++;
    cout << *it << endl;  // Operator overloading???
    
>>> cat
```

```c++
for(vector<string>::iterator it = texts.begin(); it != texts.end(); it++){
        cout << *it << endl;
    }
```

#### Vector and Memory

- Declaring a vector of some type (int or float or string) containing `n` elements with some initial value - `vector<type> vectorObject(n, value)` 
- `vectorObject.capacity()` - Returns the size of internal array that the vector is using. This size will increace as elements are added.

```c++
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
}

>>> Size of vector: 0
>>> Initial capacity: 0
>>> capacity (after adding elements): 1
>>> capacity (after adding elements): 2
>>> capacity (after adding elements): 4
>>> capacity (after adding elements): 8
>>> capacity (after adding elements): 16
```

- `vectorObject.clear()` - Removes all elements from the vector and its size becomes `0`, however the capacity does not change.

```c++
    cout << "Size of vector: " << numbers.size() << endl;
    cout << "capacity: " << capacity << endl;
    numbers.clear();
    cout << "Size of vector (after clear): " << numbers.size() << endl;
    cout << "capacity (after clear): " << capacity << endl;
    
>>> Size of vector: 10
>>> capacity: 16
>>> Size of vector (after clear): 0
>>> capacity (after clear): 16
```

- `vectorObject.resize(n)` - Resizes the vector to `n` elements, so a lot of elements are discarded. However, the capacity does not change because the internal array is not altered.

```c++
    cout << "Size of vector: " << numbers.size() << endl;
    cout << "capacity: " << capacity << endl;
    numbers.resize(3);
    cout << "Size of vector (after resize): " << numbers.size() << endl;
    cout << "capacity (after resize): " << capacity << endl;
    
>>> Size of vector: 10
>>> capacity: 16
>>> Size of vector (after resize): 3
>>> capacity (after resize): 16
```

- `vectorObject.reserve(n)` - Reserves memory in the internal array of the vector for the value less than it already has. The idea behind reserve is to increase the capacity, i.e. increase the size of the internal array of the vector.
- Check C++ reference for other methods.


#### 2D Vectors

- Creating vector of vector of some type: `vector< vector<type> > vectorObject`

```c++
#include <iostream>
#include <vector>
using namespace std;

int main() {

    // Creating 3 x 5 matrix: Create a vector with 5 elements initialized to 0
    vector<int> v_col(5, 0);

    // Create a vector of 3 elements, and each element is a copy of v_col
    vector< vector<int> > matrix(3, v_col);

	 // Iterating through 2D vector	
    for(int row = 0; row < matrix.size(); row++){
        for(int col=0; col < matrix[row].size(); col++){
            cout << matrix[row][col] << flush;
        }
        cout << endl;
    }
    return 0;
}

>>> 00000
>>> 00000
>>> 00000
```

#### List

- List is similar to vector, a difference is that items can be inserted into a list at the beginning or the middle of the list where as in vectors elements can only be inserted at the end. In vector all the elements are stacked next to each other in the computers memory. List contains a bunch of nodes which stores each element and the nodes are linked to each other via pointers. So one node in the list has a pointer to the previous element in the previous node and it also has pointer to the next node. Two nodes in a list have pointers to each other (this is also called as doubly linked list). *To traverse across the list one has to get the element, get the pointer to the next element, and so on so one can not just use index.*
- Use `#include <list>` to use `list` template class.
- Declaring a list of some type (int or float or string): `list<type> listObject`
- `listObject.push_back(item)`: Adds item at the end of the list.
- `listObject.push_front(item)`: Adds item at the front of the list.

```c++
#include <iostream>
#include <list>
using namespace std;

int main() {

    // Create a list of int
    list<int> numbers;

    // Add items to list
    numbers.push_back(15);  // Adds element to the end
    numbers.push_front(7);  // Adds element to the front
    
    // Iterate through the list. NOTE: index can not be used so use iterator
    for(list<int>::iterator it=numbers.begin(); it != numbers.end(); it++){
        cout << *it << endl;
    }
    
    return 0;
}

>>> 15
>>> 7
```

- Inserting items to other positions in the list
	- Create an iterator to the list that references the first element of the list: `list <type::iterator it = listObject.begin()`
	- Pass iterator and item to `listObject.insert` method to insert item to the list at 0th position. Use `it++` to insert item at other positions

```c++
// Create an iterator
list<int>::iterator it = numbers.begin();

// Insert an item at 0th position
numbers.insert(it, 100);

>>> 100
>>> 7
>>> 15
```

- Erasing items to other positions in the list
	- Create an iterator to the list that references the first element of the list: `list <type::iterator it = listObject.begin()`
	- Pass iterator to `listObject.eraze` method to eraze item to the list at 0th position. Use `it++` or `it--` to eraze item at other positions. NOTE: `it = listObject.eraze(it)` is used because when one erase items that an iterator refers to, this invalidates the iterator so iterator is set back to something that is valid.

```c++
// Create an iterator
list<int>::iterator it = numbers.begin();

// Eraze item from 0th position
it = numbers.erase(it);

>>> 15  // 7 is erased from the list
```

- `list` iterator can use `it++` or `it--`, i.e. Iterator can only increment or decrement, and `it+=2` can not be used
- Inserting item to list before some other item

```c++
#include <iostream>
#include <list>
using namespace std;

int main() {

    // Create a list of int
    list<int> numbers;

    // Add items to list
    numbers.push_back(15);  
    numbers.push_back(6);
    numbers.push_front(7); 

    for(list<int>::iterator it=numbers.begin(); it != numbers.end(); it++){

        // Inserting item with value 5 before value 6
        if(*it == 6){
            numbers.insert(it, 5);
        }
    }

    // Iterating through the list
    for(list<int>::iterator it=numbers.begin(); it != numbers.end(); it++){
        cout << *it << endl;
    }
    
    return 0;
}

>>> 7
>>> 15
>>> 5  // Inserted before 6
>>> 6
```

- Erasing some item from the list

```c++
#include <iostream>
#include <list>
using namespace std;

int main() {

    // Create a list of int
    list<int> numbers;

    // Add items to list
    numbers.push_back(15); 
    numbers.push_back(6);
    numbers.push_front(7); 

    for(list<int>::iterator it=numbers.begin(); it != numbers.end();){  // it++ below
    
        // Erasing item with value 6
        if(*it == 6){
            // Set iterator back to something that is valid
            it = numbers.erase(it);  
		  /*
		   * Iterator now in effect is incremented twice because iterator now points
		   * to the item after the one that has been erased. Now in the `for()` the
		   * iterator is incremented again it will skip an item, so increment the 
		   * iterator only if we do not erase something from it
		   */
        } else {
            it++;
        }
    }
    
    for(list<int>::iterator it=numbers.begin(); it != numbers.end(); it++){
        cout << *it << endl;
    }
    
    return 0;
}

>>> 7
>>> 15
```

#### Map

- Map allows to store key and value pairs. It is like a lookup table (`Python dict`). All the keys are unique. 
- Use `#include <map>` to use `map` template class.
- Declaring a `map` of some `key` type and `value` type: `map<key_type, value_type> mapObject`
- Adding `key` and `value` pair to the map: `mapObject[key] = value`
- Accessing a `key`'s `value` from map: `mapObject[key]` returns `value` associated with `key`. NOTE: If a `key` is not in the map and the map is accessed with that `key`, it creates  the `key` with `value = 0` in the map.
- Iterating through map
	- Create an iterator to the map that references the first item of the map.
	- Use `iterator->first` to access `key` and `iterator->second` to access `value`

```c++
#include <iostream>
#include <map>
using namespace std;

int main() {

	// Declare map of key type: string and value type: int
    map<string, int> dict;  

    // Adding items to the map
    dict["Crush"] = 7;
    dict["Kona"] = 1;

    // Overriding existing key value
    dict["Kona"] = 15;  // Overrides the original value of 1 to 15

    // Accessing a key's value in map
    cout << "Value associated with 'Crush' key: " << dict["Crush"] << endl;

    // Iterating through maps
    for(map<string, int>::iterator it=dict.begin(); it != dict.end(); it++){
        cout << it->first << ": " << it->second << endl;
    }

    return 0;
}

>>> Value associated with 'Crush' key: 7
>>> Crush: 7
>>> Kona: 15
``` 

- Test if a `key` is in the map use `mapObject.find(key)`. NOTE: If a `key` which does not exist in a map is used to access a value, the `key` is automatically created in the map with `value` set as `0` automatically and this is undesirable so it is better to use `find` method. 

```c++
    if(dict.find("Spot") != dict.end()){
        cout << "Key found!";
    } else {
        cout << "Key not found!" << endl;
    }
    
>>> Key not found!
```

- **`pair`** template class - What is actually stored in a `map`? What is iterator actually referring to?: Thing that is stored in a `map` is of type `pair`, which is another template class. `pair` has instance variables `first` and `second` that can be used to access `key` and `value`
- Using `pair` to iterate through a `map`. NOTE: Need to create a `pair` of the right type. A handy function that creates a `pair` of right type: `make_pair(key_type, value_type)`

```c++
#include <iostream>
#include <map>
using namespace std;

int main() {

	 // Declare map of key type: string and value type: int
    map<string, int> dict;

    // Adding items to the map
    dict["Crush"] = 7;
    dict["Kona"] = 1;

    // Another way of iterating through map
    for(map<string, int>::iterator it=dict.begin(); it != dict.end(); it++){

		 // Create pair of right type
        pair<string, int> d = *it;

        cout << d.first << ": " << d.second << endl;
    }
    return 0;
}

>>> Crush: 7
>>> Kona: 15
```

- Using `pair` to insert item into a map - Create a `pair` of right type and insert it into the map

```c++
// Create a pair and insert it to map
pair<string, int> add_to_map("Spot", 6);
dict.insert(add_to_map);

// Another way
dict.insert(pair<string, int>("Duke", 3));

// Using make_pair function
dict.insert(make_pair("Paroh", 70));
```

#### Custom Objects as Map Values

- `map<type, ClassName> mapObject` - 
- `error: no matching constructor for initialization of 'ClassName'` - When a constructor that has parameters is defined, the default implementation of a constructor with no parameters is lost. `map` needs constructor with no parameters to construct the object and then assign values to the object using the object that you set that equal to.

```c++
#include <iostream>
#include <map>
using namespace std;

class Person{
private:
    string name;
    int age;

public:
    // To avoid: error: no matching constructor for initialization of 'Person'
    Person(): name(""), age(0) {};  

    Person(string name, int age): name(name), age(age) {};
    void print() { cout << name << ": " << age << endl; }
};

int main() {

    map<int, Person> people;
    people[0] = Person("Kona", 1);
    people[1] = Person("Crush", 6);

    for(map<int, Person>::iterator it=people.begin(); it!=people.end(); it++){
        cout << it->first << ": " << flush;
        it->second.print(); // Value is a Person object so using print method
    }

    return 0;
}

>>> 0: Kona: 1
>>> 1: Crush: 6
```

- `mapObject[key] = ClassName(var, ...)` - `map` is constructing the object using default parameter less constructor and then assigning the values to the object using the assignment operator (`=`). *By default C++ gives class a default implementation of the assignment operator which does a shallow copy (it just copies the values of instance variables from the object that is set equal to)* and this is not good when using pointer, so sometimes the assignment operator needs to be overridden. *In general you do not want to copy pointers when you do a copy of an object because then you just get a pointer that is pointing at same place that your other object's pointer was pointing to.*
- It you do not want to copy the values of some instance variables when you do the copy or you want to change them somehow in the copy then you would want to provide a copy constructor as well as override assignment operator.

```c++
#include <iostream>
#include <map>
using namespace std;

class Person{
private:
    string name;
    int age;

public:
    Person(): name(""), age(0) {};  
    
    // Create a copy constructor
    Person (const Person &other) {
        cout << "Copy constructor running." << endl;
        name = other.name;
        age = other.age;
    };

    Person(string name, int age): name(name), age(age) {};
    void print() { cout << name << ": " << age << endl; }
};

int main() {

    map<int, Person> people;
    people[0] = Person("Kona", 1);
    people[1] = Person("Crush", 6);

    people.insert(make_pair(3, Person("Spot", 7)));  // Copy constructor runs

    for(map<int, Person>::iterator it=people.begin(); it!=people.end(); it++){
        cout << it->first << ": " << flush;
        it->second.print();
    }
    return 0;
}

>>> Copy constructor running.
>>> Copy constructor running.
>>> 0: Kona: 1
>>> 1: Crush: 6
>>> 3: Spot: 7
```

- Map always sorts objects in the order of its keys.

#### Custom Objects as Map Keys

- `error: member function 'functionName' not viable: 'this' argument has type 'const ClassName'` - This happens when `functionName` is not marked `const`. The keys in the map as retrieved by `first` using the iterator are `const` and `map` does not want to allow to alter the keys so as important as they are, the iterator returns them as `const` and the `functionName` is not marked as `const` so the function could change the keys so that is why error is returned. Solution: Mark `functionName` as `const`.
- `error: invalid operands to binary expression ('const ClassName' and 'const ClassName')` - This happens because C++ does not know how to compare different objects of `ClassName` class.  It has to compare objects because it has to sort the keys of the map in the right order. Comparison is done using less than (`<`) operator. Solution: Overload `<` operator in `ClassName`.
	- `bool operator<(const ClassName &other) const { comparison code; }` - `bool` is used because less that (`<`) operator returns `bool`. There should be no space between `operator` and `<`. The `<` operator will compare `this` object with `other` object, so need to pass in other object that has to be marked `const` reference. Reference is used for efficiency as we do not want to create a copy of the `ClassName` when it is passed in. Reference is marked `const` because we do not want `<` operator to change the other object. It is important to mark the whole method as `const` because the overloaded operator should not change `this` object or the other object. 

- NOTE: When a new object with same key is added the value of the key gets updated.

```c++
#include <iostream>
#include <map>
using namespace std;

class Person{
private:
    string name;
    int age;

public:
    // Default constructor
    Person(): name(""), age(0) {};

    // Create a copy constructor
    Person (const Person &other) {
        cout << "Copy constructor running" << endl;
        name = other.name;
        age = other.age;
    };

    // Constructor that accepts parameters
    Person(string name, int age): name(name), age(age) {};

    void print() const { cout << name << ": " << age << flush; }

    // Overloading less than operator
    bool operator<(const Person &other) const {         
        // Situation when key is same but value is different
        if(name == other.name){
            return this->age < other.age;
        }
        // Using string less than operator for alphabetically sorting
        return name < other.name;  
    };
};

int main() {

    map<Person, int> people;
    people[Person("Crush", 6)] = 6;
    people[Person("Kona", 1)] = 1;

    // Adding a new object with the same key -> the value of the key gets updated
    people[Person("Kona", 5)] = 15;  
    
    // considered same as people[Person("Kona", 1)], need to take age into account

    for(map<Person, int>::iterator it=people.begin(); it!=people.end(); it++){
        cout << it->second << " <- " << flush;
        it->first.print();
        cout << endl;
    }
    return 0;
}

>>> Copy constructor running
>>> Copy constructor running
>>> Copy constructor running
>>> 6 <- Crush: 6
>>> 1 <- Kona: 1
>>> 15 <- Kona: 7
```

#### Multimaps


- `multimap` allows to store values with duplicate keys.
- Use `#include <multimap>` to use `multimap` template class.
- Declaring a `multimap` of some `key` type and `value` type: `multimap<key_type, value_type> multimapObject`
- `multimap` does not have an overloaded array subscript type operator (i.e. `[]`) so to add items use `multimapObject.insert` method and insert items using `pair`

```c++
#include <iostream>
#include <map>
using namespace std;

int main() {

    // Declare multimap
    multimap<int, string> mm;

    mm.insert(make_pair(6, "Crush"));
    mm.insert(make_pair(6, "Spot"));  // Duplicate key
    mm.insert(make_pair(1, "Kona"));

    for(multimap<int, string>::iterator it = mm.begin(); it != mm.end(); it++){
        cout << it->first << ": " << it->second << endl;
    }
    return 0;
}

>>> 1: Kona
>>> 6: Crush
>>> 6: Spot
```

- `multimapObject.find(key)` is used to check if a `key` is in a multimap. However it does not work well as after finding the key it goes till the end of the map. So `find` is only useful for finding one key in a map or checking if it is in there or not. Check below:

```c++
	 // Does not work as expected 
    for(multimap<int, string>::iterator it = mm.find(1); it != mm.end(); it++){
        cout << it->first << ": " << it->second << endl;
    }
    
>>> 1: Kona  // Should have stopped here
>>> 6: Crush
>>> 6: Spot
```

- How to get a range of items in a `multimap`? - Create a `pair` of iterators of type `multimap` and set it equal to `multimapObject.equal_range(key)`, where `key` is the key to be found and then iterate from one iterator to the other. `multimapObject.equal_range` method returns a pair of iterators to the start and the end of the range.
	- `iteratorPair.first` - It gives iterator to the start of the range
	- `iteratorPair.second` - It gives iterator that is off the end of the map

```c++
    // Create a pair of iterators
    pair<multimap<int, string>::iterator, multimap<int, string>:: iterator> its = mm.equal_range(6);

	 // NOTE: mm.begin() and mm.end() are replaced by iterator pair
    for(multimap<int, string>::iterator it = its.first; it != its.second; it++){
        cout << it->first << ": " << it->second << endl;
    }
    
>>> 6: Crush
>>> 6: Spot
```

- C++ 11 is backward compatible with C++98. In C++ 11 there is a feature that simplifies creating a `pair` of iterators. `auto` which automatically gets type.

```c++
	 auto its = mm.equal_range(1);
    for(multimap<int, string>::iterator it = its.first; it != its.second; it++){
        cout << it->first << ": " << it->second << endl;
    }
    
>>> 1: Kona    
```

#### Set

- `set` only stores unique elements and orders them as well.
- Use `#include <set>` to use `set` template class.
- Declaring a `set` of some type: `set<type> setObject`

```c++
#include <iostream>
#include <set>
using namespace std;

int main() {

    // Declare a set to store integers
    set<int> numbers;

    // Insert elements to set
    numbers.insert(7);
    numbers.insert(6);
    numbers.insert(7);  // Same value

    for(set<int>::iterator it = numbers.begin(); it != numbers.end(); it++){
        cout << *it << endl;
    }
    cout << endl;
    return 0;
}

>>> 6
>>> 7
```

- Find if an object is in a set:
	- Use `setObject.find(object)` method
	- Use `setObject.count(object)` method, which returns `0` or `1` (since `set` stores unique elements)

```c++
#include <iostream>
#include <set>
using namespace std;

int main() {

    // Declare a set to store integers
    set<int> numbers;

    // Insert elements to set
    numbers.insert(7);
    numbers.insert(6);

    // Find if an object is in set
    set<int>::iterator itFind = numbers.find(7);

    if(itFind != numbers.end()){ 
        cout << "Found: " << *itFind << endl;
    }
    cout << endl;

    // Using count based method
    if(numbers.count(7)){  // Count returns 0 or 1
        cout << "Number found!" << endl;
    }
    return 0;
}

>>> Found: 7
>>> 
>>> Number found!
```

- `set` of custom object

```c++
#include <iostream>
#include <set>
using namespace std;

class Dog {
private:
    int id;
    string name;

public:
    Dog(): id(0), name("") {};
    Dog(int id, string name): id(id), name(name){};
    void print() const {
        cout << "Name: " << name << " & id: " << id << endl;
    }

    // Overloading < operator because set orders
    bool const operator<(const Dog &other) const {  // Reference to an existing object
        if(name == other.name){
            return id < other.id;
        }
        return this->name < other.name; // or name < other.name;
    };
};

int main() {

    // Set of Dog objects
    set<Dog> dogs;

    dogs.insert(Dog(1, "Crush"));
    dogs.insert(Dog(3, "Kona"));
    dogs.insert(Dog(2, "Crush"));

    for(set<Dog>::iterator it = dogs.begin(); it != dogs.end(); it++){
        it->print();
    }
    return 0;
}

>>> Name: Crush & id: 1
>>> Name: Crush & id: 2
>>> Name: Kona & id: 3
```

#### Stack

- `stack` is a Last In First Out (LIFO) structure. Analogy: a stack of cards.
- Use `#include <stack>` to use `stack` template class.
- Declaring a `stack` of some type: `stack<type> stackObject`
- Use `stackObject.push(item)` to insert item to top of stack.
- To get an object from a stack or queue there is no way to iterate through a stack or a queue. Use `vector` instead of `stack` or `queue` if you need to iterate.
- STL classes (collection) - When you access objects stored within the collection of objects (e.g. objects stored in `vector`), the STL class will return a reference of the object that is in it. `stackObject.top()` is returning reference to the object in the `stackObject` because of assignment (`=`) operator in `ClassName topItem = stackObject.top()`. We are actually copying the object that the reference refers to into `topItem`, so it is using shallow copy here using the default implementation of the assignment operator, and it is just copying the values of the instance variables into `topItem`. *This means that when we add objects to the stack like this we are going to be destroying the original objects that we added.* Solution: Use reference, e.g. `ClassName &topItem = stackObject.top()`, which returns reference to the existing object in the stack.

```c++
#include <iostream>
#include <stack>
#include <queue>
using namespace std;

class Test {
private:
    string name;
public:
    Test(string name): name(name) {}
    ~Test(){ cout << "Object destroyed!" << endl;}
    void print(){ cout << name << endl; }

};

int main() {

    // Create stack object
    stack<Test> testStack;

    // Adding items to top of stack
    testStack.push(Test("Crush"));
    testStack.push(Test("Kona"));
    
    return 0;
}

>>> Object destroyed!
>>> Object destroyed!
>>> Object destroyed!
>>> Object destroyed!
```

- Use `stackObject.top()` method *with reference for efficiency* to check the item at the top of the stack.

```c++
#include <iostream>
#include <stack>
#include <queue>
using namespace std;

class Test {
private:
    string name;
public:
    Test(string name): name(name) {}
    void print(){ cout << name << endl; }
};

int main() {

    // Create stack object
    stack<Test> testStack;

    // Adding items to top of stack
    testStack.push(Test("Crush"));  // First added
    testStack.push(Test("Kona"));  // Last added
    cout << endl;

    // Looking at the top item of the stack
    Test &testItem = testStack.top();  // Using reference
    testItem.print();

    return 0;
}

>>> Kona  // Top item
```

- Popping items off the stack use `stackObject.pop()` method which does not return anything as it has `void` return type. Invalid code because `stackObject.pop()` method destroys object. NOTE: If you use reference you cannot pop an object and keep on using it. If you want an object to hang around after it has been popped then remove the reference and get a copy of the object which is less efficient but copy is going to persist even when the original gone.

```c++
    // Looking at the top item of the stack
    Test &testItem = testStack.top();  // Using reference
    
    // Popping items off the stack
    testStack.pop();  // Object is destroyed
    testItem.print();  // Reference refers to destroyed object
    cout << endl;
    
>>> Kona  // This was popped but still got printed
```

- `stackObject.size()` returns number of items in a stack.

- Sort of iterating through a stack - The only way to iterate through a stack is to remove objects from it using `stackObject.pop()` method along with `stackObject.size()` method.

```c++
	// Iterating through a stack
    while(testStack.size() > 0) {
        Test &test = testStack.top();
        test.print();  // Prints in reverse order
        testStack.pop();
    }
    
>>> Kona
>>> Crush
```

#### Queue

- `queue` is a First In First Out (FIFO) structure. Analogy: a cash register at a store.
- Use `#include <queue>` to use `queue` template class.
- Declaring a `queue` of some type: `queue<type> queueObject`
- Use `queueObject.push(item)` to insert item to top of stack.
- Use `queueObject.front()` method (*with reference for efficiency*) to check the item at the front of the queue.
- Use `queueObject.back()` method (*with reference for efficiency*) to check the item at the back of the queue.

```c++
#include <iostream>
#include <stack>
#include <queue>
using namespace std;

class Test {
private:
    string name;
public:
    Test(string name): name(name) {}
    void print(){ cout << name << endl; }

};

int main() {
    // Create queue object
    queue<Test> testQueue;

    // Adding items to queue
    testQueue.push(Test("Spot"));
    testQueue.push(Test("Paroh"));

    Test &testQf = testQueue.front();
    testQf.print();

    testQueue.back().print();
    cout << endl;

    // Iterating through a queue
    while(testQueue.size() > 0){
        Test &testItem = testQueue.front();
        testItem.print();
        testQueue.pop();
    }
    return 0;
}

>>> Spot
>>> Paroh
```

#### Sorting Vectors, Deque and Friend

- Sorting vector in 2 ways using `std::sort()` method. NOTE: It is not efficent to sort a vector.
- `sort(vectorObject.begin(), vectorObject.end())` - Sorts the whole vector. Sort method arguments: Iterator to the first element to start sorting with and iterator to the element where sorting should finish. For using this override `<` operator.

```c++
#include <iostream>
#include <vector>
using namespace std;

class Test {
    int id;
    string name;

public:
    Test(int id, string name): id(id), name(name){};
    void print(){ cout << id << ": " << name << endl;}

    // Overriding < operator
    bool operator<(const Test &other) const {
        if(name == other.name){
            id < other.id;
        }
        return name < other.name;
    }
};

int main() {

    vector<Test> tests;

    tests.push_back(Test(7, "Spot"));
    tests.push_back(Test(6, "Crush"));
    tests.push_back(Test(1, "Kona"));

    // Sort
    sort(tests.begin(), tests.end());

    for(vector<Test>::iterator it = tests.begin(); it != tests.end(); it++){
        it->print();
    }
    return 0;
}

>>> 6: Crush
>>> 1: Kona
>>> 7: Spot
```

- Sorting using a comparison function (a comparator) - Sometimes you have classes that were written by others and you want to store those objects in a vector and you want to be able to compare them. A solution would be to create a derived class and implement the operator (operride the operator) or an easier way would be to supply a comparison function (a comparator) pointer to the `std::sort()` method. *Since comparator function can not access private members of class, add prototype of comparator in the class and then make the comparator function `friend` of the class. `friend` is allowed to access private members of a class. If `friend` is not used then `error: 'variable' is a private member of 'ClassName'` is returned.

```c++
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
};

// Comparison function
// const used because function is not going to change the objects
bool comparator(const Test &x, const Test &y) {  
    return x.name < y.name;
}

int main() {

    vector<Test> tests;

    tests.push_back(Test(7, "Spot"));
    tests.push_back(Test(6, "Crush"));
    tests.push_back(Test(1, "Kona"));

    // Sort using comparison function
    sort(tests.begin(), tests.end(), comparator);

    for(vector<Test>::iterator it = tests.begin(); it != tests.end(); it++){
        it->print();
    }
    return 0;
}

>>> 6: Crush
>>> 1: Kona
>>> 7: Spot
```

- `deque` - Double ended queue [Reference](http://www.cplusplus.com/reference/deque/deque/)

#### Complex Data Types

- Complex nested data types - Nested STL collection types can be used to represent any data structure. 

```c++
#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {

    // Create a map of vectors
    map<string, vector<int>> scores;

    scores["Crush"].push_back(10);  // Python: dict[key].append(n)
    scores["Crush"].push_back(20);

    scores["Kona"].push_back(15);
    scores["Kona"].push_back(25);

    for(map<string, vector<int>>::iterator it = scores.begin(); it != scores.end(); it++){
        string name = it->first;
        vector<int> scoreList = it->second;
        cout << name << ": " << flush;
        for(int i=0; i<scoreList.size(); i++){
            cout << scoreList[i] << " " << flush;
        }
        cout << endl;
    }
    return 0;
}

>>> Crush: 10 20 
>>> Kona: 15 25 
```

### Overloading Assignment Operator

```c++
#include <iostream>
using namespace std;

class Test {
private:
    int id;
    string name;
public:
    Test(): id(id), name(name){}
    Test(int id, string name): id(id), name(name){}
    void print() { cout << id << ": " << name << endl; }
};

int main() {

    Test test1(1, "Crush");
    cout << "test1 - ";
    test1.print();

    Test test2(7, "Kona");
    cout << "test2 - ";
    test2.print();

    // Assigning
    test2 = test1;
    cout << "After assignment test2 - ";
    test2.print();

    return 0;
}

>>> test1 - 1: Crush
>>> test2 - 7: Kona
>>> After assignment test2 - 1: Crush
```

- `object2 = object1` works because C++ provides a default implementation of something that causes this to work. What it is actually doing is a *shallow copy*. It is copying all the values of the variables in `object1` over to `object2`. Sometimes you want a shallow copy but other times you need a *deep copy*, e.g. If you had an `id` that had to be unique for every object you might not want to give `object2` the same `id` as `object1` (you might want to change the `id` to a unique `id` but give it the same `name`). You might also have pointers in the constructor, e.g. You could allocate memory, if you have pointer in `object1` that is pointing at some allocated memory. If a shallow copy is done to copy the value to `object2`, now you have got a copy of that pointer pointing at the memory `object1` allocated, in a way you have stolen `object1`'s memory rather than allocating your own in the copy, so sometimes you want to override this kind of behaviour. 
- `object2 = object1` can be thought of calling a method on `object2` and providing it with the argument `object1`. The operator `=` has 2 arguments to it (`object1` and `object2`). If we implement a method and call it on `object2` and pass it `object1`, it also has 2 arguments, `object1` and an implicit first argument which is a reference to the object being called on that enables you to use `this` operator in your methods, e.g. `test2.print()` seems to have no argument but there is an implicit first argument. So *if we implement the `=` operator as a method call with one argument, it actually has got 2 arguments (`object1` and `object2`). Because it has 2 arguents to it we call it a binary operator.
- Return type for `=` operator overloading should be `const` reference because you do not want to change things.

```c++
#include <iostream>
using namespace std;

class Test {
private:
    int id;
    string name;
public:
    Test(): id(id), name(name){}
    Test(int id, string name): id(id), name(name){}
    void print() { cout << id << ": " << name << endl; }

    // Assignment operator overloading
    const Test &operator=(const Test &other){ // Object is first implicit argument
        cout << "Assignment running" << endl;
        id = other.id;
        name = other.name;
        return *this;
    }
    /*
     * Explicit argument: const Test &other - is const because we do not want 
     * RHS to change and using reference because it is more efficient to pass 
     * references than passing objects.
     */
};

int main() {

    Test test1(1, "Crush");
    Test test2(7, "Kona");

    Test test3;
    test3 = test2 = test1;  // Return reference from method call
    test3.print();
    
    test3.operator=(test2);
    cout << "test3 - ";
    test3.print();

    return 0;
}

>>> Assignment running
>>> Assignment running
>>> 1: Crush
>>> Assignment running
>>> test3 - 1: Crush
```

- `object2.operator=(object1)` is equivalent to `object2 = object1`, and you can see that `=` is like a method call where the method name is `operator=`

- Copy Initialization (`ClassName object2 = object1`) - If you take an object and do not give initial values i.e. `ClassName object2` instead of `ClassName object2(value)` and you just immediately assign the declared objec to another it does not actually use the `=` operator, it actually uses the copy constructor.
- **Rule of 3 in C++** - If you define a copy constructor or an assignment operator or a destructor. If you implement any one of those then you should implement the other 2 as well.

```c++
#include <iostream>
using namespace std;

class Test {
private:
    int id;
    string name;
public:
    Test(): id(id), name(name){}
    Test(int id, string name): id(id), name(name){}
    void print() { cout << id << ": " << name << endl; }

    // Assignment operator overloading
    const Test &operator=(const Test &other){ 
        cout << "Assignment running" << endl;
        id = other.id;
        name = other.name;
        return *this;
    }

    // Copy constructor
    Test(const Test &other) {
        cout << "Copy constructor running" << endl;
        id = other.id;
        name = other.name;
        //*this = other;  // Can use if = operator is implemented
    }
};

int main() {

    Test test1(1, "Crush");
    
   // Copy initialization
    Test test4 = test1; 
    test4.print();

    return 0;
}

>>> Copy constructor running
>>> 1: Crush
```

### Overloading Left Bit Shift Operator

```c++
ClassName object;
cout << object << endl;  // error: invalid operands to binary expression
```

- `cout << object << endl;` - does not work if `<<` operator has not been overloaded. The first `<<` has 2 arguments: `cout` which is an object of type `ostream` (output stream) and `object`. If you look at second `<<` your first thought will be that it has 2 arguments: `object` and `endl`, but in fact some operators in C++ are right-left associative and others are left-right associative. For example in `int value = 1 + (2 + 5)` the `+` operator has right-left associativity, i.e. first `(2 + 5)` is computed then `1 + (7)` is computed. The `<<` operator has left-right associativity, so in `cout << object << endl;`, first the left bit `cout << object` will get evaluated and it will return an object which is a reference to an `ostream` object, and then the second `<<` has 2 arguments: reference to an `ostream` object and `endl`. So in both cases the first argument the `operator` has is an `ostream` object.
- Return type for `<<` operator overloading should be reference to an `ostream` object

```c++
#include <iostream>
using namespace std;

class Test {
private:
    int id;
    string name;
public:
    Test(): id(0), name("") {}
    Test(int id, string name): id(id), name(name){}
    void print(){ cout << id << ": " << name << endl; }
    const Test &operator=(const Test &other) {
        id = other.id;
        name = other.name;
        return *this;
    }
    Test(const Test &other){ *this = other; }

    // Overloading left bit shift operator
    friend ostream &operator<<(ostream &out, const Test &test){
        out << test.id << ": " << test.name;
        return out;
    }
    /* First argument: Reference to ostream object
     * Second argument: const reference to Test class
     */

};

int main() {

    Test test1(6, "Crush");
    cout << test1 << endl;  // Works after operator overloading

    Test test2(1, "Kona");
    cout << test1 << " " << test2 << endl;

    return 0;
}

>>> 6: Crush
>>> 6: Crush 1: Kona
```

#### Complex Number Class

```c++
// Complex.h

#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>
using namespace std;
namespace complex {

    class Complex {
    private:
        double real;
        double imaginary;
    public:
        Complex();
        virtual ~Complex();

        // Constructor with params
        Complex(double real, double imaginary);

        // Copy Constructor
        Complex(const Complex &other);

        // Overriding assignment operator
        const Complex &operator=(const Complex &other);

        // Get methods
        double getReal() const;
        double getImaginary() const;
    };

    // Return type is ostream reference
    ostream &operator<<(ostream &out, const Complex &c);
    
}


#endif //COMPLEX_H
```

```c++
// Complex.cpp

#include "Complex.h"

namespace complex {

    Complex::Complex(): real(0), imaginary(0){}
    Complex::~Complex() {}

    Complex::Complex(double real, double imaginary): real(real), imaginary(imaginary) {}

    Complex::Complex(const Complex &other) {
        real = other.real;
        imaginary = other.imaginary;
    }

    // Return type is const Complex reference
    const Complex &Complex::operator=(const Complex &other){
        real = other.real;
        imaginary = other.imaginary;

        return *this;
    }

    double Complex::getReal() const { return real; }
    double Complex::getImaginary() const { return imaginary; }

    ostream &operator<<(ostream &out, const Complex &c){
        cout << "(" << c.getReal() << ", " << c.getImaginary() << ")";
        return out;
    }
}
```

```c++
// main.cpp

#include <iostream>
#include "complex.h"
using namespace std;
using namespace complex;

// Overloading = operator

int main() {

    Complex c1(2, 3);
    Complex c2(c1);  // Using copy constructor

    Complex c3;
    c3 = c2;  // Using assignment operator

    cout << c2 << ": " << c3 << endl;

    return 0;
}

>>> (2, 3): (2, 3)
```

### Overloading Plus Opertor

- Overloading `+` operator approaches
	1. Make a member function
	2. Make a free standing function to make it more encapsulated (below)

- Return type for `+` operator overloading should `ClassName` object

```c++
// Complex.h

// Return type for + operator is Complex object
Complex operator+(const Complex &c1, const Complex &c2);  
```

```c++
// Complex.cpp

Complex operator+(const Complex &c1, const Complex &c2){
        return Complex(c1.getReal() + c2.getReal(), 
                       c1.getImaginary() + c2.getImaginary());
}
```

```c++
#include <iostream>
#include "complex.h"
using namespace std;
using namespace complex;

int main() {

    Complex c1(3, 4);
    Complex c2(2, 3);
    cout << c1 + c2 << endl;

    return 0;
}

>>> (5, 7)
```

- Adding a complex number to something that is not a complex number, e.g. override `+` operator that enables to add real value to the real part of the complex number

```c++
// Complex.h

// Adding real value to real number of complex number
Complex operator+(const Complex &c1, double d);
```

```c++
// Complex.cpp

Complex operator+(const Complex &c1, double d){
        return Complex(c1.getReal() + d, c1.getImaginary());
}
```

```c++
#include <iostream>
#include "complex.h"
using namespace std;
using namespace complex;

int main() {

      // Adding real to real value of complex
      Complex c1(3, 9);
      Complex c2 = c1 + 10;
      cout << c2 << endl;

    return 0;
}

>>> (13, 9)
```

- Addition does not work when Complex is on the right and other type is on the left side


```c++
// Complex.h

// When double on left and Complex on the right side
    Complex operator+(double d, const Complex &c1);
```

```c++
// Complex.cpp

Complex operator+(double d, const Complex &c1){
        return Complex(d + c1.getReal(), c1.getImaginary());
}
```

```c++
#include <iostream>
#include "complex.h"
using namespace std;
using namespace complex;

int main() {

    Complex c(1, 1);
    cout << 6 + c << endl; 
    
    return 0;
}

>>> (7, 1)
```

### Overloading Equality Test

```c++
// Complex.h

// Complex class method

// Equals test
bool operator==(const Complex &other) const;

// Not equals test
bool operator!=(const Complex &other) const;
```

```c++
// Complex.cpp

// Equals test
bool Complex::operator==(const Complex &other) const {
    return real == other.real && imaginary == other.imaginary;
}

// Not equals test
bool Complex::operator!=(const Complex &other) const {
    // return real != other.real && imaginary != other.imaginary;
    return !(*this==other);
}
```

```c++
#include <iostream>
#include "complex.h"
using namespace std;
using namespace complex;

int main() {

    Complex c1(3, 4);
    Complex c2(3, 4);
    Complex c3(2, 7);

    if(c1 == c2){
        cout << "Equal" << endl;
    }
    else {
        cout << "Not Equal" << endl;
    }

    if(c2 != c3){
        cout << "Not Equal" << endl;
    }
    else {
        cout << "Equal" << endl;
    }

    return 0;
}

>>> Equal
>>> Not Equal
```

### Overloading De-reference Operator

- The complex conjugate of a complex number is the number with an equal real part and an imaginary part equal in magnitude but opposite in sign


```c++
// Complex.h

// Complex class method: Overloading * operator
Complex operator*() const;  // Return type: Complex object
```

```c++
// Complex.cpp

// Complex class method: Overloading * operator
Complex Complex::operator*() const{
    return Complex(real, -imaginary);
}
```

```c++
#include <iostream>
#include "complex.h"
using namespace std;
using namespace complex;

// Overloading + operator

int main() {

    Complex c(7, 15);
    cout << *c << endl;

    return 0;
}

>>> (7, -15)
```

### Templates

- One important thing about `template` classes is that it is not so easy to separate the implementation from the actual class. Usually with the class, the declaraion and prototype of its methods are put in a header `.h` file and the implementation is put in `.cpp` file. Then when the compiler compiles a program it has to only look at header to see that the class is used correctly. It can separately compile the `.cpp` file into a `.o` file. So the compiler initially compiles a bunch of `.o` files and at the end it links them all together. With templates, C++ has to see both the implementation `.cpp` and the definition `.h` files all together before it can compile the code, because behind the scenes C++ is going to create the class. If using `template` it is generally better to put implementation and definition in header `.h` file.

### Template Classes

- `template` classes allows to design classes that work with types of variables that the user can specify. For example the `vector` class, where the user has to specy the type. `vector` is a `template` class and that is why it is a member of STL. Template classes are not often useful in C++, but when they are useful they can be very useful.
- Use `template <class T>` just above the class declaration to turn the class into a template class. `T` is the letter that stands for the type that the user can specify. `T` can be any word, e.g. `Thing`, but it is common to use a single letter for the purpose as the user has to specify type. `T` is traditional letter to use for a generic template type. `T` can then be used in the class.

```c++
#include <iostream>
using namespace std;

template<class T>
class Test {
private:
    T obj;  // Variable of type T which will be defined by user

public:
    Test(T obj){ this->obj = obj; }
    void print() { cout << obj << endl; }
};

int main() {

    Test<string> test("Hello!");
    test.print();

    return 0;
}

>>> Hello!
```

- NOTE: If you define a template type you should not get into inquiring what type it is and calling specific methods on it because it kind of breaks the whole object oriented idea of defining objects in such a way that you can use them without interrogating the object type. So it is not good to have `if` statements, i.e. if object type is `string` do this, if object type is `int` do that, and so on.

- `template<class T, class K, ...>` is used to define multiple template types.

```c++
#include <iostream>
using namespace std;

template<class T, class K>
class Test {
private:
    T obj;  // Variable of type T which will be defined by user
    K val;  // Variable of type K which will be defined by user

public:
    Test(T obj, K val): obj(obj), val(val) {}
    void print() { cout << obj << " " << val << endl; }
};

int main() {

    Test<string, int> test("Hello", 7);
    test.print();

    return 0;
}

>>> Hello 7
```

### Template Functions

- Template function can be part of classes or template classes
- Use `template <class T>` just above the function declaration to turn the function into a template function. `template <typename T>` can also be used but `class T` is more common than `typename T`. NOTE: C++ does automatic type inference, i.e. C++ looks at arguments and infer what type is needed

```c++
#include <iostream>
using namespace std;

template<class T>
void print(T n){ cout << n << endl; }

int main() {

    print<string>("Hello");
    print<int>(15);

    // C++ does automatic type inference
    print("Crush");
    print(7);

    return 0;
}

>>> Hello
>>> 10
>>> Crush
>>> 7
``` 

### Type Inference

- Remember that functions can be overloaded as long as their argument list is different

```c++
#include <iostream>
using namespace std;

template <class T>
void print(T data){
    cout << "Template Version: " << data << endl;
}

void print(int value){
    cout << "Non Template Version: " << value << endl;
}

int main() {

    print<string>("Hello");
    print<int>(15);

    cout << endl;
    
    print("World");  // Uses template version becauses non template uses int
    print(7);  // Uses non template version
    print<>(7);  // Put at least <> to use template version of function
    
    return 0;
}

>>> Template Version: Hello
>>> Template Version: 15
>>> 
>>> Template Version: World
>>> Non Template Version: 7
>>> Template Version: 7
```

- There are situations in which your code is not going to compile so you can not use template function unless you put not only `<>` brackets but type as well.

```c++
#include <iostream>
using namespace std;

// Situation where <> and types must be used
template <class T>
void show(){
    cout << T() << endl;  // T() runs constructor of class T
}

int main() {

    //show<>(); // Error C++ can not infer type as there is no argument list.
    show<double>(); // Works, default value of double is used

    return 0;
}

>>> 0
```

### Function Pointers

- In C++ 11 one can use lambda expression as an alternative to function pointers. A pointer to a function can be declared the same way as a pointer to a variable can be declared. The function pointer can be passed around so in effect we can pass a block of code to another function. Function pointers are actually used even behind the scenes in C++, if you have been using `virtual` methods you have been using them implicitly. Because the `virtual` keyword is an instruction to call C++ to create a **v-table** (virtual table), which is a table of function pointers. So when you call a method in a child class via a pointer to the parent class type, C++ can do a lookup on the table of function pointers and find the right function to call.
- Declaring a pointer to a function: First thing needed is *a variable of right type (i.e. return type of function)*, and then *the variable can be pointed at a function*

```c++
#include <iostream>
using namespace std;

void test() { cout << "Hello" << endl; }

int main() {

    // Variable pTest is pointer to a function with void return type and no parameters
    void (*pTest)();

    // Point pointer to function
    pTest = &test;

	 // Need ( & ) to make sure that dereference operator * applies to pointer name
    (*pTest)();  
    

    return 0;
}

>>> Hello
```

- NOTE: `*pointerName()` - is ambiguous because this can be a call to function called `pointerName` which returns pointer to something, and then we are dereferencing the pointer that is returned. Solution: `(*pointerName)()` we need to use `(` and `)` to make sure that dereference operator `*` applies to `pointerName` before the `()` operator is applied.
- **The name of the function is in fact pointer to that function**, so `&` operator is not needed. Also we do not need `*` dereference operator

```c++
#include <iostream>
using namespace std;

void test() { cout << "Hello" << endl; }

int main() {

    void (*pTest)();

    pTest = test;  // Works without address reference
    
    pTest();  // Works without dereference operator

    return 0;
}

>>> Hello
```

- Function pointer to a function that takes parameters

```c++
#include <iostream>
using namespace std;

// Function that takes parameters
void print(string s) { cout << "String: " << s << endl; }

int main() {

    // Function with parameters
    void (*pPrint)(string) = print;  // Need to specify type in ()
    pPrint("Hello!");

    return 0;
}

>>> Hello!
```

### Using Function Pointers

- Use `count_if(start_iterator, end_iterator, pointer_to_function)` to return number of elements in range satisfying some condition`. Use `#include <algorithm>` to use `count_if`

```c++
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Checks string size matches criteria
bool match(string text){
    return text.size() == 3;
}

int main() {

    vector<string> texts;
    texts.push_back("one");
    texts.push_back("two");
    texts.push_back("three");
    texts.push_back("two");
    texts.push_back("one");

    // How many strings in vector match length equal to 3
    cout << count_if(texts.begin(), texts.end(), match) << endl;

    return 0;
}

>>> 4
```

- Implementing a function that uses function pointer

```c++
#include <iostream>
#include <vector>
using namespace std;

// Checks string size
bool match(string text){
    return text.size() == 3;
}

// Count function
int countStrings(vector<string> &data, bool (*test)(string)){
    int tally = 0;
    for(int i=0; i<data.size(); i++){
        if(test(data[i])){
            tally++;
        }
    }
    return tally;
}

int main() {

    vector<string> texts;
    texts.push_back("one");
    texts.push_back("two");
    texts.push_back("three");
    texts.push_back("two");
    texts.push_back("one");

    cout << countStrings(texts, match) << endl;

    return 0;
}

>>> 4
```

### Object Slicing and Polymorphism

```c++
#include <iostream>
using namespace std;

class Parent {
public:
    void print(){ cout << "Parent" << endl; }
};

class Child: public Parent {
public:
    void print(){ cout << "Child" << endl; }
};

int main() {

    Child c;
    c.print();

    // Reference to a parent class referring to any object of sub-class
    Parent &p = c;  
    
    p.print();  // Prints "Parent" instead of "Child"

    return 0;
}

>>> Child
>>> Parent  // Should be Child
```

- Since the method in Parent class is not `virtual` there is no lookup mechanism for C++ to find the right method to call. Making method `virtual` in Parent class solves the problem

```c++
#include <iostream>
using namespace std;

class Parent {
public:
    virtual void print(){ cout << "Parent" << endl; }
};

class Child: public Parent {
public:
    void print(){ cout << "Child" << endl; }
};

int main() {

    Child c;
    c.print();

    Parent &p = c;  
    p.print();  // Prints "Child" now

    return 0;
}

>>> Child
>>> Child
```

- When copy constructor is not implemented in Parent class and we use `Parent p = Child();`, then we are invoking implicit copy constructor

```c++
#include <iostream>
using namespace std;

class Parent {
public:
    virtual void print(){ cout << "Parent" << endl; }
};

class Child: public Parent {
public:
    void print(){ cout << "Child" << endl; }
};

int main() {
    // Invoking implicit copy constructor when copy constructor is not implemented
    Parent p = Child();      
    p.print();

    return 0;
}

>>> Parent
```

- `error`: constructor for 'Child' must explicitly initialize the base class 'Parent' which does not have a default constructor - This error is raised when copy constructor is implemented in Parent class with no default constructor. Error is raised when Child class inherits from Parent class because when we create Child classes, Child classes have to run constructor of the Parent class in order to be instantiated. So when we define a subclass we must eiter have a default constructor in the Parent class or we must specify what constructor we want to run in the Parent class. 

```c++
#include <iostream>
using namespace std;

class Parent {
public:
    virtual void print(){ cout << "Parent" << endl; }

    // Default Constructor
    Parent(){};

    // Copy Constructor
    Parent(const Parent &other){
        cout << "Copy Constructor: Parent" << endl;
    };
};

class Child: public Parent {
public:
    void print(){ cout << "Child" << endl; }
};

int main() {

    Parent p = Child();
    p.print();

    return 0;
}

>>> Copy Constructor: Parent
>>> Parent
```

- After implementing copy constructor in Parent class, why `Parent p = Child();` works. The reason it works is that `Parent(const Parent &other)` has reference to Parent class and you can assign an object of subclass of the Parent class to it. This gives rise to object slicing. For example a private variable `u` is created in Parent class and private variable `v` is added in Child class, then if `Parent p = Child();` is used Parent copy constructor can not copy `v` variable in Child class so variable `v` gets sliced off and thrown away.

```c++
#include <iostream>
using namespace std;

class Parent {
private:
    int u;
public:
    virtual void print(){ cout << "Parent" << endl; }

    Parent(): u(0) {};

    Parent(const Parent &other): u(0) {
        // u = other.u; // 
        cout << "Copy Constructor: Parent" << endl;
    };
};

class Child: public Parent {
private:
    int v;
public:
    // u is private variable so its scope is limited to class where it is defined
    //Child(): u(0){};
    Child(): v(0){};
    void print(){ cout << "Child" << endl; }
};

int main() {

    Parent p = Child();  
    p.print();

    return 0;
}

>>> Copy Constructor: Parent
>>> Parent
```

### Abstract Classes and Pure Virtual Functions

- Sometimes you want to create a class hierarchy and you want to have a base class but it does not make sense to instantiate it. For example, imagine you are going to create classes representing different kinds of *animals*. You might want those classes to derive from the same base class after all *dogs*, *cats*, etc are all types of *animals*, so it makes sense to derive frome same base class. But there is no sense in instantiating an *animal* class. So for this purpose we have an abstract class. **An abstract class is a class containing methods which have no implementation and these methods are called as pure virtual functions or methods**
- `virtual return_type functionName()=0` - The prototype of `functionName` is set to `0`. This notation means that there is no implementation of `functionName` and makes `functionName` a pure virtual function. And the class which contains pure virtual functions is called abstract class.

```c++
#include <iostream>
using namespace std;

class Animal {
public:
    Animal(){};
    virtual void speak()=0;  // Pure virtual function
};

class Dog: public Animal {
public:
    virtual void speak(){ cout << "Woof!" << endl; }
};

int main() {
    
    //Animal animal; // error: variable type 'Animal' is an abstract class
    
    Dog dog;
    dog.speak();

    return 0;
}

>>> Woof!
```

- In your subclasses you have to implement all pure virtual functions declared in Parent class if you want to be allowed to instantiate your subclass.

```c++
#include <iostream>
using namespace std;

class Animal {
public:
    Animal(){};
    virtual void speak()=0;
    virtual void run()=0;  // Now Dog can not be instantiated
};

class Dog: public Animal {
public:
    virtual void speak(){ cout << "Woof!" << endl; }
};

class Doberman: public Dog {
public:
    virtual void run() { cout << "Running" << endl; }
};

int main() {

    //Dog dog;  // error: variable type 'Dog' is an abstract class

    Doberman dog;
    dog.speak();
    dog.run();

    return 0;
}

>>> Woof!
>>> Running
```

- An array of abstract base class can not be created because when you create an array of objects the constructor of objects are run and we can not run the constructor (or copy constructor) of abstract base class to instantiate it.

```c++
int main() {

    Animal animals[3];

    return 0;
}

>>> error: array of abstract class type 'Animal'
>>> note: unimplemented pure virtual method 'speak' in 'Animal'
>>> note: unimplemented pure virtual method 'run' in 'Animal'
```

- An array of pointers to abstract base class can be created.

```c++
#include <iostream>
using namespace std;

class Animal {
public:
    Animal(){};
    virtual void speak()=0;
    virtual void run()=0;  // Now Dog can not be instantiated
};

class Dog: public Animal {
public:
    virtual void speak(){ cout << "Woof!" << endl; }
};

class Doberman: public Dog {
public:
    Doberman(){ cout << "Doberman" << endl; }
    virtual void run() { cout << "Running" << endl; }
};

void test(Animal &a) {
    a.speak();

int main() {

    Doberman dog;

    Animal *animals[1];
    animals[0] = &dog;
    animals[0]->speak();
    
    test(dog);

    return 0;
}

>>> Doberman
>>> Woof!
>>> Woof!  // test result
```

### Functors

- Functors are another way of passing blocks of codes to functions. They are kind of alternative to function pointers. There are some things you can do with functors that you can not do with function pointers.
- Overloading `()` operator - Round brackets, i.e. `()`, are operator and they are different to every other operator in C++. They can take a variable list of arguments, they can take no arguments or as many arguments as needed. So `()` operator is the only operator that can take a variable list of arguments.
- Functor is a `class` or `struct` that among other things overloads `()` operator. 

```c++
#include <iostream>
using namespace std;

// This is a functor
struct MatchTest {
    bool operator()(string &text){ // First () is for overriding ()
        return text == "lion";
    }
};

int main() {

    MatchTest tester;

    string value = "lion";

    cout << tester(value) << endl;
    /*
     * Looks like a function call but it is not. It is round brackets 
     * operators being applied using MatchTest object to value
     */

    return 0;
}

>>> 1
```

- NOTE: We can not pass literal values e.g. `tester("lion")` if function argument is a reference.

- Passing functor to other functions - The idea is that function can apply different kinds functors, i.e. we want to be able to pass different types of functors to the function and we can achieve this by having a base class of functor.

```c++
#include <iostream>
using namespace std;

// Base struct
struct Test {
    virtual bool operator()(string &text)=0;  
    virtual ~Test(){}
};

struct MatchTest: public Test {
    bool operator()(string &text) { 
        return text == "lion";
    }
};

// Passing functor to a function
void check(string text, Test &test){
/*
 * Need to pass a reference for polymorphism to operate correctly, i.e. 
 * must be a reference if we want to pass in different functors
 * /
        if(test(text)){
            cout << "Text matches!" << endl;
        } else {
            cout << "No match!" << endl;
        }
}


int main() {

    string value = "lions";
    MatchTest tester;
    
    check(value, tester);  // Passing functor to a function
    
    return 0;
}

>>> No match!
```

# C++ 11

### Decltype, Typeid, and Name Mangling

- Use `#include <typeinfo>` to use `typeid` function. `typeid(object)` returns type information about `object` and `typeid(object).name()` returns name of type.
	- `i` - Integer type, `d` - Double type, etc.
	- When `typeid` is used on `string object` to get name of type, a complex string is returned. C++ does name mangling where it takes names of the things like variables and functions and adds a few characters to them to get more information about what those are, so the returned output gives a lot of information about `string` type
- `decltype` - Allows to declare variables of existing type

```c++
#include <iostream>
#include <typeinfo>
using namespace std;

int main() {

    int value;
    cout << typeid(value).name() << endl;

    double number;
    cout << typeid(number).name() << endl;
    
    string text;
    decltype(text) name = "Crush";  // Declare variable of existing type
    cout << name << endl;
    cout << typeid(name).name() << endl;

    return 0;
}

>>> i
>>> d
>>> Crush
>>> NSt3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEE
```

### auto Keyword

- In C++ 98 `auto` is the default storage class specifier, so for example `auto int x = 1` is used. In C++ 11 `auto` has been extended and *type declaration can be missed out*, for example `auto x = 1` (`int` is missed out) and C++ automatically infers the type by looking at initialized value.

```c++
#include <iostream>
#include <typeinfo>
using namespace std;

int main() {

    auto value = 7;
    cout << typeid(value).name() << endl;

    auto text = "Hello";
    cout << text << endl;

    return 0;
}

>>> i
>>> Hello
```

- `auto` can also be used to infer return type of functions. C++ introduces *trailing return types* - `auto functionName() -> type;`. 

```c++
#include <iostream>
using namespace std;

//auto test() { return 15; } // Does not work
auto test() -> int { return 15; }  // Trailing return types

int main() {

    cout << test() << endl;
    
    return 0;
}

>>> 15
```

- *Trailing return type* is useful if using `template` functions. Use `decltype` to inquire about type and use it with *trailing return types*. NOTE: Functions can be called in `decltype`.

```c++
#include <iostream>
#include <typeinfo>
using namespace std;

template <class T>
auto check(T value) -> decltype(value) { return value; }

template <class T, class K>
auto check(T value1, K value2) -> decltype(value1 + value2) { 
    return value1 + value2;
}

int get(){ return 75; }

auto func() -> decltype(get()){
    return get();
}

int main() {

    auto text = "Hello";
    cout << check(text) << endl;

    cout << check(3, 9) << endl;
    
    cout << func() << endl;

    return 0;
}

>>> Hello
>>> 12
>>> 75
```

### Range Based For Loop using `auto`

- Create a `string` array - `string array[] = {"one", "two"}`. Using `auto` to create a `string` array - `auto array = {"one", "two"}`, so no need to use type declaration and `[]`
- `for(auto i: array){ ... }` - `auto` will give variable of right type. For loop will initialize the variable and set the value of it to each of the values in the `array` in turn

```c++
#include <iostream>
using namespace std;

int main() {

    string texts[] = {"one", "two", "three"};

    for(auto text: texts){
        cout << text << endl;
    }
    return 0;
}

>>> one
>>> two
>>> three
```

```c++
#include <iostream>
#include <vector>
using namespace std;

int main() {

    vector<int> numbers;
    numbers.push_back(1);
    numbers.push_back(3);
    numbers.push_back(5);

    for(auto i: numbers){
        cout << i << endl;
    }
    return 0;
}

>>> 1
>>> 3
>>> 5
```

### Implementing a `template` class and `iterator`

- Ring Buffer Class - A ring buffer or a circular buffer is some kind of area of memory which you can write to when you get to the end of it, if you keep writing it starts writing to the beginning. This is often used in multimedia applications because you can write to the buffer and you can read just a bit head of it. And when you run out of memory instead of stopping read and write it just cycles on around the same bit of memory. Nested `template` classes are needed to implement `iterator` syntax for ring buffer class.
- Because we are implementing a `template` class we need to put declarations and implementations of `template` class in `ClassName.h` file (`ClassName.cpp` is deleted)

```c++
class ring {
public:
    class iterator {
    public:
        void print(){ cout << "Hello from iterator!" << endl; }
    };
};
```

- The above nested class syntax is widely used but in general this is not a good practice because the nesting level is going to get deep and will look confusing. So good practice is to take inner implementation outside of the class. However with `template` classes, separating out implementations is tricky and involves hacks.

```c++
// ring.h

#ifndef RING_H
#define RING_H

#include <iostream>
using namespace std;

template <class T>
class ring {
public:
    class iterator;  // Need this here
};

// Inner iterator class separated out from outer ring class
template <class T>
class ring<T>::iterator {  // Do not want iterator to have its own template
public:
    void print(){ cout << "Hello from iterator!"  << T() << endl; }
};

#endif //RING_H
```

```c++
#include <iostream>
#include "ring.h"
using namespace std;

int main() {

    ring<string>::iterator it;
    it.print();

    return 0;
}

>>> Hello from iterator!
```

- Implementing Ring Buffer Class

```c++
// ring.h

#ifndef RING_H
#define RING_H

#include <iostream>
using namespace std;

template <class T>
class ring {
private:
    int m_position;
    int m_size;
    T *m_values;  // Need an array of type T to store values

public:
    class iterator;

public:

    // Constructor that takes params
    ring(int size): m_position(0), m_size(size), m_values(NULL){
        m_values = new T[m_size];  // Allocate memory of appropriate size
    }

    // Destructor to de-allocate memory
    ~ring(){
        delete [] m_values;
    }

    // Method to return size
    int size(){ return m_size; }

    // Method to add data to buffer
    void add(T value){
        m_values[m_position] = value;  // Add value

        // Increment buffer
        m_position ++;

        if(m_position == m_size){
            m_position = 0;
        }
    }

    // Get method
    T &get(int pos){  // Return a reference of type T (more efficient)
        return m_values[pos];
    }

};

template <class T>
class ring<T>::iterator {};

#endif //RING_H
```

```c++
#include <iostream>
#include "ring.h"
using namespace std;

int main() {

    ring<string> texts(3);

    texts.add("one");
    texts.add("two");
    texts.add("three");
    texts.add("four");

    for(int i=0; i<texts.size(); i++){
        cout << texts.get(i) << endl;
    }

    return 0;
}

>>> four
>>> two
>>> three
```

- Implementing Ring Buffer Class `iterator`


```c++
// ring.h

#ifndef RING_H
#define RING_H


#include <iostream>
using namespace std;

template <class T>
class ring {
private:
    int m_position;
    int m_size;
    T *m_values;

public:
    class iterator;

public:

    ring(int size): m_position(0), m_size(size), m_values(NULL){
        m_values = new T[m_size];
    }

    ~ring(){
        delete [] m_values;
    }

    int size(){ return m_size; }

    void add(T value){
        m_values[m_position] = value;  

        // Increment buffer
        m_position ++;

        if(m_position == m_size){
            m_position = 0;
        }
    }

    T &get(int pos){  
        return m_values[pos];
    }

    // Begin method returns iterator
    iterator begin(){
        return iterator(0, *this); // (position, reference to ring object)
    }

    // End method returns iterator
    iterator end(){
        return iterator(m_size, *this);
    }
};

template <class T>
class ring<T>::iterator {
private:
    int m_position;
    ring &m_ring;

public:
    // Constructor
    iterator(int pos, ring &r_ring): m_position(pos), m_ring(r_ring){}

    // Postfix ++ operator overloading
    iterator &operator++(int){  // Postfix ++ takes int parameter do differentiate
        iterator old = *this;
        ++(*this);
        return old;
    }

    // Prefix ++ operator overloading
    iterator &operator++(){  
        ++m_position;
        return *this;
    }

    // * operator overloading (used in *it when using for loop)
    T &operator*(){  // Return reference to existing item in the ring
        return m_ring.get(m_position);
    }

    // == operator overloading
    bool operator==(const iterator &other) const {
        return m_position == other.m_position;
    }

    // != operator overloading
    bool operator!=(const iterator &other) const {
        return !(*this == other);
    }
};

#endif //RING_H
```

```c++
#include <iostream>
#include "ring.h"

int main() {

    ring<string> texts(3);

    texts.add("one");
    texts.add("two");
    texts.add(("three"));
    texts.add("four");

    // C++ 98 style
    for(ring<string>::iterator it = texts.begin(); it != texts.end(); it++){
        cout << *it << endl;
    }

    cout << endl;

    // C++ 11 style
    for(auto text: texts){
        cout << text << endl;
    }
    
    return 0;
}

>>> four
>>> two
>>> three
>>> 
>>> four
>>> two
>>> three
```

### Initialization using { } in C++ 98

- In C++ 11 `{}` can be used to initialize things.

```c++
    // Using {} to initialize an array
    int value[] = {1, 3, 5};
    cout << value[1] << endl;
    
>>> 3
```

- Using `{}` to initialize *public* member variables of a `class` or `struct` - Initialization using `{}` is more commonly used in `struct` because its member variables are public by default.

```c++
#include <iostream>
#include <vector>
using namespace std;

class C {
public:
    string text;
    int id;
};

struct S {
    string text;
    int id;
};

int main() {

    // Using {} to initialize public member variables of a class or struct
    C c_obj = {"Hello", 7};
    cout << c_obj.text << endl;

    S s_obj = {"World", 15};
    cout << s_obj.text << endl;
    
    return 0;
}

>>> Hello
>>> World
```

```c++
    // Initializing vector
    vector<int> v_obj; 
    v_obj.push_back(1);  // Tedious to call push_back
    v_obj.push_back(2);
    v_obj.push_back(3);
    for(auto i: v_obj){ cout << i << endl; }
    
>>> 1
>>> 2
>>> 3
```

### Initialization using { } in C++ 11

- A variable can be initialized in C++ 11 by using `type variable{value}`

```c++
    int value{7};
    cout << value << endl;

    string text{"Hello"};
    cout << text << endl;
    
>>> 7
>>> Hello
```

- Initializing an array

```c++
    int numbers[]{1, 3, 7};
    cout << numbers[1] << endl;
    
>>> 3
```

- Initializing a pointer to an int

```c++
    int value{7};
    int *pVal{&value};
    cout << pVal << ": " << *pVal << endl;
    
>>> 0x7fff583c45f8: 7
```

- Initializing pointer to an array

```c++
    int *pInt = new int[3]{2, 4, 8}; // Need to specify number of elements in []
    cout << pInt[1] << endl;
    delete pInt;
    
>>> 4
```

- Initializing default values using empty `{}`

```c++
    int u{};
    cout << "u: " << u << endl;

    string s{};
    cout << "s: " << s << endl;
    
    // Initializing an array of 0's
    int array[3]{};
    cout << array[2] << endl;
    
>>> u: 0
>>> s:
>>> 0
```

- `nullptr` - A null pointer. It can not be cast into an `int` and it is used specifically to initialize pointers.

```c++
    double *pNum{};  // Equivalent to double *pNum = nullptr;
    cout << pNum << endl;
    
>>> 0x0
```

- Initializing a vector

```c++
    vector<string> t{"Crush"};  // No need to use t.push_back(...)
    cout << t[0] << endl;
    
>>> Crush
```

- Anonymous `struct`

```c++
	struct {
        int value;  
        // int value = 5; error: implicit constructor lost so implement constructor
        string text;
    } c{6, "Crush"};
    cout << c.text << endl;
    
>>> Crush
```

### Initializer Lists

- Use `#include <initializer_list>` to use `initializer_list` template type.
- `initializer_list` is iterable using `for` loop

```c++
#include <iostream>
#include <vector>
#include <initializer_list>
using namespace std;

class Test {
public:
    Test(initializer_list<string> texts){
        // Accessing values from the list in constructor
        for(auto t: texts){ cout << t << endl; }
    }

    // Method that uses initializer list
    void print(initializer_list<string> texts){
        for(auto t: texts){ cout << t << endl; }
    }
};


int main() {

    Test test{"Apple", "Orange", "Mango"};
    cout << endl;
    
    test.print({"one", "two", "three"});

    return 0;
}

>>> Apple
>>> Orange
>>> Mango
>>> 
>>> one
>>> two
>>> three
```

### Object Initialization, `default` and `delete`

- If member variables in a class are initialized, then all the objects of that class will have their member variables initialized

```c++
#include <iostream>
using namespace std;

class Test {
    int id{7};
    string name{"Crush"};

public:
    void print(){ cout << id << ": " << name << endl; }
};

int main() {

    Test t;
    t.print();

    return 0;
}

>>> 7: Crush
```

- If a constructor is defined that takes an argument and uses that argument to initialize a member variable. The constructor is going to run after the member variables are created and initialized, so the constructor will override the default initializations. This works for copy constructors as well.
- If you define any constructor in C++, then you are going to loose the implicit constructor. C++ 11 provides a way to create implicit constructors by setting constructor equal to `default`

```c++
#include <iostream>
using namespace std;

class Test {
    int id {7};
    string name {"Crush"};

public:
    Test() = default;  // Create implicit constructor
    Test(const Test &other)= default;  // Copy constructor
    Test(int id): id(id){}

    void print(){ cout << id << ": " << name << endl; }
};

int main() {

    Test t;
    t.print();

    Test s(3);
    s.print();

    // Using copy constructor
    Test u = s;
    u.print();

    return 0;
}

>>> 7: Crush
>>> 3: Crush
>>> 3: Crush
```

- Sometimes you do not want default implementation, for example there is implicit `=` operator, and we can make it explicit

```c++
#include <iostream>
using namespace std;

class Test {
    int id {7};
    string name {"Crush"};

public:
    Test() = default;  // Create implicit constructor
    Test(const Test &other) = default;  // Copy constructor
    Test &operator=(const Test &other) = default; // Explicit = operator
    Test(int id): id(id){}
    void print(){ cout << id << ": " << name << endl; }
};

int main() {

    Test t;
    t.print();

    Test s(3);
    s.print();

    // Using copy constructor
    Test u = s;
    u.print();

    // Using assignment operator
    s = t;
    s.print();

    return 0;
}

>>> 7: Crush
>>> 3: Crush
>>> 3: Crush
>>> 7: Crush
```

- If you want to make an object unable to copy other object then use `delete` to delete imlementations

```c++
#include <iostream>
using namespace std;

class Test {
    int id {7};
    string name {"Crush"};

public:
    Test() = default;  // Create implicit constructor
    Test(const Test &other) = delete;  // Delete implementation of copy constructor
    Test &operator=(const Test &other) = delete; // delete implementation of = operator
    Test(int id): id(id){}
    void print(){ cout << id << ": " << name << endl; }
};

int main() {

    Test t;
    t.print();

    Test s(3);
    s.print();

    // Using copy constructor
    Test u = s;  // Error because copy constructor implementation deleted
    u.print();

    // Using assignment operator
    s = t;  // Error because = operator implementation deleted
    s.print();

    return 0;
}
```

### Lambda Expressions

- Lambda expression is a function which does not have a name and it can be passed around. `[]` are distinctive feature of lambda expressions that enable them to be recognized. `[](){}` is a valid lambda expression, the code is written inside `{}`. The function can be stored in a variable using `auto`, i.e. the reference to anonymous function is stored in a variable using `auto`

```c++
#include <iostream>
using namespace std;

void test(void (*p_func)()){
    p_func();
}

int main() {

    // Defining lambda expression and calling it
    [](){ cout << "Crush" << endl; }();

    // Storing reference to lambda function
    auto func = [](){ cout << "Hello!" << endl; };
    func();

    // Passing lambda expression to a function
    test(func);

    cout << "func: " << func << endl;

    return 0;
}

>>> Crush
>>> Hello!
>>> Hello!
>>> func: 1
```

### Lambda Expression Parameters and Return Type

- Using `auto` C++ can infer return types so there is no need to specify return type in lambda expression. This works fine as long as there is one return statement, if there are multiple return statements (i.e. multiple return types) then C++ can not infer what return type should be and this causes error. If there are **multiple return types** in lambda expression then use **trailing return type** syntax 

```c++
#include <iostream>
using namespace std;

void testGreet(void (*p_greet)(string)){
    p_greet("Crush");
}

int main() {

    // Lambda expression that takes parameters
    auto greet = [](string name){ cout << "Hello " << name << endl; };
    greet("Ankoor");
    
    auto add = [](int x, int y){ return x + y; };
    cout << add(7, 6) << endl;
    
    auto divide = [](double x, double y){ return x / y; };
    cout << divide(9, 3) << endl;

	 // Passing lambda function to a function
    testGreet(greet);

    return 0;
}

>>> Hello Ankoor
>>> 13
>>> 3
>>> Hello Crush
```

```c++
   // Multiple return types error
	auto divide = [](double a, double b)  {
        if(b == 0.0){
            return 0;
        } else {
            return a / b; 
        }
    };
    
# error: return type 'double' must match previous return type 'int' when
# lambda expression has unspecified explicit return type
```

- Use *trailing return type* `-> type` between `[]()` and `{}` when defining lambda expression with multiple return types

```c++
#include <iostream>
using namespace std;

void runDivide(double (*p_divide)(double a, double b)){
    cout << p_divide(9, 3) << endl;
}

int main() {

    auto divide = [](double a, double b) -> double { // Trailing return type
        if(b == 0.0){
            return 0;
        } else {
            return a / b;
        }
    };

    cout << divide(9, 4) << endl;

    runDivide(divide);

    return 0;
}

>>> 2.25
>>> 3
```

### Capture Expressions in Lambda Expressions

- Value of a local variable can not be immediately used by lambda expression because lambda expression has its own scope.

```c++
	int v = 7;
	[](){ cout << v << endl; }();  // Error
	
# error: variable 'v' cannot be implicitly captured in a lambda with no 
# capture-default specified
```

- Use `[]` to capture local variables

```c++
	int v = 7;
	int w = 3;
	
	// Capture by value
	[v](){ cout << v << endl; }(); 
	[v, w](){ cout << v + w << endl; }();
	
>>> 7
>>> 10
```

- Use `[=]` to capture all the local variables

```c++
	int v = 7;
	int w = 3
	// Capture all local variables by value
    [=](){ cout << v + w << endl; }();
    
>>> 10
```

- Use `[&]` to capture all the local variables by reference

```c++
	int v = 7;
	int w = 3;
	
	// Capture all local variables by reference
    [&](){ v = 2; w = 4; cout << v + w << endl; }();
    
>>> 6
```

- Capture some local variables by value and others by reference - The `=` sign has to be the first symbol in `[]`, then specify all the local variables that need to be captured by reference.

```c++
	int v = 7;
	int w = 3;
	// Capture some local variables by value and other by reference
   [=, &w](){ w = 7; cout << v + w << endl; }();

>>> 14
```

- Capture all local variables by reference but a few variables by value

```c++
	int v = 7;
	int w = 3;
	// Capture all local variables by reference but a few by value
   [&, w](){ v = 3; cout << v + w << endl; }();

>>> 6
```

### Capturing `this` in Lambda Expressions

```c++
class Test {
private:
    int u{1};
    int v{2};
public:
    void run(){
        // Local variables x and y
        int x{6};
        int y{7};

        auto lambda = [x, y](){
            cout << x << " and " << y << endl;
            cout << u << " and " << v << endl;
        };
        lambda();
    }
};
```

- In the above code snippet we can not capture `u` and `v` private member variables in lambda expression because of *error: 'this' can not be implicitly captured in this context*. Solution: Instance variables are captured by reference, so capture `this` in `[]` and `this` can be the first symbol, or last symbol or anywhere. NOTE: `[=, this]` is not allowed because of error, but `[&, this]` is allowed.

```c++
#include <iostream>
using namespace std;

class Test {
private:
    int u{1};
    int v{2};
public:
    void run(){
        // Local variables x and y
        int x{6};
        int y{7};

        auto lambda = [this, x, y](){
            cout << x << " and " << y << endl;
            this->u = 15; v = 7;
            cout << u << " and " << v << endl;
        };
        lambda();
    }
};

int main() {

    Test t;
    t.run();

    return 0;
}

6 and 7
15 and 7  // Initial u = 1 and v = 2
```

### `mutable` Lambda Expression

- If a variable is captured by value the lambda expression does not allow to assign value to that variable and this results in *error: cannot assign to a variable captured by copy in a non-mutable lambda*


```c++
#include <iostream>
using namespace std;

int main() {

    int dogs = 7;
    [dogs]()  {
        dogs = 15;
        cout << "lambda expression scope: " << dogs << endl;
    }();

    cout << "outside lambda expression: " << dogs << endl;

    return 0;
}

# error: cannot assign to a variable captured by copy in a non-mutable lambda
```

- Use `mutable` between `[variable]()` and `{}`. This makes a variable *mutable* within the scope of lambda expression

```c++
#include <iostream>
using namespace std;

int main() {

    int dogs = 7;
    [dogs]() mutable {
        dogs = 15;
        cout << "lambda expression scope: " << dogs << endl;
    }();

    cout << "outside lambda expression: " << dogs << endl;

    return 0;
}

>>> lambda expression scope: 15
>>> outside lambda expression: 7
```

### Standard Function Type

- We can pass in anything that is callable to `count_if` - How does it do that? - It uses standard function type. NOTE: `string s = "Text"; s.size();` returns size of a string.

```c++
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function
bool check(string &s){
    return s.size() == 5;
}

// Functor
class Test {
public:
    bool operator()(string &t){
        return t.size() == 5;
    }
} t_obj;  // Pass t_obj to count_if

int main() {

    // Passing lambda expression to count_if
    int size = 3;
    vector<string> texts{"one", "two", "three"};
    long int c = count_if(texts.begin(), texts.end(),
                          [size](string s){ return s.size() == size; });
    cout << c << endl;

    // Passing function pointer to count_if
    c = count_if(texts.begin(), texts.end(), check);
    cout << c << endl;

    // Passing functor to count_if
    c = count_if(texts.begin(), texts.end(), t_obj);
    cout << c << endl;

    return 0;
}

>>> 2
>>> 1
>>> 1
```

- Standard Function Type - It is a nice convienence in C++ 11 that lets you define a type equivalent to what it can be used to reference any callable type (i.e. anything that you can call with round brackets) in C++ 11. Use `#include <functional>` and use `function` to define a function that can accept anything callable. Add `function<return_type(&type)> name` in a functions `()` to make a function accept anything callable.

```c++
#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
using namespace std;

// Function
bool check(string &s){
    return s.size() == 5;
}

// Functor
class Test {
public:
    bool operator()(string &t){
        return t.size() == 5;
    }
} t_obj;  // Pass t_obj to count_if

void run(function<bool(string&)> check){  // run can accept anything that is callable
    string t = "crush";
    cout << check(t) << endl;
}

int main() {

    // Using a function that can accept anything callable
    int size = 3;
    auto lambda = [size](string s){ return s.size() == size; };
    run(lambda); // Lambda expression
    run(check);  // Function pointer
    run(t_obj);  // Functor

    return 0;
}

>>> 0
>>> 1
>>> 1
```

```c++
    // Handy way of creating a type that is callable
    function<int(int, int)> add = [](int x, int y){ return x + y; };
    cout << add(7, 3) << endl;
    
>>> 10
```

### Delegating Constructor

- When a *child* class object is constructed it must run constructor in *parent* class. *Parent* class constructors are not inherited, i.e. *Parent* class constructors can not be called from *child* class, but they do exist in *child* class. In *parent* class if there is no default constructor and you define a constructor that takes parameters then the default implementation of no parameter constructor is lost. *Child* class is trying to run that constructor but it can not so we get compilation error. Solution: In *child* class specify which constructor from *parent* class to run.

```c++
#include <iostream>
using namespace std;

class Parent {
private:
    int id;
    string text;
public:
    Parent(){
        id = 7;
        cout << "No parameter Parent constructor" << endl;
    }
    Parent(string text){
        id = 7;
        this->text = text;
        cout << "string parameter Parent constructor" << endl;
    }
};

class Child: public Parent {
public:
    Child(): Parent("Hello"){}
};

int main() {

    Parent parent("Crush");
    Child child;

    return 0;
}

>>> string parameter Parent constructor
>>> string parameter Parent constructor
```

- In C++ 11, we can select what constructor we want to use if there are several different constructors in *parent* class, and this is called *delegating constructor*. In C++ 98 we could not call one constructor from another within a class. NOTE: Good practice is to avoid recursion, pick either no parameter constructor or constructor with most parameters and call that from other constructors.

```c++
#include <iostream>
using namespace std;

class Parent {
private:
    int id;
    string text;
public:
    Parent(): Parent("Hello"){  // Calling constructor with parameter within class
        id = 7;
        cout << "No parameter Parent constructor" << endl;
    }
    Parent(string text){
        id = 7;
        this->text = text;
        cout << "string parameter Parent constructor" << endl;
    }
};

class Child: public Parent {
public:
    Child() = default; // NOTE: Can not use Parent() = default; in Parent class
};

int main() {

    Parent parent("Crush");
    Child child;

    return 0;
}

>>> string parameter Parent constructor
>>> string parameter Parent constructor  // Called by child
>>> No parameter Parent constructor  // Called by child
```

### Elision and Optimization

- In C++ computer programing, copy *elision refers to a compiler optimization technique that eliminates unnecessary copying of objects*. GCC provides the `‑fno‑elide‑constructors` option to disable copy elision, however it is not a good idea to disable copy elision.

```c++
#include <iostream>
using namespace std;

class Test {
public:
    Test(){ cout << "Constructor" << endl; }
    Test(int i){ cout << "Parameterized Constructor" << endl; }
    Test(const Test &other){ cout << "Copy Constructor" << endl; }
    Test &operator=(const Test &other){
        cout << "Overridden assignment" << endl;
        return *this;
    }
    ~Test(){ cout << "Destructor" << endl; }

    friend ostream &operator<<(ostream &out, const Test &test);
};

ostream &operator<<(ostream &out, const Test &test){
    out << "Hello from test";
    return out;
}

// Function that returns object of type Test
Test getTest(){
    return Test();
}

int main() {

    Test t;
    cout << t << endl;

    Test s = getTest();
    cout << s << endl;

    return 0;
}
```

- C++ can do Return Value Optimization which involves eliding or getting rid of extra copies of objects. Extra copies happen in a situation where you are running some object from a function and you are using it to initialize another object outside of the function, e.g. `Test s = getTest();`

- Extra copies example using `vector`

```c++
	 // Problem: Extra copies
    vector<Test> vec;
    vec.push_back(Test());

>>> Constructor
>>> Copy Constructor
>>> Destructor
>>> Destructor
```

### Allocating Memory (Tips and Tricks)

- There are 3 efficient ways to set memory to  zero (Common thing you want to do if you create a buffer is to set all the bytes in the buffer to zero, this tend to help you reduce bugs, because then you know that buffer should be zero until you have written to it)
	- Use `memset`
	- Use `m_pBuffer = new type [SIZE]()`
	- Use `m_pBuffer = new type [SIZE]{}`
- Use `memcpy` to copy bytes from one to another.
- NOTE: There aer tools that can detect memory leaks. Memory leaks are often hard to spot.

```c++
#include <iostream>
using namespace std;

class Test {
private:
    static const int SIZE = 100;  // Number of ints in a buffer
    int *m_pBuffer;
public:
    Test(){
        cout << "Constructor" << endl;
        m_pBuffer = new int [SIZE]{};  // Allocating memory
    }

    Test(int i){
        cout << "Parameterized Constructor" << endl;
        m_pBuffer = new int [SIZE]{};  // Allocating memory
        for(int i=0; i<SIZE; i++){
            m_pBuffer[i] = 7 * i;
        }
    }

    Test(const Test &other){
        cout << "Copy Constructor" << endl;

        // Allocate byte and copy the bytes from other object using memcopy
        m_pBuffer = new int [SIZE]{};  // Allocating memory
        memcpy(m_pBuffer, other.m_pBuffer, sizeof(int)*SIZE);  // Copy bytes from other

    }

    Test &operator=(const Test &other){
        cout << "Overridden assignment" << endl;
        m_pBuffer = new int [SIZE]{};  // Allocating memory
        memcpy(m_pBuffer, other.m_pBuffer, sizeof(int)*SIZE);  // Copy bytes from other
        return *this;
    }

    ~Test(){
        cout << "Destructor" << endl;
        delete [] m_pBuffer;
    }

    friend ostream &operator<<(ostream &out, const Test &test);
};

ostream &operator<<(ostream &out, const Test &test){
    out << "Hello from test";
    return out;
}

// Function that returns object of type Test
Test getTest(){
    return Test();
}

int main() {

    Test t;
    cout << t << endl;

    return 0;
}

>>> Constructor
>>> Hello from test
>>> Destructor
```

### Rvalues and Lvalues

- In the example `int u = 7;`, `u` is an *Lvalue* and `7` is an *Rvalue*, because `u` is on the left of `=` and `7` is on its right. C++ 11 extends the definition of *Lvalues* and *Rvalues*. In C++ 11, a *Lvalue* is anything you can take the address of. 
- In the example `int *p = &u;`, `u` is an *Lvalue* so the examples works, but `int *p = &7;` does not work because `7` is an *Rvalue* and we **can not take address of Rvalues**. `int *s = &(7 + value);` will not work because `(7 + value)` becomes an *Rvalue*
- Return values of a function are *Rvalues* and *Rvalues* are often temporary values.

```c++
	Test test = getTest();  // getTest() output is an Rvalue
	Test *ptest = &test;  // Taking address of
	
	// Test *pt = &getTest; // Error: Can not take address of Rvalue
```

- Prefix and postfix increment operator example

```c++
	int value = 7;
	int *pvalue = &++value;  // Prefix operator increments value and uses it
	cout << *pvalue << endl;
	
	int *pValue = &value++;  // Error 
	 
>>> 8
>>> Error: Because postfix operator needs to use the value and then increment it
>>> this creates a temporary copy of the value.
```

### Lvalue References

- The references in C++ 98 are called *Lvalue* references in C++ 11. *Lvalue* reference is a normal kind of reference. We can only bind *Lvalue* references to *Lvalues*. However, `const` *Lvalue* references can bind to *Rvalues*, because lifetime of the *Rvalue* gets extended beyond the lifetime it would normally have.

```c++
	Test test = getTest();  // getTest() output is an Rvalue
	
	// Binding Lvalue reference to Lvalue
	Test &lv_test = test;  
	
	// Binding Lvalue reference to Rvalue
	Test &rv_test = getTest();  // Error
	
# error: non-const lvalue reference to type 'Test' cannot bind to a 
# temporary of type 'Test'
```

- Binding *Lvalue* reference to *Rvalue* using `const`. Also remember that the copy constructor always has a `const` *Lvalue* reference parameter to it, e.g. `const Test &other`

```c++
	const Test &rv_test = getTest();
	
	Test t(Test());  // Copy constructor
```

### Rvalue References

- *Rvalue* references gives us a way to differentiate between temporary values and non-temporary values or more precisely *Rvalues* and *Lvalues*. Functions return temporary values. Use `&&` to define *Rvalue* reference. NOTE: We can not bind *Rvalue* reference to an *Lvalue*

```c++
	Test = test = getTest();
	Test &lvr_test = test;  // Lvalue reference pointing at an Lvalue
	
	Test &&test_ = test;  // Error: Can not bind Rvalue reference to an Lvalue
	
	// Rvalue reference pointing at an Rvalue
	Test &&rvr_test = Test() 
	Test &&rvr_test_ = getTest(); 
``` 

- Function that takes *Rvalue* reference - We do not need `const` *Rvalue* reference because they can *change values and steal resources from objects you no longer need* and they can only do that if they are not `const`

```c++
// Function that takes Lvalue reference
void check(const Test &value){
    cout << "Lvalue function" << endl;
}

// Function that takes Rvalue reference
void check(Test &&value){ 
    cout << "Rvalue function" << endl;
}

int main() {

    Test test = getTest();

    check(test);
    check(getTest());
    check(Test());

    return 0;
}

>>> Lvalue function
>>> Rvalue function
>>> Rvalue function
```

### Move Constructor

- Move constructor looks a lot like a copy constructor except is uses *Rvalue* reference. Move constructor has to take a mutable *Rvalue* reference, it can not be `const` as it has to change *other*

```c++
#include <iostream>
#include <vector>
using namespace std;

class Test {
private:
    static const int SIZE = 100;
    int *m_pBuffer{nullptr};
public:
    Test(){ m_pBuffer = new int [SIZE]{}; }

    Test(int i){
        m_pBuffer = new int [SIZE]{};  // Allocating memory
        for(int i=0; i<SIZE; i++){
            m_pBuffer[i] = 7 * i;
        }
    }

    Test(const Test &other){
        // Allocate byte and copy the bytes from other object using memcopy
        m_pBuffer = new int [SIZE]{};  // Allocating memory
        memcpy(m_pBuffer, other.m_pBuffer, sizeof(int)*SIZE);  // Copy bytes from other

    }

    Test &operator=(const Test &other){
        m_pBuffer = new int [SIZE]{};  // Allocating memory
        memcpy(m_pBuffer, other.m_pBuffer, sizeof(int)*SIZE);  // Copy bytes from other
        return *this;
    }

    // Move Constructor: Initialize m_pBuffer with a nullptr
    Test(Test &&other){  // Move constructor takes a mutable Rvalue reference
        cout << "Move Constructor" << endl;
        m_pBuffer = other.m_pBuffer;
        
        /* Problem is that destructor of other will de-allocate that buffer and we
         * have stolen that buffer and we do not want that to happen so set others
         * buffer to nullptr.
         */
        other.m_pBuffer = nullptr;
    }

    ~Test(){
        delete [] m_pBuffer;
    }

    friend ostream &operator<<(ostream &out, const Test &test);
};

ostream &operator<<(ostream &out, const Test &test){
    out << "Hello from test";
    return out;
}

// Function that returns object of type Test
Test getTest(){
    return Test();
}

int main() {

    vector<Test> vec;
    vec.push_back(Test());

    return 0;
}

>>> Move Constructor
```

- In this example: In move constructor we do not have to allocate any more memory, but in copy constructor we have to allocate memory, therefore move constructor is very efficient.


### Move Assignment Operator

- Move assignment operator looks a lot like normal assignment operator except it has to take a mutable *Rvalue* reference, it can not be `const` as it has to change *other*. 

```c++
Test {
   // Constructors, Copy Constructors, etc.

	// Move Assignment Operator
    Test &operator=(Test &&other){
        cout << "Move Assignment" << endl;
        
        // this object which we are assigning to will have already allocated memory
        // so we need to free up any memory that it has allocated
        
        delete [] m_pBuffer;
        m_pBuffer = other.m_pBuffer;  // Assign memory to point at other.m_pBuffer
        other.m_pBuffer = nullptr;  // Stopping other to delete

        return *this;
    }
}

// Function that returns object of type Test
Test getTest(){
    return Test();
}

int main() {

    Test test;
    test = getTest();

    return 0;
}

>>> Move Assignment
```

### Static Cast

- Casting in C

```c++
void main(){
	float value = 3.14;
	cout << (int)value << endl;
	cout << int(value) << endl;
}

>>> 3
>>> 3
```

- `static_cast<type_to_cast_to>(value)`

```c++
void main(){
	float value = 3.14;
	cout << static_cast<int>(value) << endl;
}

>>> 3
```

- The below code is potentially error prone because what `static_cast` does is that it is purely *a compile time thing* so there is *no runtime checking*.

```c++
#include <iostream>
using namespace std;

class Parent {
public:
    void speak(){ cout << "Parent" << endl; }
};

class Son: public Parent {};

int main() {

    Parent parent;
    Son son;

    Parent *pp = &son;  // Pointer to parent, works because of polymorphism

    Son *ps = &parent;  // Error
    
    Son *ps = static_cast<Son *>(&parent);  // This is very unsafe
    cout << "ps: " << ps << endl;

    Parent *pps = &son;  // Pointer to Parent pointing as Son object
    Son *pss = &son;  // Pointer to Son pointing at Son object
    Son *pss_ = static_cast<Son *>(pps);
    cout << "pss: " << pss << endl;

    Parent &&p = Parent();  // Works because Rvalue reference bound to Rvalue
    
    // Rvalue reference to Lvalue works only if using static_cast
    Parent &&px = static_cast<Parent &&>(parent);  
    px.speak();

    return 0;
}

>>> ps: 0x7fff5bd9e958
>>> pss: 0x7fff55c86940
>>> Parent
```

### Dynamic Cast

- If you have a pointer of superclass type to a subclass type, you might later on want to have a poiner to the subclass type and you might want to cast the pointer of the superclass type back to the subclass type. `static_cast` in this case is unsafe.

```c++
int main() {

    Parent parent;
    Son son;
    
    Parent *pps = &son;
    Son *pss = static_cast<Son *>(pps);  // Unsafe
    cout << pss << endl;
    
    return 0;
}
```

- `static_cast` in the above case is unsafe. So it would be nice if we had some kind of cast that perform checks at runtime. `dynamic_cast` checks types at runtime to make sure you are doing something that makes sense. It is better to use `dynamic_cast` instead of `static_cast` because `static_cast` does not do runtime checking.
	- `error: 'Parent' is not polymorphic` - Make Parents method `virtual` 

```c++
#include <iostream>
using namespace std;

class Parent {
public:
    virtual void speak(){ cout << "Parent" << endl; }
};

class Son: public Parent {};

int main() {

    Parent parent;
    Son son;

    Parent *pps = &son;  // if &parent used output: Invalid cast
    Son *pss = dynamic_cast<Son *>(pps);

    if(pss == nullptr){
        cout << "Invalid cast" << endl;
    } else {
        cout << pss << endl;
    }

    return 0;
}

>>> 0x7fff56d96928
```

### Reinterpret Cast

- `reinterpret_cast` - It has even less checking than `static_cast`. If some situation arises where you genuinely need to cast what appears to be one type of pointer to a completely different type of pointer, and `static_cast` and `dynamic_cast` would not do it for some reason then use `reinterpret_cast`, but generally it is best to avoid it.

```c++
int main() {

    Parent parent;
    Son son;
    Daughter daughter;

    Parent *pps = &son;
    //Daughter *pds = dynamic_cast<Daughter *>(pps);  // dynamic_cast returns nullptr
    //Daughter *pds = static_cast<Daughter *>(pps);  // Works and unsafe
    Daughter *pds = reinterpret_cast<Daughter *>(pps);
    if(pds == nullptr){
        cout << "Invalid cast" << endl;
    } else {
        cout << pds << endl;
    }

    return 0;
}

>>> 0x7fff56d96928
```


### Perfect Forwarding

- The idea behing *Perfect Forwarding* is that you might want to call the right version of a function depending on whether you passed an *Rvalue* or an *Lvalue* to `template` function

```c++
#include <iostream>
using namespace std;

class Test {};

void check(Test &test){
    cout << "Lvalue" << endl;
}

void check(Test &&test){
    cout << "Rvalue" << endl;
}

int main() {

    Test test;

    // Rvalue reference to Rvalue
    auto &&rt = Test();

    // Lvalue reference to Lvalue
    auto &t = test;

    return 0;
}
```

- *Rvalue* reference to an *Lvalue* - If `auto` is used references collapse (check Reference collapsing rule)

```c++
int main() {

    Test test;

    // Rvalue reference to Lvalue
    auto &&tt = test;  // References collapse because of use of `auto` 
    
    return 0;
}
```

- Example of `template` declaration that uses *Rvalue*

```c++
#include <iostream>
using namespace std;

class Test {};

template<typename T>
void call(T &&arg){
    check(arg);
}

void check(Test &test){
    cout << "Lvalue" << endl;
}

void check(Test &&test){
    cout << "Rvalue" << endl;
}

int main() {

    Test test;

    call(Test());  // Rvalue input
    call(test);  // Lvalue input

    return 0;
}

>>> Lvalue  # Not Perfect Forwarding because output should be Rvalue
>>> Lvalue
```

- Fix of not perfect forwarding - Use `static_cast`

```c++
#include <iostream>
using namespace std;

class Test {};

template<typename T>
void call(T &&arg){
    check(static_cast<T>(arg));
}

void check(Test &test){
    cout << "Lvalue" << endl;
}

void check(Test &&test){
    cout << "Rvalue" << endl;
}

int main() {

    Test test;

    call(Test());  // Rvalue input
    call(test);  // Lvalue input

    return 0;
}

>>> Rvalue
>>> Lvalue
```

- Fix of not perfect forwarding - Use `forward`

```c++
#include <iostream>
using namespace std;

class Test {};

template<typename T>
void call(T &&arg){
    check(forward<T>(arg));
}

void check(Test &test){
    cout << "Lvalue" << endl;
}

void check(Test &&test){
    cout << "Rvalue" << endl;
}

int main() {

    Test test;

    call(Test());  // Rvalue input
    call(test);  // Lvalue input

    return 0;
}

>>> Rvalue
>>> Lvalue
```

### Bind and Placeholders

- `bind` - It allows to create kind of aliases to functions, a bit like function pointers. Need to use `#include <functional>`
- Use `auto variable = bind(function_pointer, function_arguments)` to bind a function with arguments to *variable*. Now the bound *variable* can be called, and every time bound *variable* is called it will be supplied with the arguments that were used during binding.

```c++
#include <iostream>
#include <functional>
using namespace std;
using namespace placeholders;

int add(int a, int b, int c){
    cout << a << ", " << b << ", " << c << endl;
    return a + b + c;
}

int main() {

    cout << add(1, 2, 3) << endl;
    
    auto sum = bind(add, 1, 2, 3);  // Binding add function to sum variable
    cout << sum() << endl;

    return 0;
}

>>> a, b, c: 1, 2, 3
>>> 6
>>> a, b, c: 1, 2, 3  # Output from calling sum()
>>> 6
```

- If using `using namespace placeholders` and `#include <functional>` then we can pass arguments like `_1`, `_2`, `_3` and so on to `bind` during binding.

```c++
#include <iostream>
#include <functional>
using namespace std;
using namespace placeholders;

int add(int a, int b, int c){
    cout << "a, b, c: " << a << ", " << b << ", " << c << endl;
    return a + b + c;
}

int main() {

    auto sum = bind(add, _1, _2, _3);
    cout << sum(3, 4, 5) << endl;

    return 0;
}

>>> a, b, c: 3, 4, 5
>>> 12
```

- Placeholders are always numbered and their order can be changed. `bind(function_name, _2, _1, _3)` is an example of order change. Placeholders and actual arguments can be combined, e.g. `bind(function_name, _1, value, _2);`

```c++

int main() {

    auto sum = bind(add, _1, 100, _2);
    cout << sum(1, 2) << endl;

    return 0;
}

>>> a, b, c: 1, 100, 2
>>> 103
```

```c++
#include <iostream>
#include <functional>
using namespace std;
using namespace placeholders;

int add(int a, int b, int c){
    cout << "a, b, c: " << a << ", " << b << ", " << c << endl;
    return a + b + c;
}

// Standard function
int run(function<int(int, int)> func){
    return func(7, 3);
}

int main() {

    auto sum = bind(add, _1, 100, _2);
    cout << run(sum) << endl;

    return 0;
}

>>> a, b, c: 7, 100, 3
>>> 110
```

- Binding to class method
	- First argument is pointer to class method or reference
	- Second argument is object of class to bind to

```c++
#include <iostream>
#include <functional>
using namespace std;
using namespace placeholders;

// Binding to Method
class Test {
public:
    int add(int a, int b, int c){
        cout << "a, b, c: " << a << ", " << b << ", " << c << endl;
        return a + b + c;
    }
};

int main() {

    Test test;
    // Pointer to add method or reference, second argument is object of class to bind to
    auto method = bind(&Test::add, test, 2, 100, 1);
    cout << method() << endl; 

    return 0;
}

>>> a, b, c: 2, 100, 1
>>> 103
```

### Unique Pointers

- *Unique pointers* are kind of smart pointer which behaves *like a normal pointer* except *they handle the de-allocation of memory automatically*
- Memory leaks are a common problem in C++ programs because you do not get enough `delete`'s being called or the right type of `delete` for the objects you have allocated using `new`. Smart pointers helps you avoid these bugs by automatically de-allocating memory.
- To use *smart pointers* you need to use `#include <memory>` as well as `using namespace std;`. If using `#include <iostream>`, it is already including memory so no need to use `#include <memory>`, if not then use `#include <memory>`
- Use `unique_ptr<type> pvariable(new type)` to declare a pointer `pvariable`, the `type` is the `type` pointer is going to point at. `unique_ptr` is a `template` type, we want this to manage memory that will be allocated by `new`
- Use `pVariable.get()` method to get pointer to underlying memory managed by `unique_ptr` *pVariable*

```c++
int main() {

    unique_ptr<int> pvalue(new int);
    cout << *pvalue << endl;
    *ptest = 7;
    cout << *ptest << endl;

    cout << "Finished" << endl;

    return 0;
}

>>> 0  # Default value
>>> 7
>>> Finished	
```

- *Smart pointers* in general cleans up memory when the variables they are associated with goes out of scope. NOTE: In C++ 11 use `unique_ptr` instead of `auto_ptr` (C++ 98) because `auto_ptr` is depreciated so do not use `auto_ptr`.

```c++
#include <iostream>
using namespace std;

class Test {
public:
    Test(){ cout << "created" << endl; }
    void greet(){ cout << "Hello!" << endl; }
    ~Test(){ cout << "destroyed" << endl; }
};

int main() {

    {
        // C++ 11 use unique_ptr instead of auto_ptr
        unique_ptr<Test> ptest(new Test);
        ptest->greet();
    }

        cout << "Finished" << endl;
        
    return 0;
}

>>> created
>>> Hello!
>>> destroyed
>>> Finished
```

- `auto_ptr` can not be used on arrays however `unique_ptr` can be used on arrays.

```c++
#include <iostream>
using namespace std;

class Test {
public:
    Test(){ cout << "created" << endl; }
    void greet(){ cout << "Hello!" << endl; }
    ~Test(){ cout << "destroyed" << endl; }
};

int main() {

    {
        // Array
        unique_ptr<Test []> ptest(new Test [2]);  // 2 elements
        ptest[1].greet();
    }
        cout << "Finished" << endl;

    return 0;
}

>>> created
>>> created
>>> Hello!
>>> destroyed
>>> destroyed
>>> Finished
```
- Example where a class member variable is a `unique_ptr`

```c++
#include <iostream>
using namespace std;

class Test {
public:
    Test(){ cout << "created" << endl; }
    void greet(){ cout << "Hello!" << endl; }
    ~Test(){ cout << "destroyed" << endl; }
};

// Example where class member variable is a unique_ptr
class Temp {
private:
    unique_ptr<Test []> pt;
public:
    Temp(): pt(new Test[2]){}
};

int main() {

    {
        Temp temp;
    }
        cout << "Finished" << endl;

    return 0;
}

>>> created
>>> created
>>> destroyed
>>> destroyed
>>> Finished
```

### Shared Pointers

- Shared pointers (`shared_ptr`) are similar to unique pointers, however they do not delete the memory associated with object until all the pointers that point at that object have gone out of scope. At the moment you can not use `shared_ptr` to point at arrays (this might change in C++ 17)
- Use `shared_ptr<type> pvariable(new type)` to declare a shared pointer `pvariable`, the `type` is the `type` pointer is going to point at. 

```c++
#include <iostream>
using namespace std;

class Test {
public:
    Test(){ cout << "created" << endl; }
    void greet(){ cout << "Hello!" << endl; }
    ~Test(){ cout << "destroyed " << endl; }
};

int main() {

	shared_ptr<Test> ptest(new Test);
	ptest->greet();
	
	cout << "finished" << endl;  // This is run before "destroyed"
	
	return 0;
}


>>> created
>>> Hello!
>>> finished
>>> destroyed 
```

- The best way to create a shared pointer is to use `make_shared` macro, where we do not have to use `new` and it is like template function. And according to documentation this approach is more efficient than using `new`.
- Use `shared_ptr<type> pvariable = make_shared<type>()` to create a shared pointer. NOTE: Need to use `()` when using `make_shared` macro

```c++
int main() {

    shared_ptr<Test> ptest = make_shared<Test>();  // Need ()

    cout << "finished" << endl;  // This is run before "destroyed"

    return 0;
}

>>> created
>>> finished
>>> destroyed 
```
- Example where memory will not get destroyed until both pointers (`pt` and `ptest`) have gone out of scope

```c++
int main() {

    shared_ptr<Test> pt(nullptr);

    {
        shared_ptr<Test> ptest = make_shared<Test>();
        pt = ptest;  
    }
    cout << "finished" << endl;  // This is run before "destroyed"

    return 0;
}

>>> created
>>> finished
>>> destroyed
```

### Multiple Inheritance

```c++
#include <iostream>
using namespace std;

class MusicalInstrument {
public:
    virtual void play(){ cout << "Playing instrument ..." << endl; }
    virtual void reset(){ cout << "Resetting instrument ..." << endl; }
    virtual ~MusicalInstrument(){};
};

class Machine {
public:
    virtual void start(){ cout << "Starting machine ..." << endl; }
    virtual void reset(){ cout << "Resetting machine ..." << endl; }
    virtual ~Machine(){}
};

// Class inheriting from multiple superclasses
class Synthesizer: public Machine, public MusicalInstrument {
public:
    virtual ~Synthesizer(){};
};

int main() {

    Synthesizer *pSynth = new Synthesizer();

    pSynth->play();  // Method in MusicalInstrument
    pSynth->start();  // Method in Machine
    cout << endl;

    delete pSynth;

    return 0;
}

>>> Playing instrument ...
>>> Starting machine ...
```

```c++
int main() {

    Synthesizer *pSynth = new Synthesizer();


    // pSynth->reset(); // Error
    pSynth->MusicalInstrument::reset();
    pSynth->Machine::reset();

    delete pSynth;

    return 0;
}

>>> Resetting instrument ...
>>> Resetting machine ...
```

- One reason multiple inheritance is bad because if a method that exists in all superclasses is called *error: member 'member_name' found in multiple base classes of different types*. For example using `pSynth->reset();` raises error. This can be solved by specifying from which superclass the method should be called, e.g. `pSynth->Machine::reset();`, however this requires you to know how Synthesizer is implemented and you want to encapsulate details of implementation as much as possible, i.e. you do not want the user of Synthesizer class to have to know what the superclasses of Synthesizer are. **In general it is better to avoid multiple inheritance. If superclasses have methods with identical signatures or identical prototypes the problem of ambiguous methods arises, so the methods need to be disambiguated which involves knowing implementation details of the derived class or child class.**






























