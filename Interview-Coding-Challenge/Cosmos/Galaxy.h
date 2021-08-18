//
// Created by Ankoor Bhagat on 8/18/21.
//

#ifndef COSMOS_GALAXY_H
#define COSMOS_GALAXY_H


#include <vector>
#include "Star.h"
#include "Object.h"


class Galaxy : public Object {
public:
    std::vector<std::shared_ptr<Object>> stars_;

    Galaxy(float x, float y, std::string type, std::string name, std::string parent);
};


#endif //COSMOS_GALAXY_H
