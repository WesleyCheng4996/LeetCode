struct Fib {
    int arr[45];
    constexpr Fib() :
    arr() {
        arr[0] = 1;
        arr[1] = 1;
        for(int i = 2; i < 45; ++i) {
            arr[i] = arr[i - 1] + arr[i - 2];
        }
    }
};
constexpr Fib fib;

class Solution {
public:
    int findMinFibonacciNumbers(int k) {
        int ret = 0;
        int idx = 45;
        while(k) {
            idx = (upper_bound(fib.arr, fib.arr + idx, k) - fib.arr - 1);
            k -= fib.arr[idx];
            ++ret;
        }
        return ret;
    }
};