template<long long N>
struct ApplesInSideLen {
    long long arr[N];
    const long long len;
    constexpr ApplesInSideLen() :
    arr(),
    len(N)
    {
        for(long long i = 1; i < N; ++i) {
            arr[i] = arr[i - 1] + (12 * i * i);
        }
    }
};

constexpr ApplesInSideLen<100000> apples;

class Solution {
public:
    long long minimumPerimeter(long long neededApples) {
        return (long long)(lower_bound(apples.arr, apples.arr + apples.len, neededApples) - apples.arr) << 3;
    }
};