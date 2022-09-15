struct Pow_2 {
    long long arr[1000000];
    Pow_2() :
    arr() {
        for(long long i = 0; i < 1000000; ++i) {
            arr[i] = i * i; 
        }
    }
};

Pow_2 pow_2;

class Solution {
public:
    int mySqrt(int x) {
        return (upper_bound(pow_2.arr, pow_2.arr + 1000000, x) - pow_2.arr - 1);
    }
};