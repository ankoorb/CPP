#include <iostream>
#include <array>
#include <memory>

template <class T, int SIZE>
class Image {
public:
    using ptr_ = std::unique_ptr<Image<T, SIZE>>;
    std::array<T, SIZE> data_;
};

template <int SIZE>
using Imagef = Image<float, SIZE>;

int main() {

    using Image3f = Imagef<3>;
    auto img_ptr = Image3f::ptr_(new Image3f);

    return 0;
}