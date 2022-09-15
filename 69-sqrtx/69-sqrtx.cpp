struct Pow_2 {
    long long arr[46341];
    constexpr Pow_2() :
    arr() {
        for(long long i = 0; i < 46341; ++i) {
            arr[i] = i * i; 
        }
    }
};

constexpr Pow_2 pow_2;

class Solution {
public:
    int mySqrt(int x) {
        return (upper_bound(pow_2.arr, pow_2.arr + 46341, x) - pow_2.arr - 1);
    }
};