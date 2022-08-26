template<size_t N>
struct Fib {
	constexpr Fib() : arr() {
		arr[0] = 0;
		arr[1] = 1;
		for (int i = 2; i < N; ++i) {
			arr[i] = arr[i - 1] + arr[i - 2];
		}
	}
	int arr[N];
};
constexpr Fib<31> f;
class Solution {
public:
    int fib(int n) {
        return f.arr[n];
    }

};