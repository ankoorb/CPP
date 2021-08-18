//
// Created by Ankoor Bhagat on 8/18/21.
//

#ifndef COSMOS_OBJECT_H
#define COSMOS_OBJECT_H


#include <memory>
#include <iostream>

class Object {
public:
    float x_;
    float y_;
    std::string type_;
    std::string name_;
    std::string parent_;

    Object(){};
    Object(float x, float y, std::string type, std::string name, std::string parent);

    static bool cmp_x(const std::shared_ptr<Object> a, const std::shared_ptr<Object> b){
        return a->x_ < b->x_;
    }

    static bool cmp_y(const std::shared_ptr<Object> a, const std::shared_ptr<Object> b){
        return a->y_ < b->y_;
    }

};


#endif //COSMOS_OBJECT_H
