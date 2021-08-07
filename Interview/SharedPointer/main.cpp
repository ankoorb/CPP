#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class Test {
public:
    Test() : data_{0} { cout << "Test Constructor: " << data_ << endl; }
    Test(int data) : data_{data}{ cout << "Test Constructor: " << data_ << endl; }
    int getData() const { return data_; }
    ~Test(){ cout << "Test Destructor" << endl; }
private:
    int data_;
};

void Display(shared_ptr<Test>& p){
    cout << "Use count: " << p.use_count() << endl;
}


int main() {

    shared_ptr<int> p1 = make_shared<int>(7);
    cout << "Use count: " << p1.use_count() << endl;

    shared_ptr<int> p2 = p1;
    cout << "Use count: " << p2.use_count() << endl;

    shared_ptr<int> p3 = p1;
    cout << "Use count: " << p3.use_count() << endl;

    p1.reset();
    cout << "Use count: " << p1.use_count() << endl;
    cout << "Use count: " << p2.use_count() << endl;
    cout << "Use count: " << p3.use_count() << endl;
    cout << endl;


    shared_ptr<Test> t1 = make_shared<Test>(10);
    Display(t1);
    cout << "1. Use count: " << t1.use_count() << endl;
    {
        shared_ptr<Test> t2 = t1;
        cout << "2. Use count: " << t1.use_count() << endl;
        {
            shared_ptr<Test> t3 = t1;
            cout << "3. Use count: " << t1.use_count() << endl;
            t1.reset();
        }
        cout << "4. Use count: " << t1.use_count() << endl;
    }
    cout << "5. Use count: " << t1.use_count() << endl;


    vector<shared_ptr<Test>> tests;

    shared_ptr<Test> t4 = make_shared<Test>(10);
    shared_ptr<Test> t5 = make_shared<Test>(100);

    tests.emplace_back(t4); // Use count will be 2 because vector copied
    tests.emplace_back(t5); // Use count will be 2 because vector copied
    tests.emplace_back(make_shared<Test>(20));
    tests.emplace_back(make_shared<Test>(30));
    tests.emplace_back(make_shared<Test>(40));
    tests.emplace_back(make_shared<Test>(50));

    shared_ptr<Test> t6 = make_shared<Test>(60);
    tests.emplace_back(move(t6));
    cout << "\nLoop\n" << endl;
    for (const auto& test: tests){
        cout << test.use_count() << endl;
    }

    cout << endl;

    for (auto test: tests){  // Without reference range loop copes
        cout << test.use_count() << endl;
    }

    return 0;
}