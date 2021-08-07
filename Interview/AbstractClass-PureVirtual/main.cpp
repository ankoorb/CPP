#include <iostream>
#include <vector>
#include <memory>

using namespace std;

class Account {
public:
    virtual void Display() const = 0; // Pure virtual function
};

class Savings : public Account {
public:
    void Display() const override { cout << "Savings Class" << endl; }
};

class Checking : public Account {
public:
    void Display() const override { cout << "Checking Class" << endl; }
};

class Trust : public Account {
public:
    void Display() const override { cout << "Trust Class" << endl; }
};


int main() {

    // Account acc(); // Error: Can not instantiate Abstract class
    // Account* ptr = new Account;

    vector<unique_ptr<Account>> accounts;

    unique_ptr<Account> savings_ptr = make_unique<Savings>();
    unique_ptr<Account> checking_ptr = make_unique<Checking>();

    accounts.emplace_back(move(savings_ptr));
    accounts.emplace_back(move(checking_ptr));

    accounts.emplace_back(make_unique<Trust>());

    for (const auto& account: accounts){
        account->Display();
    }

    return 0;
}