//
// Created by Ankoor Bhagat on 8/18/21.
//

#ifndef COSMOS_UNIVERSE_H
#define COSMOS_UNIVERSE_H


#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <tuple>
#include "Star.h"
#include "Galaxy.h"
#include "Object.h"
#include "Planet.h"

class Universe {
public:
    float x_;
    float y_;

    char delimiter_;
    std::string file_name_;

    std::vector<std::shared_ptr<Object>> planets_;
    std::vector<std::shared_ptr<Object>> stars_;
    std::vector<std::shared_ptr<Object>> galaxies_;

    std::multimap<std::string, std::shared_ptr<Object>> look_up_;
    std::map<std::string, std::pair<std::string, std::shared_ptr<Object>>> inv_look_up_;

    Universe(float x, float y, std::string file_name, char delimiter);

    void ReadFile();
    void UpdateStars();
    void UpdatePlanets();
    void GenerateLookUp();
    void GenerateInvLookUp();
    void PrintInfo(std::string& object_A, std::string& object_B);

    std::shared_ptr<Object> KeySearch(std::string& key);
    std::pair<std::shared_ptr<Object>, std::shared_ptr<Object>> ParentSearch(std::string& key);
    static float Distance(std::shared_ptr<Object>& obj_A, std::shared_ptr<Object>& obj_B);

    static std::tuple<float, std::shared_ptr<Object>&, std::shared_ptr<Object>&> MinDistance(std::vector<std::shared_ptr<Object>> objects_x, std::vector<std::shared_ptr<Object>> objects_y, int n);
    std::tuple<float, std::shared_ptr<Object>&, std::shared_ptr<Object>&> ClosestPairOfStars();
    std::tuple<float, std::shared_ptr<Object>&, std::shared_ptr<Object>&> BruteForceClosestPairOfStars();

};


#endif //COSMOS_UNIVERSE_H
