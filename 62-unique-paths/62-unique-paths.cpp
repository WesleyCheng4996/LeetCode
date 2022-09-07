class Solution {
public:
    int uniquePaths(int m, int n) {
        int sum = m + n - 2;
        long long ans = 1;
        for(int i = m > n ? m : n, j = 1; i <= sum; ++i, ++j) {
            ans *= i;
            ans /= j;
        }
        return ans;
    }
};