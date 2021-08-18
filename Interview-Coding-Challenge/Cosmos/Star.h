//
// Created by Ankoor Bhagat on 8/18/21.
//

#ifndef COSMOS_STAR_H
#define COSMOS_STAR_H


#include <vector>
#include "Object.h"
#include "Planet.h"

class Star : public Object {
public:
    std::vector<std::shared_ptr<Object>> planets_;

    Star(float x, float y, std::string type, std::string name, std::string parent);
};


#endif //COSMOS_STAR_H
