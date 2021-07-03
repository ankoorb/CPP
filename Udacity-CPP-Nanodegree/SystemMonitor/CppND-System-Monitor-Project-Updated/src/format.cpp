#include <string>

#include "format.h"

using std::string;

// TODO: Complete this helper function
// INPUT: Long int measuring seconds
// OUTPUT: HH:MM:SS
// REMOVE: [[maybe_unused]] once you define the function
string Format::ElapsedTime(long seconds) {
    long hr {0};
    long min {0};
    long sec {0};

    hr = seconds / 3600;
    seconds = seconds % 3600;
    min = seconds / 60;
    sec = seconds % 60;

    string time = pad(hr) + ":" + pad(min) + ":" + pad(sec);
    return time;
}

std::string Format::pad(long n) {
    if (n < 10){
        return "0" + std::to_string(n);
    }
    return std::to_string(n);
}
