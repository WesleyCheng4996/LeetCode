class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int ret = 0, sum = 0;
        for(auto x: nums) {
            sum += x;
            if(sum < ret) {
                ret = sum;
            }
        }
        return -ret + 1;
    }
};