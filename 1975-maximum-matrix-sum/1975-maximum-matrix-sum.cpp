class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long ret = 0, minnum = abs(matrix[0][0]), sign = 0;
        for(vector<int> &vec : matrix) {
            for(int x : vec) {
                
                if(x < 0) {
                    int num = abs(x);
                    if(num < minnum) {
                        minnum = num;
                    }
                    ++sign;
                    ret += num;
                } else {
                    if(x < minnum) {
                        minnum = x;
                    }
                    ret += x;
                }
            }
        }
        return ret - (sign & 1 ? (minnum << 1) : 0);
    }
};