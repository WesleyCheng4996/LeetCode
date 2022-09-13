class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        for(vector<int>vec: ops) {
            if(m > vec[0]) {
                m = vec[0];
            }
            if(n > vec[1]) {
                n = vec[1];
            }
        }
        return m * n;
    }
};