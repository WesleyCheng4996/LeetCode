class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        unordered_set<int>st(nums.begin(), nums.end());
        vector<int>ret;
        for(int i = 1; i <= nums.size(); ++i) {
            if(st.count(i) == 0) {
                ret.push_back(i);
            }
        }
        return ret;
    }
};