class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int>count;
        for(int x : nums) {
            ++count[x];
        }
        for(auto&[num, times] : count) {
            if(times == 1) {
                return num;
            }
        }
        return -1;
    }
};