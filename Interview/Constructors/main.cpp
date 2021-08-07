#include <iostream>
#include <string>
using namespace std;

class Player {
public:
    Player();
    Player(string name="", int health=100, int xp=1);

    // Copy constructor
    Player(const Player& other);

    ~Player(){};

private:
    int xp_;
    int health_;
    string name_;
};


Player::Player(string name, int health, int xp) : name_{name}, health_{health}, xp_{xp} {};


Player::Player(const Player &other) : name_{other.name_}, health_{other.health_}, xp_{other.xp_} {
    cout << "Copy Constructor" << endl;
}


int main() {

    Player human();
    Player thief("Thief");
    Player dwarf("Dwarf", 75);
    Player orc("Orc", 90, 25);
    Player dragon(thief);

    return 0;
}
