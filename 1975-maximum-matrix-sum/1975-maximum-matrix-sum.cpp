class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int minnum = abs(matrix[0][0]), sign = 0;
        return accumulate(matrix.begin(), matrix.end(), 0LL, [&](long long sum, vector<int>vec) {
            return sum += accumulate(vec.begin(), vec.end(), 0LL, [&](long long sum, int num) {
                if(num < 0) {
                    sign ^= 1;
                    if(-num < minnum) {
                        minnum = -num;
                    }
                    return sum - num;
                } else {
                    if(num < minnum) {
                        minnum = num;
                    }
                    return sum + num;
                }
            });
        }) - (sign ? minnum << 1 : 0);
    }
};