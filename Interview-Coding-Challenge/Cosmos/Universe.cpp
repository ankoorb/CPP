//
// Created by Ankoor Bhagat on 8/18/21.
//

#include "Universe.h"

Universe::Universe(float x, float y, std::string file_name, char delimiter): x_{x}, y_{y}, file_name_{file_name}, delimiter_{delimiter} {

    ReadFile();

    GenerateLookUp();
    GenerateInvLookUp();

    UpdateStars();
    UpdatePlanets();

}


void Universe::ReadFile() {
    std::string line;
    std::ifstream file_stream(file_name_);

    //FORMAT: Type|Unique-Name|X-Coordinate|Y-Coordinate|Parent’s-Name|
    std::string type, name, coord_x, coord_y, parent;

    if (file_stream.is_open()){
        while (getline(file_stream, line)){
            replace(line.begin(), line.end(), delimiter_, ' ');
            std::istringstream line_stream(line);
            while (line_stream >> type >> name >> coord_x >> coord_y >> parent){

                if (type == "Galaxy"){
                    std::shared_ptr<Galaxy> galaxy = std::make_shared<Galaxy>(std::stof(coord_x), std::stof(coord_y), type, name, parent);
                    galaxies_.emplace_back(galaxy);
                } else if (type == "Star"){
                    std::shared_ptr<Star> star = std::make_shared<Star>(std::stof(coord_x), std::stof(coord_y), type, name, parent);
                    stars_.emplace_back(star);
                } else {
                    std::shared_ptr<Planet> planet = std::make_shared<Planet>(std::stof(coord_x), std::stof(coord_y), type, name, parent);
                    planets_.emplace_back(planet);
                }
            }
        }
    }
}


void Universe::GenerateLookUp() {
    for (const auto& galaxy: galaxies_){
        look_up_.emplace(galaxy->name_, galaxy);
    }

    for (const auto& star: stars_){
        look_up_.emplace(star->name_, star);
    }

    for (const auto& planet: planets_){
        look_up_.emplace(planet->name_, planet);
    }
}


void Universe::GenerateInvLookUp() {
    for (const auto& [name, obj_ptr]: look_up_){
        inv_look_up_[obj_ptr->parent_] = make_pair(name, obj_ptr);
    }
}


void Universe::UpdateStars() {
    for (const auto& star_ptr: stars_){
        if (look_up_.count(star_ptr->parent_) > 0){
            auto galaxy = look_up_.find(star_ptr->parent_);
            std::shared_ptr<Object> ptr = galaxy->second;
            std::static_pointer_cast<Galaxy>(ptr)->stars_.emplace_back(star_ptr);
        }
    }
}


void Universe::UpdatePlanets() {
    for (const auto& [parent, child]: inv_look_up_){
        if (child.second->type_ == "Planet"){
            if (look_up_.count(parent) > 0){
                auto star = look_up_.find(parent);
                std::shared_ptr<Object> ptr = star->second;
                std::static_pointer_cast<Star>(ptr)->planets_.emplace_back(child.second);
            }
        }
    }
}


std::shared_ptr<Object> Universe::KeySearch(std::string &key) {
    if (look_up_.count(key) > 0){
        auto child = look_up_.find(key);
        return child->second;
    }
    return nullptr;
}


std::pair<std::shared_ptr<Object>, std::shared_ptr<Object>> Universe::ParentSearch(std::string &key) {
    auto child = KeySearch(key);
    if (child != nullptr){
        if (look_up_.count(child->parent_) > 0){
            auto parent = look_up_.find(child->parent_)->second;
            return {child, parent};
        }
        return {nullptr, nullptr};
    }
}


float Universe::Distance(std::shared_ptr<Object> &obj_A, std::shared_ptr<Object> &obj_B) {
    float diff_x = obj_A->x_ - obj_B->x_;
    float diff_y = obj_A->y_ - obj_B->y_;
    return sqrt(diff_x * diff_x + diff_y * diff_y);
}


std::tuple<float, std::shared_ptr<Object>&, std::shared_ptr<Object>&> Universe::BruteForceClosestPairOfStars() {
    int n = stars_.size();
    std::vector<std::shared_ptr<Object>> stars(stars_.cbegin(), stars_.cend());
    std::tuple<float, std::shared_ptr<Object>, std::shared_ptr<Object>> result {Distance(stars[0], stars[1]), stars[0], stars[1]};
    for (auto i = 0; i < n; i++){
        for (auto j = i + 1; j < n; j++){
            float dist = Distance(stars[i], stars[j]);
            if (dist < std::get<0>(result)){
                std::get<0>(result) = dist;
                std::get<1>(result) = stars[i];
                std::get<2>(result) = stars[j];
            }
        }
    }
    return result;
}


void Universe::PrintInfo(std::string &object_A, std::string &object_B) {

    std::pair<std::shared_ptr<Object>, std::shared_ptr<Object>> pair_A = ParentSearch(object_A);
    std::pair<std::shared_ptr<Object>, std::shared_ptr<Object>> pair_B = ParentSearch(object_B);

    std::shared_ptr<Object> parent_A = pair_A.second;
    std::shared_ptr<Object> parent_B = pair_B.second;

    std::cout << std::endl;

    if (parent_A != nullptr){
        std::cout << "1. Parent of " << object_A << " is located at: (" << parent_A->x_ << ", " << parent_A->y_  << ")" << std::endl;
    }

    if (parent_B != nullptr){
        std::cout << "2. Parent of " << object_B << " is located at: (" << parent_B->x_ << ", " << parent_B->y_ << ")" << std::endl;
    }

    std::shared_ptr<Object> child_A = pair_A.first;
    std::shared_ptr<Object> child_B = pair_B.first;

    if (child_A != nullptr && child_B != nullptr){
        float distance = Distance(child_A, child_B);
        std::cout << "3. Distance between " << object_A << " and " << object_B << ": " << distance  << " units." << std::endl;
    }

    std::tuple<float, std::shared_ptr<Object>, std::shared_ptr<Object>> bf_closest = BruteForceClosestPairOfStars();
    float bf_d = std::get<0>(bf_closest);
    std::shared_ptr<Object> bf_closest_A = std::get<1>(bf_closest);
    std::shared_ptr<Object> bf_closest_B = std::get<2>(bf_closest);
    std::cout << "4. Brute Force O(n^2): Closest two stars in the Universe are: " << bf_closest_A->name_ << " and " << bf_closest_B->name_ << std::flush;
    std::cout << ", with distance: " << bf_d << " units away." << std::endl;

    std::tuple<float, std::shared_ptr<Object>, std::shared_ptr<Object>> closest = ClosestPairOfStars();
    float d = std::get<0>(closest);
    std::shared_ptr<Object> closest_A = std::get<1>(closest);
    std::shared_ptr<Object> closest_B = std::get<2>(closest);
    std::cout << "4. Divide & Conquer O(n log n): Closest two stars in the Universe are: " << closest_A->name_ << " and " << closest_B->name_ << std::flush;
    std::cout << ", with distance: " << d << " units away. [TODO: I need to fix the bug as output is not correct]" << std::endl;

    // Bonus: Convex Hull + Rotating Caliper
    std::cout << "5. (Bonus) TODO: Convex Hull + Rotating Caliper algorithms" << std::endl;

}

// Reference-0: http://www.csl.mtu.edu/cs4321/www/Lectures/Lecture%209%20-%20Divide%20and%20Conquer%20Closest%20Pair%20and%20Convex.htm
// Reference-1: https://www.geeksforgeeks.org/closest-pair-of-points-using-divide-and-conquer-algorithm/
// Reference-2: https://stackoverflow.com/questions/49966104/closest-pair-of-points-divideconquer-with-vectors
// Reference-3: Great explanation: https://www.youtube.com/watch?v=kCLGVat2SHk
std::tuple<float, std::shared_ptr<Object>&, std::shared_ptr<Object>&> Universe::MinDistance(
        std::vector<std::shared_ptr<Object>> objects_x, std::vector<std::shared_ptr<Object>> objects_y, int n) {

    if (n <= 3){
        float min_dist = MAXFLOAT;
        for (auto i = 0; i < n; i++){
            for (auto j = i + 1; j < n; j++){
                float dist= Distance(objects_x[i], objects_y[j]);
                if (dist < min_dist){
                    min_dist = dist;
                    std::tuple<float, std::shared_ptr<Object>, std::shared_ptr<Object>> result {min_dist, objects_x[i], objects_y[j]};
                    return result;
                }
            }
        }
    }

    // 1. Find mid index and body
    int mid = n / 2;
    std::shared_ptr<Object> body_mid = objects_x[mid];

    // 2. Divide vector of bodies into 2 halves
    std::vector<std::shared_ptr<Object>> objects_x_left(objects_x.cbegin(), objects_x.cbegin() + mid);
    std::vector<std::shared_ptr<Object>> objects_x_right(objects_x.cbegin() + mid, objects_x.cend());

    std::vector<std::shared_ptr<Object>> objects_y_left(objects_y.cbegin(), objects_y.cbegin() + mid);
    std::vector<std::shared_ptr<Object>> objects_y_right(objects_y.cbegin() + mid, objects_y.cend());

    // 3. Recursively calculate minimum distance at Left and Right regions
    std::tuple<float, std::shared_ptr<Object>, std::shared_ptr<Object>> out_left = MinDistance(objects_x_left, objects_y_left, mid);
    std::tuple<float, std::shared_ptr<Object>, std::shared_ptr<Object>> out_right = MinDistance(objects_x_right, objects_y_right, n - mid);

    // 4. Find closest pair out of closest left pair and closest right pair
    std::tuple<float, std::shared_ptr<Object>, std::shared_ptr<Object>> output {};
    float d_left = std::get<0>(out_left);
    float d_right = std::get<0>(out_right);

    if (d_left < d_right){
        output = out_left;
    } else {
        output = out_right;
    }

    // 5. Keep points that are within
    std::vector<std::shared_ptr<Object>> strip;
    for (auto i = 0; i < n; i++){
        if (abs(objects_x[i]->x_ - body_mid->x_) < std::get<0>(output)){
            strip.emplace_back(objects_y[i]);
        }
    }

    for (auto i = 0; i < strip.size(); i++){
        for (auto j = i + 1; j < strip.size() && abs(strip[j]->y_ - strip[i]->y_) < std::get<0>(output); i++){
            float dist = Distance(strip[i], strip[j]);
            if (dist < std::get<0>(output)){
                std::get<0>(output) = dist;
                std::get<1>(output) = strip[i];
                std::get<2>(output) = strip[j];
            }
        }
    }

    return output;
}


std::tuple<float, std::shared_ptr<Object>&, std::shared_ptr<Object>&> Universe::ClosestPairOfStars() {

    std::vector<std::shared_ptr<Object>> objects_x(stars_.cbegin(), stars_.cend());
    std::vector<std::shared_ptr<Object>> objects_y(stars_.cbegin(), stars_.cend());

    std::sort(objects_x.begin(), objects_x.end(), Object::cmp_x);
    std::sort(objects_y.begin(), objects_y.end(), Object::cmp_y);

    return MinDistance(objects_x, objects_y, stars_.size());
}




















