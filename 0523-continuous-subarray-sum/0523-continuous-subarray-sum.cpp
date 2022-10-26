class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_set<int>st;
        int pre = 0, sum = 0;
        for(int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            sum %= k;
            if(st.count(sum)) {
                return true;
            }
            st.insert(pre);
            pre = sum;
        }
        return false;
    }
};