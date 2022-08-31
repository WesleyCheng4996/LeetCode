template<size_t N>
struct Constant {
    constexpr Constant() :
        arr()
        {
            arr[0] = 0;
            arr[1] = 0;
            for(int i = 2; i < N; ++i) {
                arr[i] = ((i * (i - 1)) >> 1);
            }
        }
    short arr[N];
};

constexpr Constant<101> c;

class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int ans = 0;
        char times_counter[101] = {0};
        for(auto x: nums) {
            ++times_counter[x];
        }
        for(auto x: times_counter) {
            ans += c.arr[x];
        }
        return ans;
    }
};