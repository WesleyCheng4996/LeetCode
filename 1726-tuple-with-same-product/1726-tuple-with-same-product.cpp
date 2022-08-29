template<size_t N>
struct Constant
{
    constexpr Constant() :
        arr()
    {
        int count = 0;
        arr[0] = 0;
        arr[1] = 0;
        for (int i = 1; i < N; ++i) {
            count += (i << 3);
            arr[i + 1] = count;
        }
    }
    int arr[N + 1];
};


Constant<30> c;


class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
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