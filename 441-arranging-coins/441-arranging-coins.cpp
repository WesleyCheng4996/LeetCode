struct Sum {
    constexpr Sum() :
    arr() {
        for(int i = 1; i < 100000; ++i) {
            arr[i] = arr[i - 1] + i; 
        }
    }
    long long arr[100000];
};

constexpr Sum s;

class Solution {
public:
    int arrangeCoins(int n) {
        return upper_bound(s.arr, s.arr + 100000, n) - s.arr - 1;
    }
};