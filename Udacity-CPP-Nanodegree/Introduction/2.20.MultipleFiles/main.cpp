#include <iostream>
#include <vector>
#include "incrementSum.h"

int main()
{
    std::vector<int> v{1, 2, 3, 4};
    int total = IncrementAndComputeVectorSum(v);
    std::cout << " The total is = " << total << "\n";
    return 0;
}