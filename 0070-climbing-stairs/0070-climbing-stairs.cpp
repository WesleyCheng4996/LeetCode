template<size_t N>
struct Fib {
	constexpr Fib() : arr() {
		arr[0] = 1;
		arr[1] = 1;
		for (int i = 2; i < N; ++i) {
			arr[i] = arr[i - 1] + arr[i - 2];
		}
	}
	int arr[N];
};
constexpr Fib<46> f;

class Solution {
public:
    int climbStairs(int n) {
        return f.arr[n];
    }
};