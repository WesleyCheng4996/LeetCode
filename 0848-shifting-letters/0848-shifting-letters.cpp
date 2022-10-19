struct Table {
    int mat[50][26];
    constexpr Table() :
    mat() {
        for(int i = 0; i < 50; ++i) {
            for(int j = 0; j < 26; ++j) {
                mat[i][j] = 'a' + i + j;
                if(mat[i][j] > 'z') {
                    mat[i][j] -= 26;
                }
            }
        }
    }
};
constexpr Table t;

class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        for(int i = shifts.size() - 2; i >= 0; --i) {
            shifts[i] += shifts[i + 1] % 26;
        }
        for(int i = 0; i < s.size(); ++i) {
            s[i] = t.mat[shifts[i] % 26][s[i] - 'a'];
        }
        return s;
    }
};