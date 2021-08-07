#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

template <typename T>
class Cyclic {
public:
    Cyclic(size_t capacity) {
        assert(capacity != 0 && "Buffer capacity must not be 0");
        buffer_.resize(capacity);
        iter_ = buffer_.begin();
    };

    void push(T& data){
        *iter_ = data;
        iter_++;
        if (iter_ == buffer_.end()){
            if(buffer_full_ == false){
                buffer_full_ = true;
            }
            iter_ = buffer_.begin();
        }
    }

    vector<T> getBuffer() const {
        size_t idx = iter_ - buffer_.begin();
        if (idx != 0){
            if (buffer_full_){
                return buffer_;
            } else {
                return {buffer_.begin(), buffer_.begin() + idx};
            }
        } else {
            return buffer_;
        }
    }

private:
    bool buffer_full_ {false};
    vector<T> buffer_;
    typename vector<T>::iterator iter_;
};

int main() {

    //Cyclic<int> data(0);

    Cyclic<int> data(5);

    //vector<int> v {0, 1, 2};
    //vector<int> v {0, 1, 2, 3, 4, 5, 6, 7};
    vector<int> v {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    for (auto e: v){
        data.push(e);
    }

    for (auto d: data.getBuffer()){
        cout << d << endl;
    }

    return 0;
}
