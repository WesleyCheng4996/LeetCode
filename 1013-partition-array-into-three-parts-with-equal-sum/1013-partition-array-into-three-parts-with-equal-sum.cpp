class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A, int parts = 0) {
        int total = accumulate(begin(A), end(A), 0);
        if (total % 3 != 0) return false;
        for (int i = 0, sum = 0, idx_end = A.size(), part_end = total != 0 ? 2 : 3; i < idx_end && parts < part_end; ++i) {
          sum += A[i];
          if (sum == total / 3) ++parts, sum = 0;
        }
        return parts == (total != 0 ? 2 : 3);
    }
};