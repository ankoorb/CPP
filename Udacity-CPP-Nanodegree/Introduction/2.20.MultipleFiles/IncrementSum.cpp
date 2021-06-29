//
// Created by Ankoor Bhagat on 6/28/21.
//

#include "IncrementSum.h"
#include "VectorAddOne.h"

int IncrementAndComputeVectorSum(std::vector<int> v)
{
    int total = 0;
    AddOneToEach(v);
    for (auto &i : v)
    {
        total += i;
    }
    return total;
}
