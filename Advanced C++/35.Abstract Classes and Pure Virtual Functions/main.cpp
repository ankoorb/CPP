//#include <iostream>
//using namespace std;
//
//class Animal {
//public:
////    Animal()= default;
//    virtual void speak()=0;  // All animals should have a method called speak, Pure virtual function
//    virtual void run()=0;  // Now can not instantiate Dog
//};
//
//class Dog: public Animal {
//public:
//    virtual void speak(){ cout << "Woof!" << endl; }
//};
//
//class Doberman: public Dog {
//public:
//    Doberman(){ cout << "New Doberman" << endl; }
//    virtual void run() { cout << "Sprint" << endl; }
//};
//
//void test(Animal &a) {
//    a.speak();
//}
//
//int main() {
//
//    Doberman dog;
//    dog.speak();
//    dog.run();
//
//    //Animal animal;
//    //animal.speak();  // error: variable type 'Animal' is an abstract class
//
////    Animal animals[2];
//    Doberman dogs[5];  // Constructors of Doberman runs
//
//    Animal *animals[5];
//    animals[0] = &dog;
//    animals[0]->run();
//
//    test(dog);
//
//    return 0;
//}

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
    a.speak();}

int main() {

    Doberman dog;

    Animal *animals[3];
    animals[0] = &dog;
    animals[0]->speak();

    test(dog);

    return 0;
}

/*
 * Sometimes you want to create a class hierarchy and you want to have a base class but it
 * does not make sense to instantiate. For example, imagine that you are going to create
 * classes representing different kinds of animals. The reasons why you might want those
 * to derive from the same base class, after all dogs, cats, etc are all types of animals,
 * so it makes sense to derive from same base class. But there is no sense in instantiating
 * an animal class. Now for that purpose we have an abstract class. An abstract class is a
 * class containing methods which have no implementation and we say that they are pure virtual
 * functions or methods.
 *
 * virtual void speak()=0 -> The prototype of speak is set to 0. This notation means that
 * there is no implementation of this. This is what we call a pure virtual function. And class
 * which contains pure virtual functions is called abstract class.
 *
 * In your class you have got to implement all pure virtual functions declared in parent class
 * if you want to be allowed to instantiate your sub class.
 *
 * Animal animals[]; -> We can not create an array from abstract base class because when
 * you create an array of objects that actually runs the constructors of the objects.
 *
 * You can not create an array of animals because we can not run the constructor of animal
 * because it is an abstract class so we can not instantiate it, we can not run the
 * constructor or copy constructor.
 *
 * We could create a vector of animals but it wont be of any use.
 *
 * We could create an array of pointers to animal class.
 *
 *
 */