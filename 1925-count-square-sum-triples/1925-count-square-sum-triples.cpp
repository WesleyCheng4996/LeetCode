class Solution {
public:
    int countTriples(int n) {
        int ans = 0;
        for(int i = 1; i <= n; ++i) {
            for(int j = i + 1; j <= n; ++j) {
                int val = (i * i + j * j);
                int sq_val = sqrt(val);
                if(sq_val * sq_val == val && sq_val <= n) {
                    ans += 2;
                }
            }
        }
        return ans;
    }
};