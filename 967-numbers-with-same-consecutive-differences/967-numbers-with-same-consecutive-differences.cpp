class Solution {
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int>ans;
        int lower_bound = pow(10, n - 1);
        for(int i = 1; i <= 9; ++i) {
            Function(ans, lower_bound, k, i);
        }
        return ans;
    }
    void Function(vector<int>& vec, int lower_bound, int k, int curr) {
        
        if(curr >= lower_bound) {
            vec.push_back(curr);
            return;
        }
        int digit = curr % 10;
        if(digit - k >= 0) {
            Function(vec, lower_bound, k, (curr * 10 + digit - k));
        }
        if(digit + k < 10 && k != 0) {
            Function(vec, lower_bound, k, (curr * 10 + digit + k));
        }
        return;
    }
};