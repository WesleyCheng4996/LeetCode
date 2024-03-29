class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        ans.reserve(2);
        int x = 0, y = 0, count_x = 0, count_y = 0;
        for (auto i : nums) {
            if(x == i) {
                ++count_x;
            }
            else if(y == i) {
                ++count_y;
            }
            else if(count_x == 0) {
                x = i;
                count_x = 1;
            }
            else if(count_y == 0) {
                y = i;
                count_y = 1;
            }
            else {
                --count_x;
                --count_y;
            }
        }
        count_x = 0;
        count_y = 0;
        for (auto i : nums) {
            if (x == i) {
                ++count_x;
            }
            if (y == i) {
                ++count_y;
            }
        }
        if (count_x > nums.size() / 3) {
            ans.push_back(x);
        }
        if (count_y > nums.size() / 3 && x != y) {
            ans.push_back(y);
        }
        return ans;
    }
};