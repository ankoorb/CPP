//
// Created by Ankoor Bhagat on 8/18/21.
//

#ifndef COSMOS_PLANET_H
#define COSMOS_PLANET_H


#include "Object.h"

class Planet : public Object {
public:
    Planet(float x, float y, std::string type, std::string name, std::string parent);
};


#endif //COSMOS_PLANET_H
