#include <iostream>

using namespace std;

class CustomString {
public:
    CustomString();
    CustomString(const char* s);
    CustomString(const CustomString& other);
    ~CustomString();

    // Overloading assignment (=) operator
    CustomString& operator=(const CustomString& rhs);

    // Overloading move assignment (=) operator
    CustomString& operator=(CustomString&& rhs);

    // Overloading - operator (make lowercase)
    CustomString operator- () const;

    // Overloading == equality operator
    bool operator==(const CustomString& rhs) const;

    // Overloading + concatenation operator
    CustomString operator+(const CustomString& rhs) const;

    // Overloading  - operator (make lowercase)
    //friend CustomString operator-(const CustomString& obj);

    // Overloading + operator (concatenate)
    //friend CustomString operator+(const CustomString& lhs, CustomString& rhs);

    //friend ostream& operator<<(ostream& os, const CustomString& obj);

    void Display() const;
    int Length() const;
    const char* GetString() const;

private:
    char* str_;
};

CustomString::CustomString(): str_{nullptr}{
    str_ = new char[1];
    *str_ = '\0';
};

CustomString::CustomString(const char *s): str_{nullptr} {
    if (s == nullptr){
        str_ = new char[1];
        *str_ = '\0';
    } else {
        str_ = new char[std::strlen(s) + 1];
        std::strcpy(str_, s);
    }
}

CustomString::~CustomString() {
    delete [] str_;
}

void CustomString::Display() const { cout << str_ << " : " << Length() << "\n" << endl; }

int CustomString::Length() const { return std::strlen(str_); }

const char* CustomString::GetString() const { return str_; }

CustomString& CustomString::operator=(const CustomString &rhs) {
    cout << "Copy Assignment" << endl;
    // Check for self assignment
    if (this == &rhs){
        return *this; // return current object by reference
    }

    // Deallocate because we are overwriting
    delete [] str_;
    str_ = new char[std::strlen(rhs.str_) + 1];
    std::strcpy(str_, rhs.str_);

    return *this;
}


// rhs object reference can not be const because we are modifying that object
CustomString& CustomString::operator=(CustomString &&rhs) {
    cout << "Move Assignment" << endl;
    // Check for self assignment
    if (this == &rhs){
        return *this; // return current object by reference
    }

    // Deallocate because we are overwriting
    delete [] str_;
    str_ = rhs.str_;
    rhs.str_ = nullptr;

    return *this;
}

// const because we do not want to modify the object
CustomString CustomString::operator-() const {
    char* buffer = new char[std::strlen(str_) + 1];
    std::strcpy(buffer, str_);

    for (auto i = 0; i < std::strlen(buffer); i++){
        buffer[i] = std::tolower(buffer[i]);
    }

    CustomString output(buffer);
    delete [] buffer;
    return output;
}

bool CustomString::operator==(const CustomString &rhs) const {
    if (std::strcmp(str_, rhs.str_) == 0){
        return true;
    }
    return false;
}

CustomString CustomString::operator+(const CustomString &rhs) const {
    auto size = std::strlen(str_) + std::strlen(rhs.str_) + 1;
    char* buffer = new char[size];
    std::strcpy(buffer, str_);
    std::strcat(buffer, rhs.str_);
    CustomString output(buffer);
    delete [] buffer;
    return output;
}

//CustomString CustomString::operator-(const CustomString &obj) {
//    char* buffer = new char[std::strlen(obj.str_) + 1];
//    std::strcpy(buffer, obj.str_);
//
//    for (auto i = 0; i < std::strlen(buffer); i++){
//        buffer[i] = std::tolower(buffer[i]);
//    }
//
//    CustomString output(buffer);
//    delete [] buffer;
//    return output;
//}

//CustomString CustomString::operator+(const CustomString &lhs, CustomString &rhs) {
//    auto size = std::strlen(lhs.str_) + std::strlen(rhs.str_) + 1;
//    char* buffer = new char[size];
//    std::strcpy(buffer, lhs.str_);
//    std::strcat(buffer, rhs.str_);
//    CustomString output(buffer);
//    delete [] buffer;
//    return output;
//}

//ostream& CustomString::operator<<(ostream &os, const CustomString &obj) {
//    os << obj.str_;
//    return os;
//}

//ofstream& operator<<(ostream& os, const CustomString& obj){
//    os << obj.str_;
//    return os;
//}

int main() {

    CustomString a("Ferrari");
    CustomString b = a; // Copy Constructor used
    b.Display();

    CustomString c("Renault");

    // Assignment operator check
    b = c;
    b.Display();

    // Move assignment operator check
    c = CustomString("Lotus"); // CustomString("Lotus") is R-value
    c.Display();

    // Make lowercase - operator check
    cout << "\n- Lowercase check" << endl;
    //b.Display();

    // Equality operator check
    cout << "\nEquality" << endl;
    bool state = (a == c);
    cout << boolalpha << state << endl;

    // Concatenate operator check
    cout << "\nConcatenate" << endl;
    CustomString d = a + c;
    d.Display();

    // Overloading << insertion operator
    //cout << a << endl;

    return 0;
}

































