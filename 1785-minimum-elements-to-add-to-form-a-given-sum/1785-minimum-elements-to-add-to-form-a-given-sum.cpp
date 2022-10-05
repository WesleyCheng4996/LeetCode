class Solution {
public:
    int minElements(vector<int>& nums, int limit, int goal) {
        long long sum = 0;
        for(int x : nums) {
            sum += x;
        }
        return ceil((double)abs(goal - sum) / limit);
    }
};