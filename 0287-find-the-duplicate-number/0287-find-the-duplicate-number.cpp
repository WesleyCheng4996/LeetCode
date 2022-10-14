class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        bitset<100001>st;
        for(int x : nums) {
            if(st[x] == 1) {
                return x;
            }
            st[x] = 1;
        }
        return 0;
    }
};