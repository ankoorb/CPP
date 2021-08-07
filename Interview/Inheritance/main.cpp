#include <iostream>
#include <string>

using namespace std;

class Base {
public:
    Base() : value_{0} { cout << "Base (no args) Constructor" << endl; }
    Base(int value) : value_{value} {cout << "Base (int arg) Constructor" << endl; }
    Base(const Base& other) : value_{other.value_} {
        cout << "Base Copy Constructor" << endl;
    }
    Base& operator=(const Base& rhs){
        if (this != &rhs){
            value_ = rhs.value_;
        }
        cout << "Base = operator" << endl;
        return *this;
    }
    ~Base() { cout << "Base Destructor" << endl; }
private:
    int value_;
};

class Derived : public Base {
public:
    Derived() : Base(), doubled_value_{0} { cout << "Derived (no args) Constructor" << endl; }
    Derived(int value) : Base(value), doubled_value_{2 * value} { cout << "Derived (int arg) Construct" << endl; }
    Derived(const Derived& other) : Base(other), doubled_value_{other.doubled_value_} {
        cout << "Derived Copy Constructor" << endl;
    }
    Derived& operator=(const Derived& rhs){
        if (this != &rhs){
            Base::operator=(rhs);
            doubled_value_ = rhs.doubled_value_;
        }
        cout << "Derived = operator" << endl;
        return *this;
    }
    ~Derived() { cout << "Derived Destructor" << endl; }
private:
    int doubled_value_;
};


class Account {
    friend ostream& operator<<(ostream& os, const Account& account);
public:
    Account();
    Account(float balance);
    ~Account();
    void Deposit(float amount);
    void Withdraw(float amount);

protected:
    float balance_;
};

class SavingsAccount : public Account {
    friend ostream& operator<<(ostream&, const SavingsAccount& acc);
public:
    SavingsAccount();
    SavingsAccount(float balance, float interest);
    ~SavingsAccount();
    void Deposit(float amount);

private:
    float interest_;
};

Account::Account() : Account(0.0f){}

Account::Account(float balance) : balance_{balance} {}

Account::~Account() {}

void Account::Deposit(float amount) {
    balance_ += amount;
    cout << "Account Deposit" << endl;
}

void Account::Withdraw(float amount) {
    if (balance_ - amount >= 0){
        balance_ -= amount;
    } else {
        cout << "Insufficient balance" << endl;
    }
}

ostream& operator<<(ostream& os, const Account& acc){
    os << "Account balace: " << acc.balance_;
    return os;
}

SavingsAccount::SavingsAccount() : SavingsAccount(0.0f, 0.0f){}

SavingsAccount::SavingsAccount(float balance, float interest): Account(balance), interest_{interest} {}

SavingsAccount::~SavingsAccount() {}

void SavingsAccount::Deposit(float amount) {
    amount += amount * interest_;
    Account::Deposit(amount);
    cout << "Savings Account Deposit" << endl;
}

ostream& operator<<(ostream& os, const SavingsAccount& acc){
    os << "Savings balance: " << acc.balance_;
    return os;
}

int main() {

//    Base b;
//    Base bb(7);
//    Base bbb(b);

//    Derived d;
//    Derived dd(15);
//    d = dd;

    Account primary;
    primary.Deposit(100.0f);
    cout << primary << endl;
    primary.Withdraw(200.0f);
    cout << endl;

    SavingsAccount savings(1000, 0.05);
    savings.Deposit(150);
    cout << savings << endl;
    savings.Withdraw(1200.0f);
    cout << endl;

    // C++: Static binding of method calls, compiler saw Account object so called its method
    Account* account = new SavingsAccount();
    account->Deposit(250.f); // Account::Deposit() called instead of SavingsAccount::Deposit()

    return 0;
}
