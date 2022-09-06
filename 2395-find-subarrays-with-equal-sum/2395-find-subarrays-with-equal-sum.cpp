class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        unordered_set<int>st;
        st.reserve(nums.size() - 1);
        for(int i = 0, end = nums.size() - 1; i < end; ++i) {
            int val(nums[i] + nums[i + 1]);
            if(st.count(val)) {
                return true;
            }
            st.insert(val);
        }
        return false;
    }
};