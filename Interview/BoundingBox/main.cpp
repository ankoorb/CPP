#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

class BBox {
    friend ostream& operator<<(ostream& os, const BBox& box);
private:
    int id_;
    float x_;
    float y_;
    float width_;
    float height_;
    float prob_;
    int type_;

public:
    BBox(int id, float x, float y, float width, float height, float prob, int type) : id_{id}, x_{x}, y_{y}, width_{width}, height_{height}, prob_{prob}, type_{type}{}

    static float IOU(const BBox& a, const BBox& b);
    int getID() const { return id_; }
    int getType() const { return type_; }
    float getProb() const { return prob_; }
    bool operator<(const BBox& other);
};

float BBox::IOU(const BBox& a, const BBox& b) {
    float x = max(a.x_, b.x_);
    float y = max(a.y_, b.y_);
    float width = max(min(a.x_ + a.width_, b.x_ + b.width_) - x, 0.0f);
    float height = max(min(a.y_ + a.height_, b.y_ + b.height_) - y, 0.0f);
    float overlap_area = width * height;
    float union_area = a.width_ * a.height_ + b.width_ * b.height_ - overlap_area;
    return overlap_area / union_area;
}

bool BBox::operator<(const BBox& other){
    if (prob_ < other.prob_){
        return true;
    }
    return false;
}

ostream& operator<<(ostream& os, const BBox& box){
    os << "id: " << box.id_ << ", x: " << box.x_ << ", y: " << box.y_ << ", width: " << box.width_ << ", height: " << box.height_ << ", prob: " << box.prob_;
    return os;
}

vector<int> NMS(vector<BBox>& boxes, const float& threshold){
    //TODO: Fix the bugs
    int n = boxes.size();
    vector<int> suppress;
    BBox& pick = boxes.back();
    for (auto i = 0; i < n - 1; i++){
        bool type_check = pick.getType() == boxes[i].getType();
        float iou = BBox::IOU(pick, boxes[i]);
        if (iou > threshold && type_check){
            suppress.emplace_back(i);
        }
    }
    return suppress;
}


int main() {

    float iou_threshold = 0.2f;

    BBox a {1, 190, 380, 300, 150, 0.9, 1}; // class-1
    BBox b {2, 300, 420, 150, 210, 0.98, 1}; // class-1
    BBox c {3, 320, 360, 200, 230, 0.82, 1}; // class-1
    BBox d {4, 390, 50, 300, 330, 0.87, 2}; // class-2
    BBox e {5, 490, 45, 200, 500, 0.98, 2}; // class-2
    BBox f {6, 480, 130, 150, 400, 0.82, 2}; // class-2

    bool check = a < b;
    cout << boolalpha << check << endl;

    vector<BBox> boxes {a, b, c, d, e, f};

    auto cmp = [](const auto& a, const auto& b){ return a.getProb() < b.getProb(); };
    sort(boxes.begin(), boxes.end(), cmp);
    vector<int> suppress = NMS(boxes, iou_threshold);
    for (auto s: suppress){
        cout << s << endl;
    }

    for (auto i = 0; i < boxes.size() - 1; i++){
        for (auto j = i + 1; j < boxes.size(); j++){

            float iou = BBox::IOU(boxes[i], boxes[j]);
            cout << boxes[i].getID() << " and " << boxes[j].getID() << " iou: " << iou << endl;
        }
    }
    cout << endl;

    for (auto box: boxes){
        cout << box.getID() << " and type: " << box.getType() << endl;
    }

    return 0;
}
