struct Table{
    int arr[10001];
    constexpr Table() : 
        arr()
    {
        int val = 0;
        for(int i = 0; i < 10001; ++i) {
            arr[i] = val ^= i;
        }
    }
};
constexpr Table t;
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        return t.arr[nums.size()] ^ accumulate(nums.begin(), nums.end(), 0, [](int sum, int x) { return sum ^ x; });
    }
};