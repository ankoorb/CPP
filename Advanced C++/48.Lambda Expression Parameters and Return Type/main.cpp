#include <iostream>
using namespace std;

void testGreet(void (*p_greet)(string)){
    p_greet("Crush");
}

void runDivide(double (*p_divide)(double a, double b)){
    cout << p_divide(9, 3) << endl;
}

int main() {

    auto greet = [](string name){ cout << "Hello " << name << endl; };
    greet("Ankoor");

    testGreet(greet);

    // Return type
    auto add = [](int x, int y){ return x + y; };
    cout << add(7, 6) << endl;

//    auto divide = [](double x, double y){ return x / y; };
//    cout << divide(9, 3) << endl;

    auto divide = [](double a, double b) -> double { //-> double
        if(b == 0.0){
            return 0;
        } else {
            return a / b;
        }
    };

    cout << divide(9, 4) << endl;

    runDivide(divide);

    return 0;
}

/*
 * Using auto C++ can infer return types so there is no need in the lambda expression
 * to specify return type -> This works fine as long as there is one return statement,
 * it there are multiple return statement (i.e. multiple return types then C++ can not
 * infer what return type should be so error is raised so need to use trailing return
 * types syntax
 *
 * error: return type 'double' must match previous return type 'int' when lambda
 * expression has unspecified explicit return type
 *
 */