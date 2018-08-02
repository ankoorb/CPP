# C++ Notes
- 1 byte = 8 bits
- `//` - Single line comment
- `/* comment(s) */` - Multi-line comment
- `;` - Ending statement (Necessary)
- `&&` - AND operator
- `&` - Bit-wise AND operator
- `||` - OR operator
- `|` - Bit-wise OR operator
- `#directive-name` - A Preprocessor directive. When a program is built, the preprocessor directive runs and looks for statements that begin with `#` symbol and follows the commands specified in `#` symbol. 
- `#include` - Include directive is the most common preprocessor directive. It makes the compiler replace that line with the entire text of the contents of the named source file (`""`) or named header (`<>`) before compiling the program.
	- `<>` - Refers to files that are in standard location which the compiler will automatically look at, e.g. `#include <iostream>`
	- `""` - Refers to files that are located in local project directory, e.g. `#include "file.h"`
- `#include <iostream>` - Input/Output stream
- `#include <limits>` - For maximum or mininum integer or float values.
- `#include <iomanip>` For input/output manipulation, e.g. make `cout` output to not switch to scientific notation but to keep *fixed* notation, e.g. `cout << fixed << 10.5 << endl;`. It can also be used to set precision - `setprecision(n)` or set width.
- `<<` - Insertion operator
- `>>` - Extraction operator
- `cout` - Character output. e.g. `cout << "This is example number " << 1;`. NOTE: Use *double quotes* for string.
- `cin` - Character input. e.g. `cin >> x;` where `x` is some variable type.
- `endl` - Inserts a newline character and flushes the stream.
- `flush` - It instructs the operating system to output text without creating a carriage return. It also clears out the memory.
- `break` - It helps break out of the loop.
- `continue` - It breaks out of the current iteration of the loop and goes to the next iteration (i.e. any statements after `continue` will not be executed for the current iteration).

```c++
#include <iostream>
using namespace std;

int main() {
	cout << "Hello World! << endl;
}
```

- Type casting example: `(int)<variable>` or `(double)<variable>`
- `int value = 5/2` returns `2`, the remainder `0.5` is discarded. In C++ whenever an integer is divided by an integer it will always discard the remainder and will do integer division and would not do floating point division. Even `double value = 5/2` returns `2`. To do floating point division either remainder or denominator must be converted or cast to a floating point number, e.g. `double value = (double)5/2` returns `2.5`


### Variable Types

- `int` - Integer type delaration
- `long int` - Long integer type declaration (big value)
- `short int` - Short integer type declaration (small value)
- `signed int` - Signed (positive or negative) integer type declaration (default in C++)
- `unsigned int` - Unsigned integer type declaration (Only positive values)
- `float` - Floating point type declaration. NOTE: After few significant digits, the last few digits are garbage.
- `double` - Double floating point type declaration. It has more precision (significant digits) than `float`
- `long double` - Long double floating point type declaration. It has more precision (significant digits) than `double`
- `bool` - Boolean type declaration (**true** or **false**)
- `string` - String type declaration. NOTE: Use *double quotes*
- `char` - Character type declaration. NOTE: Use *single quotes*

```c++
char c = 'a';
c++;
string s(3, c); 
cout << s << endl;  // Prints: bbb, if c++ not used then: aaa
```

- `sizeof(variable-type)` - Operator to find how much memory is used by `int` or `float` or `string` or other variable types or declared or assigned variables.
- String Streams - Concatenating disparate types of data, e.g. `double` or `int` and `string` into `string`

```c++
#include <sstream>

stringstream ss;
ss << "variable" << " + " << 1.5;  
cout << ss.str() << endl; 
```



--

### Arrays

- Declare array of integers: `int x[num-elements];`
- Declare and initialize an array of strings:
	- `string s[2] = {"An", "Apple"};`
	- `string s[] = {"An", "Apple"};` - *C++ can figure out if array size is not given but array is initialized.*
- Declare an empty array of integers: `int x[num-elements] = {};`
- Setting array values: `x[0] = 7;`
- Multi-dimensional array (2-D) of integers: `int x[num-rows][num-columns] = {};`. C++ will return some garbage if elements that do not exist are accessed, e.g. `x[10]` will return garbage if number of elements in array `x` is 2.


### If Else-If Else Statement
```c++
if (condition) {
	statement;
}
else if (other condition) {
	other statement;
} else {
	other statement;
}
```

### While Loop
```c++
while (condition) {
	statement;
}
```

### For Loop
- `i = i + 1` and `i += 1` and `i++` are same

```c++
for (int i=0; i<10; i++) {
	statement;
}
```

```c++
for (int i=0; i<10; i++) {
	statement;
	j++;
}

for (int i=0; i<10; i++, j++) {
	statement;
}
```


### Do While Loop
- `do-while` loop always executes the statements between the `{` and `}` at least once, because it does not check condition until the end.

```c++
do {
	statement;
} while (condition);
```

### Switch Statement
- `switch` statement lets one choose between various possible values, it is similar to `if-else if-else` statement. If `break` statement is not provided, the next `case` statement will be executed.


```c++
int value;
switch (value) {
	case i:
		statement;
		break;
	case j:
		another statement;
		break;
	default:
		default statement;
		break;
}
```

#### Char Arrays

- Creating `char` arrays
	- `char c[] = {'A', 'B', 'C'};`
	- `char c[] = "ABC";`

```c++
char c[] = {'A', 'B', 'C'};
cout << sizeof(c) << endl;  // Prints: 3
	
char c[] = "ABC";
cout << sizeof(c) << endl;  // Prints: 4
	
for (int i=0; i<sizeof(c); i++) {
	 cout << i << ": " << c[i] << " " << flush;
} // Prints: 0: A 1: B 2: C 3: # -> It is a null string terminator (invisible character)

/*
Null String Terminator allows program to know where the string actually ends. " appends
0 value to the string.
*/

// Casting array value as an int
for (int i=0; i<sizeof(c); i++) {
	 cout << i << ": " << (int)c[i] << " " << flush;
}  // Prints: 0: 65 1: 66 2: 67 3: 0 
```

### Functions

- Functions needs to be defined before `main()` function because compilation is a single pass top-down process. `{` and `}` define scope of variables inside a function.
- `void` - It is used to indicate that a function does not return a value or data into calling function i.e. `main()`

```c++
void function_name(){
	statements;
}

```

- Returning values from function that takes parameters

```c++
int multiply(int x, int y){
	return x * y;
}

int z = multiply(3, 5);
```

- **Prototype** - Allows functions to be defined below `main()`. If functions defined below `main()` are called in `main()` - An *error: use of undeclared identifier* is raised, because compiler reads code from top to bottom. A way to fix this is to declare prototype of the function above `main()`.

```c++
// Declare function prototype
int function_name();

int main () {
	function_name();
}

// Define function
int function_name() {
	statements;
}
```

- **Header** - Prototype of functions are added in header file. 
	- Create a Header C++ file, e.g. `example.h`. Add prototype of related functions in this header file. Header guard prevents a given header file from being included more than once in the same file.
		- `#ifndef XYZ` - If this symbol (`XYZ`) is not defined then
		- `#define XYZ` - Define this symbol (`XYZ`) 
		- <font color=salmon>Add function prototype</font>
		- `endif //XYZ` - End if directive

	
		```c++
		// example.h
		#ifndef INC_PROJECT
		#define INC_PROJECT
		
		void function_name(); // Prototype of function
		
		#endif INC_PROJECT
		```

	- In `main.cpp` include `example.h` header file using `#include "example.h"`. NOTE: Put standard headers at the top before project headers.

```c++
// main.cpp
#include <iostream>
#include "example.h"
```

# Object Oriented Programming

### Classes

- Classes are defined in `ClassName.h` using `class ClassName {};`

```c++
// Dog.h
#ifndef DOG_H_
#define DOG_H_

class Dog{
public:  // Allows access to variable from outside of the class
	bool happy;  // Every Dog object will have this bool variable
	void jump();  // Prototype of function
};

#endif //DOG_H_
```

- Class variables and methods are defined in `ClassName.cpp`. Class methods are prefixed with class name, e.g. `ClassName::method(){}`


```c++
// Dog.cpp
#include <iostream>
#include "Dog.h"
using namespace std;

void Dog::jump() {  // This means jump method is member of Dog class
    if(happy) {
    	cout << "Jumping on top of bed." << endl;
    } else {
    	cout << "Bark!" << endl;
    }
}
```

```c++
// main.cpp
#include <iostream>
#include "Dog.h"
using namespace std;

int main() {

    Dog crush;  // Creating Dog class object, similar to int value
    crush.happy = true;
    crush.jump();
    
    return 0;
}
```

### Constructors and Destructors

- Constructors and Destructors must have same name as class name. Constructors and destructors do not have a return type (not even `void`). 
- Constructor method runs when object is instantiated.
	- Constructors initializes instance variables.
- Destructor method runs automatically when object is destroyed (i.e. when the memory for the object is de-allocated). It has same name as class name and it has `~` in the start. e.g. `~Class_Name();`

```c++
// Dog.h
#ifndef DOG_H_
#define DOG_H_

class Dog{
private:
	bool happy;  
public: 
	void speak();  
	Dog();  // Constructor
	~Dog();  // Destructor
};

#endif //DOG_H_
```

```c++
// Dog.cpp
#include <iostream>
#include "Dog.h"
using namespace std;

// Constructor
Dog::Dog() {  // NOTE: No return type specified
    cout << "Dog Created ..." << endl;
    happy = true; // Set instance variable
}

// Destructor
Dog::~Dog() {  // NOTE: No return type specified
    cout << "Dog Destroyed ..." << endl;
}

// Class Method
void Dog::speak() {
    if(happy) {
        cout << "Bark!" << endl;
    } else {
        cout << "Grr!" << endl;
    }
}
```

```c++
// main.cpp
#include <iostream>
#include "Dog.h"

using namespace std;

int main() {

    // { and } scope used to de-allocate memory i.e. call Destructor.
    {
        Dog crush;  // Instantiate a dog from Dog class. Constructor runs
        crush.speak();
    }
    
    return 0;
}
```

### Getters and Setters

```c++
// Person.h
#ifndef PERSON_H
#define PERSON_H

#include <iostream>
using namespace std;

class Person {
private:
    string name;
public:
    Person();
    string toString();
    void setName(string new_name);
    string getName();

};

#endif //PERSON_H
```

```c++
// Person.cpp
#include "Person.h"

Person::Person() {
    name = "Jon Snow";
}

string Person::toString() {
    return "Person's name is: " + name;
}

// Getter
string Person::getName() {
    return name;
}

// Setter
void Person::setName(string new_name) {
    name = new_name;
}
```

```c++
// main.cpp
#include <iostream>
#include "Person.h"
using namespace std;

int main() {

    Person stark;
    cout << stark.toString() << endl;
    stark.setName("Aegon Targaryen");
    cout << stark.getName() << endl;

    return 0;
}
```

### Overloading Constructors

- There can be as many constructors as one likes as long as they have different parameters. This is true for methods with same name as long as they have different parameters.

```c++
// Person.h
#ifndef PERSON_H
#define PERSON_H

#include <iostream>
using namespace std;

class Person {
private:
    string name;
    int age;
public:
	 // Constructor without parameter
    Person();

    // Constructor with parameter - Defined inline here instead of Person.cpp
    Person(string new_name) { name = new_name; age = 0;};

    // Constructor with parameters - Defined in Person.cpp
    Person(string new_name, int new_age);

    // Methods
    string toString();
};

#endif //PERSON_H
```

```c++
// Person.cpp
#include <sstream>
#include "Person.h"

Person::Person() {
    name = "undefined";
    age = 0;
}

string Person::toString() {
    stringstream ss;
    ss << "Name: " << name << " and age: " << age;
    return ss.str();
}

Person::Person(string new_name, int new_age) {
    name = new_name;
    age = new_age;
}
```

### `this` using `this->variable = variable`


```c++
// Person.h
#ifndef PERSON_H
#define PERSON_H

#include <iostream>
using namespace std;

class Person {
private:
    // Instance variables name and age
    string name;     
    int age;  
public:
    // Parameterized constructor
    Person(string name, int age);
};

#endif //PERSON_H
```

```c++
// Person.cpp
#include "Person.h"

// Parameterized Constructor
Person::Person(string name, int age) {  // Parameters name and age
    this->name = name;  // Allows to set instance variable name with parameter name
    this->age = age;
    cout << "Memory location of object: " << this << endl;  // Memory location
}

// Using `this` is equivalent to:
Person::Person(string new_name, int new_age) { 
    name = new_name;
    age = new_age;
}

``` 

### Constructor Initialization Lists

- More efficient in terms of speed compared to setting instance variable using `this` but it is not going to make a difference to most programs
- `ClassName::ClassName(<var-type> <argument>)`**`: <instance-var>(<argument>) {}`**. Use `,` to separate instance variables.

```c++
// Person.cpp
#include "Person.h"

// Using `this`
Person::Person(string name, int age) {
    this->name = name;
    this->age = age;
}

// Using Constructor Initialized List
Person::Person(string name, int age): name(name), age(age) {
}

Person::Person(): name(""), age(0) {}  // Default Constructor
```

```c++
// Person.h
#ifndef PERSON_H
#define PERSON_H

#include <iostream>
using namespace std;

class Person {
private:
    // Instance variables name and age
    string name;     
    int age;  
public:
	// Using Constructor Initialized List directly in Person.h instead of Person.cpp
	Person(): name(""), age(0) {};  
};

#endif //PERSON_H
```


# Pointers

- Pointers are used to store memory location of different types of variables, e.g. `int`, `double`, `string`.
- Get the address of a variable: `&<variable>`
- Type of variable is "pointer to an int": `int *<variable>` or `int* <variable>`. Pointer of type int
- Get the actual value at the memory address which is contained in the pointer: `*<variable>`
- Assign a value to a pointer: `*<variable> = value`

```c++
int Value = 7;
int *pValue = &Value;  // Pointer to int is equal to address of Value

cout << pValue << endl;   // Prints: 0x7fff5564da54
cout << *pValue << endl;  // Prints: 7
cout << Value << endl;    // Prints: 7

*pValue  = 15; // Change the value that this pointer points at

cout << pValue << endl;   // Prints: 0x7fff5564da54
cout << *pValue << endl;  // Prints: 15
cout << Value << endl;    // Prints: 15
```

### Arrays

- Pointer will point to the first element of the array

```c++
int array;
int *parray = array;  // NOTE: &array is not used!
```

- Array variables and pointers are similar to each other. The main difference is that array variable knows how much data it is pointing at (that is why `sizeof` can be used to get the number of elements in the array). Normal pointer does not know how much data it is pointing at, it only knows the size of the first block of data it is pointing at, it does not know how many blocks there are. This is why we can *assign a pointer directly to point out an array variable*.

```c++
string s[] = {"A", "B"};  // Array of strings
string *ps = s;  // Pointer to string array

// Array Element Reference Syntax
cout << ps[0] << endl;  // Prints: A
cout << ps[1] << endl;  // Prints: B
cout << ps[2] << endl;  // Prints: Garbage

// Incrementing Pointer and De-referencing Syntax
cout << *ps << endl;  // Prints: A only
cout << ps << endl;  // Prints: 0x7fff5c7c7b00 -> 140734745049856
ps = ps + 1;  // Pointing at the next block of data 
cout << ps << endl;  // Prints: 0x7fff5c7c7b18 -> 140734745049880
// NOTE: 140734745049880 - 140734745049856 = 24 i.e. sizeof(string)
cout << *ps << endl;  // Prints: B

/* 
NOTE: Now if ps = ps + 1 is done again, garbage will be printed out because
the pointer will point to the end of the array items as number of items in
array is 2.
*/

// Pointers for First/Last Elements
string *pElement = s;
string *pEnd = &(s[1]);  // It is same as &s[1], [] operator higher precidence than &
```

### Pointer Arighmetic (Adding, Subtracting, and Comparing Pointers)

```c++
string s[3] = {"A", "B", "C"};
string *ps = s;

// Addition
ps = ps + 2;
cout << *ps << endl;  // Prints: C

// Subtraction
ps = ps -1;
cout << *ps << endl;  // Prints: B

// Comparison
string *pEnd = &s[2]  // Number of elements in s = 3, max index = 2
cout << (ps == pEnd)  << endl;  // Prints: 0
```

- If we subtract one pointer from another we can store the result in an `int` type variable
- Reversing a string example

```c++
char s[] = "hello";
char *pfirst = s;
int nchars = sizeof(s) - 1;
char *plast = s + nchars - 1;

while (pfirst < plast) {  // Pointer comparison
	// Swapping chars
	char c = *pfirst;
	*pfirst = *plast;
	*plast = c;
	
	pfirst++;
	plast--;
}

cout << s << endl;  // Prints: olleh
```

### References

- `int &v = u` - `v` is a reference to `u` (i.e. `v` is just another name for `u`). Whatever we do to `v` will happen to `u` as they are same. The reference can not hold an `int` (or other types), it can only act as a synonym for the existing variable. 

```c++
int u = 7;
int &v = u;
v = 14;

cout << "u: " << u << " v: " << v << endl;  // Prints: u: 14 v: 14
``` 


### Passing arguments to a function by reference with pointers

- Passing argument to a function by value - C++ passes a copy of argument variable, so the original variable itself can not be changed by until it is set equal to another value. This way the function only has access to the copy of the variable.
- Passing argument to a function by reference with pointer - C++ passes the address of variable. This way the function has direct access to the variable and the original variable can be modified inside the function. Advantage: Less stress on computer, because everytime a argument is passed by value to a function, the function has to make a copy of the variable. 

```c++
#include <iostream>
using namespace std;

void passByValue(int value) {
    value = 15;
}

// Functions that receive a memory address need to have a pointer argument
void passByReference(int *value) {  // Pointer receives memory address
    *value = 15;
}

int main() {

    int x = 7;
    int y = 7;
    
    cout << "Initial x: " << x << endl;
    passByValue(x);
    cout << "After pass by value, x is " << x <<endl;

    cout << "Initial y: " << y << endl;
    passByReference(&y);
    cout << "After pass by reference with pointer, y is " << y << endl;

    return 0;
}
```


### `const` Methods and Variables

- `const` - It makes sure that a variable is not re-assigned. e.g. `const double pi = 3.14159;`

- If a method does not change instance data of the class it can be declared as `const` as follows: `void method() const {};`. It is a good practice to declare such methods as `const`.

```c++
class Animal {
private:
	string name;
public:
	void setName(string name) {this->name = name;}
	void speak() const { cout << "Animal name is: " << name << endl;}
}

>>> Initial x: 7
>>> After pass by value, x is 7
>>> Initial y: 7
>>> After pass by reference with pointer, y is 15
```

- Constant Pointer (*read backwards*)
	- Normal operation without `const` keyword
	
	```c++
	int value = 7;
	int *pvalue = &value;
	
	// Change pointer
	int number = 15;
	pvalue = &number;  // Re-assign pointer to point somewhere else
	cout << *pvalue << endl;  // Prints: 15
	
	*pvalue = 6;  // Change the int the pointer point at
	cout << *pvalue << endl;  // Prints: 6
	```
	
	- `const int *pvalue = &value;` - Pointer to an `int` that is constant. We can not change the `int` that pointer points at.

	```c++
	int value = 7;
	const int *pvalue = &value;
	
	// Change pointer
	int number = 15;
	pvalue = &number;
	cout << *pvalue << endl;  // Prints: 15
	
	*pvalue = 6;  // Error when: Pointer to an int that is constant
	```
	
	- `int *const pvalue = &value;` - Constant pointer to an `int`. The pointer is constant, we can not re-assign pointer to point somewhere else.

	```c++
	int value = 7;
	int *const pvalue = &value;
	
	// Change pointer
	int number = 15;
	pvalue = &number;  // Error when: Pointer is a constant
	
	// However we can change the int the pointer points at
	*pvalue = 6;	
	cout << *pvalue << endl;  // Prints: 6
	```
	
	- `const int *const pvalue = &value;` - Constant pointer to an `int` that is constant. We can not change anything.

	```c++
	int value = 7;
	const int *const pvalue = &value;
	
	// Can not change anything
	int number = 15;
	pvalue = &number;  // Error when: Pointer is a constant
	*pvalue = 6;  // Error when: Pointer to an int that is constant
	```
	
### Copy Constructors

- C++ *implictly* creates a special constructor called copy constructor that simply copies settings from one object to another. Copy constructor can be explicitly defined.


```c++
#include <iostream>
using namespace std;

class Animal {
private:
    string name;
public:
    Animal() { cout << "Animal Created!" << endl;}
    void setName (string name) { this->name = name;}
    void speak() const { cout << "Animal name: " << name << endl;}
};

int main() {

    Animal dog1;
    dog1.setName("Crush");

    Animal dog2 = dog1;  // Why 2nd constructor is not called here? 
    
    // Because we are implicitly invoking copy constructor
    
    dog2.setName("Lucy Lu");  // Can set animal name independently

    dog1.speak();
    dog2.speak();
       
    return 0;
}

>>> Animal Created!
>>> Animal name: Crush
>>> Animal name: Lucy Lu
```

- Explicit 

```c++
#include <iostream>
using namespace std;

class Animal {
private:
    string name;
public:
    // Constructor
    Animal() { cout << "Animal Created!" << endl;}

    // Copy Constructor (explicit)
    Animal(const Animal &other):  // Using reference
    name(other.name) { 
    	cout << "Animal Created by Copying!" << endl;
    }

    void setName (string name) { this->name = name;}
    void speak() { cout << "Animal name: " << name << endl;}
};

int main() {

    Animal dog1;
    dog1.setName("Crush");

    Animal dog2 = dog1;
    dog2.speak();
    dog2.setName("Lucy Lu");

    dog1.speak();
    dog2.speak();
    
    // Another way to explicitly invoke copy constructor
    Animal dog3(dog1);  // 
    dog3.speak();

    return 0;
}

>>> Animal Created!
>>> Animal Created by Copying!
>>> Animal name: Crush  // Output from dog2.speak();
>>> Animal name: Crush
>>> Animal name: Lucy Lu
>>> Animal Created by Copying!
>>> Animal name: Crush  // Output from dog3.speak();
```

### `new` Operator

- `ClassName *pointer = new ClassName()` - Another way to instantiate object from a class. `pointer->MethodName(parameter)` - Use `->` to call methods on a pointer. NOTE: When memory is allocated using `new` you must always remember to de-allocate memory explicitly. Always call `delete` when `new` is used because if it is not called it causes memory leak and can crash the program randomly, e.g. `delete pointer`

```c++
#include <iostream>
using namespace std;

class Animal {
private:
    string name;
public:
    Animal() { cout << "Animal created." << endl; }
    ~Animal() { cout << "Destructor called." << endl; }

    void setName(string name) { this->name = name; }
    void speak() const { cout << "Animal name: " << name << endl;}
};

int main() {
	
	 // Instantiating object from a class using new
    Animal *pDog = new Animal;  // When class takes parameter use ()
    pDog->setName("Crush");
    pDog->speak();
    delete pDog;  // Always call a delete when new is used
  
    return 0;
}

>>> Animal created.
>>> Animal name: Crush
>>> Destructor called.
```

### Pointer to a class and arrow member selection operator

```c++
#include <iostream>
using namespace std;

class Dog {
public:
    Dog(){};
    ~Dog(){};
    void speak() { cout << "Bark!" << endl; }
};

int main() {

    Dog dogObject;
    dogObject.speak();  // Accessing speak with object

    Dog *dogPointer = &dogObject;
    dogPointer->speak();  // Accessing speak with pointer

    Dog *crush;
    crush->speak();
    
    return 0;
}
```

### Returning Objects From Functions (Hard)

- `new` allocates memory to heap. NOTE: This helps avoid *stack overflow*
- `ClassName *function() {}` - Returns pointer to `ClassName` object

```c++
#include <iostream>
using namespace std;

class Animal {
private:
    string name;
public:
    Animal() { cout << "Animal created." << endl; }
    ~Animal() { cout << "Destructor called." << endl; }

    void setName(string name) { this->name = name; }
    void speak() const { cout << "Animal name: " << name << endl; };
};

// Create a function that returns pointer to object of Animal class
Animal* createAnimal() { 
    Animal *pAnimal = new Animal;
    pAnimal->setName("Snoops");
    return pAnimal;
}

int main() {

    Animal *pCat = createAnimal();
    pCat->speak();
    delete pCat;  // De-allocate memory

    return 0;
}

>>> Animal created.
>>> Animal name: Snoops
>>> Destructor called.
```

### Allocating Memory


```c++
#include <iostream>
using namespace std;

class Animal {
private:
    string name;
public:
    Animal() { cout << "Animal created." << endl; }
    ~Animal() { cout << "Destructor called." << endl; }

    void setName(string name) { this->name = name; }
    void speak() const { cout << "Animal name: " << name << endl; };
};


int main() {

	 // Allocating memroy for primitive types
    int *pInt = new int;
    *pInt = 7;
    cout << *pInt << endl;
    delete pInt;

    // Allocating memory and also instantiating an object in that memory
    Animal *pDog = new Animal;  
    delete pDog;
 
    // Allocate arrays of objects
    Animal *pAnimal = new Animal[2];  // Creates and allocates 2 Animal objects
    pAnimal[1].setName("Crush");
    pAnimal[1].speak();

    delete [] pAnimal;  // Free up memory that pAnimal is pointing at

	 // Allocate arrays for primitive types
    char *pMem = new char[1000];
    delete [] pMem;

    return 0;
}

>>> 7
>>> Animal created.
>>> Destructor called.
>>> Animal created.
>>> Animal created.
>>> Animal name: Crush
>>> Destructor called.
>>> Destructor called.
```

### Passing Arrays to Functions 

- Passing array directly - The information about the number of elements in the array is lost.

```c++
// If string array[5] is passed then 5 will be ignored by c++
void show(const int nElements, string array[]) {  
	// Prints size of the pointer, which equal to sizeof(long)
	cout << "sizeof(array): " << sizeof(array) << endl; 
	for (int i=0; i<nElements; i++) {
		cout << array[i] << endl;
	}
}

int main() {
    string texts[] = {"apple", "banana"};
    cout << "sizeof(texts): " << sizeof(texts) << endl;
    show(2, texts);
}

>>> sizeof(texts): 72
>>> sizeof(array) : 8  // Size of pointer = sizeof(long)
>>> apple
>>> banana
```

- Passing pointer - Information about the size of array is unavailable (however, information about size of pointer variable is available)

```c++
void show(const int nElements, string *array) {
	cout << "sizeof(array): " << sizeof(array) << endl;
	for (int i=0; i<nElements; i++) {
		cout << array[i] << endl;
	}
}

int main() {
    string texts[] = {"apple", "banana"};
    cout << "sizeof(texts): " << sizeof(texts) << endl;
    show(2, texts);
}

>>> sizeof(texts): 72
>>> sizeof(array) : 8  // Size of pointer = sizeof(long)
>>> apple
>>> banana
```

- Passing reference to the array (must pass in number of elements correctly in []) - Information about the size of array is retained.

```c++
// Must pass in number of elements correctly in `[]` else error
void show(string (&array)[2]) {  
	cout << "sizeof(array): " << sizeof(array) << endl;
	for (int i=0; i<sizeof(array)/sizeof(string); i++) {
		cout << array[i] << endl;
	}
}

int main() {
    string texts[] = {"apple", "banana"};
    cout << "sizeof(texts): " << sizeof(texts) << endl;
    show(texts);
}

>>> sizeof(texts): 72
>>> sizeof(array) : 72
>>> apple
>>> banana
```

### Returning Arrays from Functions

- **Do not return pointers to local variables**: In the code snippet below, the array scope is function's `{` and `}` and the array is local to the function. The function returns pointer to local array or variables. The pointer will not exist after leaving the function, i.e. the pointer will point to something that no longer exists after the function returns. **Avoid returning pointer to local variables**

```c++
string *getArray() {  // Returning a pointer
	string texts[] = {"cat", "dog"};
	return texts;
}

int main(){
	string *pArray = getArray();
	cout << "pArray: " << *pArray << endl;
	pArray++;
	cout << "pArray: " << *pArray << endl;
}

>>> pArray: cat
>>> pArray: eW@$%@  // Garbage
```

- Using `new` operator - Explicitly allocating memory that will not be de-allocated until `delete` is called. *If you create a function that allocates memory, the common practice is also to create a function that de-allocates that memory. And in the documentation of function that allocates memory add information for user to call function that de-allocates memory*

```c++
int *getArray() {
	// Call freeMemory function to de-allocate memory
	int *pArray = new int[2];
	pArray[0] = 7;
	pArray[1] = 15;
	return pArray;
}

void freeMemory(int *pArray){
	delete [] pArray;
}

int main(){
	int *pArray = getArray();
	cout << "pArray: " << *pArray << endl;
	pArray++;
	cout << "pArray: " << *pArray << endl;
	freeMemory(pArray);
}

>>> pArray: 7
>>> pArray: 15
```

### Namespaces

- `namespace`'s are a way of avoiding conflicts between classes or global variables that have the same name.

```c++
// Dog.h
#ifndef DOG_H
#define DOG_H

class Dog {
public:
    Dog();
    virtual ~Dog();
    void speak();
};

#endif //DOG_H
```

```c++
// Dog.cpp
#include "Dog.h"
#include <iostream>
using namespace std;

Dog::Dog() {}

Dog::~Dog() {}

void Dog::speak() {
    cout << "Bark!" << endl;
}
```

- Creating namespace: `namespace name { <code> }`

```c++
// Animal.h
#ifndef ANIMAL_H
#define ANIMAL_H

namespace canine {  // Namespace with name "canine"
    class Dog {  // Now Dog class can be defined again
    public:
        Dog();
        virtual ~Dog();
        void speak();
    };
}

#endif //ANIMAL_H
```

```c++
// Animal.cpp
#include "Animal.h"
#include <iostream>
using namespace std;

namespace canine {  // Namespace with name "canine"
    Dog::Dog() {}

    Dog::~Dog() {}

    void Dog::speak() {
        cout << "Grrr!" << endl;
    }
}
```

- Using namespace: `using namespace name`

```c++
// main.cpp
#include "Animal.h"  // Dog.h is not used

using namespace canine;

int main() {

    Dog crush;
    crush.speak();

    return 0;
}

>>> Grrr!
```

```c++
// main.cpp
#include "Dog.h"  // Dog.h is used
#include "Animal.h"

using namespace canine;

int main() {

    canine::Dog crush;
    crush.speak();

    return 0;
}

>>> Grrr!
```

- To use other class with same name create a namespace and add class definition (`*.h`) and class implementation (`*.cpp`) into it

```c++
// main.cpp
#include "Dog.h"
#include "Animal.h"

using namespace dog;  // Creating "dog" namespace in Dog.h and Dog.cpp
using namespace canine;

int main() {

    dog::Dog pluto;
    pluto.speak();
    
    canine::Dog crush;
    crush.speak();

    return 0;
}

>>> Bark!
>>> Grrr!
```

### `const` in `namespace`

```c++
// Animal.h
#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>
using namespace std;

namespace canine {

    const string NAME = "Goofy";

}

#endif //ANIMAL_H
```

```c++
// Animal.cpp
#include "Animal.h"

namespace canine {}
```

```c++
// main.cpp
#include "Animal.h"

using namespace canine;

int main() {

    cout << canine::NAME << endl;

    return 0;
}

>>> Goofy
```

### Inheritance (basic)

- Usage: `class subclass: public superclass { }`

```c++
#include <iostream>
using namespace std;

class Animal {  // Animal is superclass
public:
    void speak() {
        cout << "Animal speaking: Grrr!" << endl;
    }
};

class Canine: public Animal {  // Canine is subclass of Animal
public:
    void jump() {
        cout << "Canine Jumping!" << endl;
    }
};

class Dog: public Canine {  // Dog is subclass of Canine and Animal
public:
    void attack() {
        cout << "Dog Attacking!" << endl;
    }
};

int main() {

    Animal A;
    A.speak();

    Canine C;
    C.speak();
    C.jump();

    Dog D;
    D.jump();
    D.speak();
    D.attack();

    return 0;
}

>>> Animal Speaking: Grrr!  // Animal
>>> Animal Speaking: Grrr!  // Canine
>>> Canine Jumping!
>>> Animal Speaking: Grrr!  // Dog
>>> Canine Jumping!
>>> Dog Attacking!
```

### Encapsulation

- When constructor is implicitly called outside the class the constructor will have to be `public`

```c++
#include <iostream>
using namespace std;

class Frog {
private:
	string name;
public:
	Frog(string name): name(name) {}  // Constructor
	string getName() { return name; }
}

int main() {
	
	Frog frog("Freddy");  // Implicitly calling constructor
	cout << frog.getName() << endl;
	// cout << frog.name << endl;  // Error, because "name" is private
	
}

>>> Freddy
```

- If you do not want users to access some methods then declare those methods as `private`, for example: 

```c++
#include <iostream>
using namespace std;

class Frog {
private:
	string name;
	string getName() { return name; }  
public:
	Frog(string name): name(name) {}
	void info() { 
		cout << "Frog's name is: " << getName() << endl; 
	}
}

int main() {
	
	Frog frog("Freddy");  
	frog.info()
	
	// Error, because "name" and "getName" are private
	// cout << frog.getName() << endl;
	// cout << frog.name << endl; 
}

>>> Frog's name is: Freddy
```

- Make as much of your class private as you possibily can.
- Common encapsulation order
	- `private` instance variables
	- `private` methods
	- `public` methods


### Constructor Inheritance

- In C++ constructors are not inherited by subclasses but they are called.
- C++ will call the default constructors of all the superclasses when it creates an object from a subclass

```c++
#include <iostream>
using namespace std;

class Machine {
public:
    Machine() { cout << "Machine no argument constructor called." << endl; }
};

class Vehicle: public Machine {
public:
    Vehicle() { cout << "Vehicle no argument constructor called." << endl; }
};

int main() {

    Vehicle vehicle;
    
    return 0;
}

>>> Machine no argument constructor called.
>>> Vehicle no argument constructor called.
```

```c++
#include <iostream>
using namespace std;

class Machine {
private:
    int id;
public:
	// Constructor with an argument
    Machine(): id(0) { cout << "Machine no argument constructor called." << endl; }
    void info() { cout << "ID: " << id << endl; }
};

class Vehicle: public Machine {
public:
    Vehicle() { cout << "Vehicle no argument constructor called." << endl; }

    // In Vehicle we can not refer to `id` because it is private to Machine
    // so if we use `Vehicle(): id(7) { }`, we will get error.
};

class Car: public Vehicle {
public:
    Car() { cout << "Car no argument constructor called." << endl; }
};

int main() {

    Car car;
    car.info();

    return 0;
}

>>> Machine no argument constructor called.
>>> Vehicle no argument constructor called.
>>> Car no argument constructor called.
>>> ID: 0
```

- C++ allows to specify which constructor in the superclass at any point in the hierarchy is actually run

```c++
#include <iostream>
using namespace std;

class Machine {
private:
    int id;
public:
    Machine(): id(0) { cout << "Machine no argument constructor called." << endl; }
    Machine(int id): id(id) { cout << "Machine argument constructor called." << endl; }
    void info() { cout << "ID: " << id << endl; }
};

class Vehicle: public Machine {
public:
    Vehicle() { cout << "Vehicle no argument constructor called." << endl; }

    // Specify which constructor in the superclass to run
    Vehicle(int id): Machine(id) { cout << "Machine argument constructor called." << endl; }
};

class Car: public Vehicle {
public:
    Car() { cout << "Car no argument constructor called." << endl; }
    Car(int id): Vehicle(id) { cout << "Car argument constructor called." << endl; }

};

int main() {

    Vehicle vehicle(15);  
    vehicle.info();

    return 0;
}

>>> Machine argument constructor called.
>>> Vehicle argument constructor called.
>>> Car argument constructor called.
>>> ID: 15
```

### `static` Keyword

- `static` variables are shared by all objects of a class (similar to class variable in Python)
- Whenever `static` variables are created they need to be initialized

```c++
#include <iostream>
using namespace std;

// .h header file
class Test {
public:
    static int count;  // static variable
};

// .cpp source
int Test::count = 7;

int main() {

    cout << Test::count << endl;

    return 0;
}

>>> 7
```

- `static` methods (similar to class methods) are accessed via class and they can only access `static` variables. NOTE: An instance variable (non static variable) can not be accessed from static methods

```c++
#include <iostream>
using namespace std;

// .h header file
class Test {
private:
    static int count;  // static variable
public:
    static void info() {  // static method accessing static variable
        cout << count << endl;
    }
};

// .cpp source
int Test::count = 7;

int main() {

    Test::info();

    return 0;
}

>>> 7
```

- `static` variables can be used to define constants. With `static`, initialization of `const` must be done in class declaration (i.e. in `ClassName.h` header file)

```c++
#include <iostream>
using namespace std;

// .h header file
class Test {
public:
	// Initialization of const must be done right here when using static
    static int const MAX = 1000; 
};

int main() {

    cout << Test::MAX << endl;

    return 0;
}

>>> 1000
```

- Since `static` variables are not only shared between objects of a class but they can be accessed via all the objects of the class and since they are not `const`'s they can be changed by the objects as well.

```c++
#include <iostream>
using namespace std;

// .h header file
class Test {
private:
    static int count; 
public:
    Test() { count++; }
    static void info() { 
        cout << count << endl;
    }
};

// .cpp source
int Test::count = 0;

int main() {

    Test::info();    
    Test test1;  // object 1
    Test::info(); 
    Test test2;  // object 2
    Test::info();
    
    return 0;
}

// Count increases as new objects are created
>>> 0
>>> 1
>>> 2
```

```c++
#include <iostream>
using namespace std;

// .h header file
class Test {
public:
    int id;
private:
    static int count; 
public:
    Test() { id = ++count; }  // increments then assigns
    int getID() { return id; }
};

// .cpp source
int Test::count = 0;

int main() {

    Test test1;
    cout << "Object-1 ID: " << test1.getID() << endl;
    Test test2;
    cout << "Object-2 ID: " << test2.getID() << endl;

    return 0;
}

>>> Object-1 ID: 1
>>> Object-2 ID: 2
```

### `struct`

```c++
struct Animal {

// By default, the variables are public
string name;
int num_legs;

}

class Animal {

// By default, the variables are private
string name;
int num_legs;
}
```

### C++ Libraries

- In C++ you can create a program with some code or a library. If you create a library, you can give the code as a compiled binary library to other developers together with the header files and they can link that code with the program and use it.

**Compilation Process**

- Pre-processor runs and processes anything that begins with `#`, e.g. `#include` statements
- Compilation process produces object files (`*.o`)
- Linking - The final stage of compilation is that you link all your `*.o` files together with any libraries that you have into an executable (`*.exe` on Win or no suffix on Unix platforms). External libraries that were used to develop your program can also be linked.

When you compile a program you have a choice between **static** libraries and **dynamic** libraries

- Static Libraries - They are files containing C++ code which are actually compiled into your program, i.e. static library is a bunch of C++ files that have been compiled into a binary file. And the idea is you give that binary file to other computer programmers. They can then link their program with it to create their executable and then use that code that was compiled into that static library. Static libraries will have suffix: `XYZ.lib` on Win, `libXYX.a` on Unix/Linux/Mac
- Dynamic Libraries - Libraries that contain code which the program finds when it actually runs not one it links. If you use `cout` your program is going to use code in a standard dynamic library that is already going to be present on any systems where that program is capable of running. *So in this case with dynamic libraries your program finds the relevant code at run time.* Dynamic libraries will have suffix: `XYZ.dll` on Win, `libXYZ.so` on Unix/Linux/Mac, and `XYZ.dylib` only on Mac


### Install SDL2 and Link With CLion

```
$ brew install sdl2
```

- Add the following to CMakeLists.txt

```
find_package(SDL2)
set(SDL2_LIBRARY /usr/local/Cellar/sdl2/2.0.8/lib/libSDL2.dylib)
target_link_libraries(<project-name> ${SDL2_LIBRARY})
```

- Use `#include "SDL2/SDL.h"` in `main.cpp`




### Important

- `memset(block-of-memory, value, number-of-bytes-to-set)` - Allows to set a block of memory with a particular value.

```c++
int *buffer = new int[3];
memset(buffer, 255, 3 * sizeof(int));
```

- Convention: Class member variables are usually prefixed with `m_`, e.g. `m_value`, to make it clear that they are instance variables
- `0x` is prefix to hexadecimal in C++, e.g. `0xFFFFFFFF`. And 2 digits in hexadecimal correspond to 1 byte (i.e. 8 bits)
- Left bit-shifting

```c++
unsigned int color = 0;  // 4 bytes

unsigned char alpha = 0xFF;  // 1 byte
unsigned char red = 0x12;  // And so on for green and blue

// Left bit shifting
color += alpha;
color <<= 8;
color += red;  // And so on for green and blue
```

- Right bit-shifting

```c++
int color = 0x123456;  // RGB
int red = color & 0xFF0000;  

/* 0xFF0000 = 111111110000000000000000 (8: 1, 8:0, 8:0) is called mask
 * Bitwise & operator will look at each bit in color and mask and set 
 */ value if there is 1 else set 0
 
cout << hex << "color: " << color << endl;
cout << hex << "  red: " << red << endl;

// Bitshift to get value
int RED = (color & 0xFF0000) >> 16;  // shifting by 2 bytes, i.e. 2 * 8 bits
int GREEN = (color & 0x00FF00) >> 8; // shifting by 1 byte

// Or do the following instead of bits
unsigned char uRed = color >> 16;
unsigned char uGreen = color >> 8;

>>> color: 123456
>>>   red: 120000
```

- Math functions, use `#include <math.h>`
- Random number generator, use `#include <stdlib.h>`
- In `struct` the `public` is default. `struct` is similar to `class` except in `class` the `private` is default

### Prefix and Postfix Operators

- `++i` - Prefix increment operator. The value will be incremented and used

```c++
int u = 7;
cout << "  u: " << u << endl;
cout << "++u: " << ++u << endl;  // Increment and use

>>>   u: 7
>>> ++u: 8
```
- `i++` - Postfix increment operator. The value will be used and then incremented

```c++
int u = 7;
cout << "u++: " << u++ << endl;  // Use
cout << "  u: " << u << endl;  // Increment

>>> u++: 7
>>>   u: 8
```

### Polymorphism (`virtual`)

- Destructors should always be declared `virtual` as they cleans up memory
- `virtual` is used for overriding methods

```c++
#include <iostream>
using namespace std;

#define Log(x) { cout << x << endl; }  // Function to print on screen

class Animal {
public:
	 // Need to declare method virtual only in the base class so it can
	 // be overridden by sub-class
    virtual void speak() = 0;
    virtual ~Animal() {};
};

class Canine: public Animal {
public:
    virtual void speak() { Log("Growl!") };  // Overriding speak method
    virtual ~Canine() {};
};

class Dog: public Canine {
public:
    virtual void speak() { Log("Bark!") }
    virtual ~Dog() {};  // Destructors should always be declared virtual
};

int main() {

    Animal* pAnimal = new Dog;  // Pointer to base class type
    pAnimal->speak();
    delete pAnimal;

    return 0;
}

>>> Bark!
```

### Creating Static Libraries

- Make sure to not use `#include <>` statements in `ClassName.h` file
- Make sure to not use `using namespace <...>` in `ClassName.cpp` file. Instead use `using namespace <...>` in `main.cpp` and use `prefix::function` in `ClassName.cpp`, e.g. `std::cout << "Test" << std::endl;`

### C++ Guidelines

[Core Guidelines](https://github.com/isocpp/CppCoreGuidelines)

