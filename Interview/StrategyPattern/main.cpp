#include <iostream>

using namespace std;

class Strategy {
public:
    virtual void Print() const = 0;
};

class StrategyA : public Strategy {
public:
    void Print() const override { cout << "Strategy-A" << endl; }
};

class StrategyB : public Strategy {
public:
    void Print() const override { cout << "Strategy-B" << endl; }
};

class Process {
public:
    Process(const Strategy& s) : strategy_{s} {}
    void Print() const { strategy_.Print(); }
    const Strategy& strategy_;
};

int main() {

    Process(StrategyA()).Print();
    Process(StrategyB()).Print();

    return 0;
}