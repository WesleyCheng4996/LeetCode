class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int idx1 = 0, idx2 = 0;
        for(; idx2 < nums.size();) {
            if(idx2 + 1 < nums.size() && nums[idx2] == nums[idx2 + 1]) {
                nums[idx1++] = nums[idx2];
                nums[idx1++] = nums[idx2];
                idx2 += 2;
                while(idx2 < nums.size() && nums[idx2] == nums[idx2 - 1]) {
                    ++idx2;
                }
            } else {
                nums[idx1++] = nums[idx2++];
            }
        }
        return idx1;
    }
};