class Solution {
public:
    int min(int a, int b){
        return (a < b ? a : b);
    }
    int abs(int x) {
        return (x ^ (x >> 31)) - (x >> 31);
    }
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int minnum = abs(matrix[0][0]), sign = 0;
        return accumulate(matrix.begin(), matrix.end(), 0LL, [&](long long sum, vector<int>vec) {
            return sum += accumulate(vec.begin(), vec.end(), 0LL, [&](long long sum, int num) {
                sign += (num < 0);
                minnum = min(minnum, abs(num));
                return sum + abs(num);
            });
        }) - (sign & 1 ? minnum << 1 : 0);
    }
};