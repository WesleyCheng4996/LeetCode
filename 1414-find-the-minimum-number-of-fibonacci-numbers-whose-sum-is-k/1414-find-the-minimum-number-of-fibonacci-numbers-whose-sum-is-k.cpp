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
        while(k) {
            k -= fib.arr[(upper_bound(fib.arr, fib.arr + 45, k) - fib.arr - 1)];
            ++ret;
        }
        return ret;
    }
};