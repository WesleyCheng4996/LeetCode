template<size_t N>
struct Array{
    int arr[N + 1];
    constexpr Array() :
    arr() {
        int m = 0, n = 0;
        for(int i = 0; i < N; ++i) {
            arr[i] = m++ * n;
            arr[++i] = m * n++;
        }
    }
};
constexpr Array<10010> A;

class Solution {
public:
    int minOperations(int n) {
        return (n >> 1) * ((n + 1) >> 1);
    }
};