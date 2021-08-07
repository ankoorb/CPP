#include <iostream>

using namespace std;

class Singleton {
public:
    // static -> Create at least one instance of Singleton class
    static Singleton& GetInstance(){
        static Singleton instance;
        return instance;
    }
public:
    // delete -> Eliminate the possibility to copy any existing singleton object
    Singleton(const Singleton&) = delete;
    void operator=(const Singleton&) = delete;
private:
    // private -> Eliminates possibility to create a Singleton object or destory it
    Singleton() = default;
    ~Singleton() = default;
};

int main() {

    auto& singleton = Singleton::GetInstance();

    // Singleton s; // Error


    return 0;
}