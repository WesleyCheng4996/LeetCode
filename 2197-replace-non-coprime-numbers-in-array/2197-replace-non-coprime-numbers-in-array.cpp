class Solution {
public:
    int GCD(int a, int b) {
        return b == 0 ? a : GCD(b, a % b);
    }
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int>stk;
        stk.push_back(nums.front());
        for(int i = 1; i < nums.size(); ++i) {
            int gcd;
            while(!stk.empty() && (gcd = GCD(stk.back(), nums[i])) != 1) {
                nums[i] *= stk.back() / gcd;
                stk.pop_back();
            }
            stk.push_back(nums[i]);
        }
        return stk;
    }
};