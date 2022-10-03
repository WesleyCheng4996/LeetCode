class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        set<int> st;
        for(int i = 0; i < nums.size(); ++i) {
            if(nums[i] == key) {
                int jj = i + k > nums.size() - 1 ? nums.size() - 1 : i + k;
                for(int j = max(0, i - k), end = jj; j <= end; ++j) {
                    st.insert(j);
                }
            }
        }
        return vector<int>(st.begin(), st.end());
    }
};