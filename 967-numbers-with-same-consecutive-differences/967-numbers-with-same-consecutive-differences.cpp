class Solution {
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int>ans;
        for(int i = 1; i <= 9; ++i) {
            Function(ans, n, k, i);
        }
        return ans;
    }
    void Function(vector<int>& vec, int len, int k, int curr) {
        
        if(curr >= pow(10, len - 1)) {
            vec.push_back(curr);
            return;
        }
        if((curr % 10) - k >= 0) {
            Function(vec, len, k, (curr * 10 + (curr % 10 - k)));
        }
        if((curr % 10 + k) < 10 && k != 0) {
            Function(vec, len, k, (curr * 10 + (curr % 10 + k)));
        }
        return;
    }
};