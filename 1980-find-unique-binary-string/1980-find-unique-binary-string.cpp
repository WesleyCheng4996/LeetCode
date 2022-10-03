class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        string ret(nums.size(), '0');
        for(int i = 0, end = nums.size(); i < end; ++i) {
            ret[i] = nums[i][i] == '0' ? '1' : '0';
        }
        return ret;
    }
};