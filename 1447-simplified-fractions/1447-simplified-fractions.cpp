struct Table{
  constexpr Table():
    arr() {
        for(int i = 0; i < 101; ++i) {
            for(int j = 0; j < 101; ++j) {
                arr[i][j] = j;
            }
        }
        for(int i = 2; i < 101; ++i) {
            for(int j = 2; j < 101; ++j) {
                if(i % j == 0) {
                    for(int k = j; k < 101; k += j) {
                        arr[i][k] = 0;
                    }
                }
            }
        }
    }
    int arr[101][101];
};

constexpr Table table;

class Solution {
public:
    vector<string> simplifiedFractions(int n) {
        vector<string>ret;
        for(int i = 1; i <= n ; ++i) {
            for(int j = i + 1; j <= n; ++j) {
                if(table.arr[i][j] != 0)
                    ret.push_back(to_string(i) + "/" + to_string(j));
            }
        }
        return ret;
    }
};