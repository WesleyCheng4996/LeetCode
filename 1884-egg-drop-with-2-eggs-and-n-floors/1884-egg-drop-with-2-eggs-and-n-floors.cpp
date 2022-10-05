struct Floor {
    int arr[1036];
    constexpr Floor() :
    arr() {
        int *ptr = this->arr + 1;
        for(int i = 1; i < 46; ++i) {
            for(int j = 0; j < i; ++j) {
                *ptr++ = i;
            }
        }
    }
};

constexpr Floor F;

class Solution {
public:
    int twoEggDrop(int n) {
        return F.arr[n];
    }
};