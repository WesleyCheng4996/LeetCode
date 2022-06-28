class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        set<int>st;
        for (auto& x : nums) {
            st.insert(x);
        }
        int pre = *st.begin();
        int max = 0;
        for (set<int>::iterator x = st.begin(); x != st.end(); ++x) {
            if (*x == pre + 1) {
                int count = 1;
                for (; x != st.end() && *x == pre + 1; ++count, ++x) {
                    pre = *x;
                }
                if (count > max) {
                    max = count;
                }
                if (x == st.end()) {
                    break;
                }
            }
            pre = *x;
        }
        return max == 0? 1 : max;
    }
};