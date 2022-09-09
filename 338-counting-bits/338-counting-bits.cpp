template<size_t N>
struct Bits{
    int arr[N + 1];
    constexpr Bits() :
    arr() {
        for(int i = 0; i <= N; ++i) {
            arr[i] = __builtin_popcount(i);
        }   
    }
};

constexpr Bits<200000> b;

class Solution {
public:
    vector<int> countBits(int n) {
        return vector<int>(b.arr, b.arr + n + 1);
    }
};