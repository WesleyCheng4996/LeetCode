template<size_t N>
struct Constant
{
    constexpr Constant() :
        arr()
    {
        arr[0] = 0;
        arr[1] = 0;
        for (int i = 2; i < N; ++i) {
            arr[i] = ((i * (i - 1)) << 2);
        }
    }
    int arr[N];
};


class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        constexpr Constant<30> c;
        unordered_map<int, int> mp;
        int nums_len = nums.size(), counter = 0;
        for (int i = 0; i < nums_len; ++i) {
            for (int j = i + 1; j < nums_len; ++j) {
                ++mp[nums[i] * nums[j]];
            }
        }
        for (auto x : mp) {
            counter += c.arr[x.second];
        }
        return counter;
    }
};