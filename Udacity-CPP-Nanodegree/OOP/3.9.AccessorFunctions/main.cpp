#include <iostream>
#include <string>

using namespace std;

class BankAccount {
private:
    string _name;
    int _account;
    int _funds;

public:
    BankAccount(string name, int account, int funds);

    // Setters / Mutators
    void setName(string name);
    void setAccount(int account);
    void setFunds(int funds);

    // Getters / Accessors
    string getName() const;
    int getAccount() const;
    int getFunds() const;
};


int main() {

    BankAccount customer("Ankoor", 949, 10000);
    cout << "Name: " << customer.getName() << endl;
    cout << "Account: " << customer.getAccount() << endl;
    cout << "Funds: " << customer.getFunds() << endl;

    return 0;
}

BankAccount::BankAccount(string name, int account, int funds) {
    setName(name);
    setAccount(account);
    setFunds(funds);
}

void BankAccount::setName(string name) {
    _name = name;
}

void BankAccount::setAccount(int account) {
    _account = account;
}

void BankAccount::setFunds(int funds) {
    _funds = funds;
}

string BankAccount::getName() const {
    return _name;
}

int BankAccount::getAccount() const {
    return _account;
}

int BankAccount::getFunds() const {
    return _funds;
}