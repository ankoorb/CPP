#include <iostream>

template <class T>
class PtrDetails {
public:
    int ref_count_;
    T* mem_ptr;
    int array_size_;
    PtrDetails(T* obj, int size);
};

template <class T>
bool operator==(const PtrDetails<T>& obj_1, const PtrDetails<T>& obj_2){
    return obj_1.array_size_ == obj_2.array_size_ && obj_1.mem_ptr == obj_2.mem_ptr;
}

int main() {
    return 0;
}