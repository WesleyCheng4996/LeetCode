template<int N>
struct Table{
  constexpr Table():
    arr() {
        for(int i = 0; i < N; ++i) {
            for(int j = 0; j < N; ++j) {
                arr[i][j] = j;
            }
        }
        for(int i = 2; i < N; ++i) {
            for(int j = 2; j < N; ++j) {
                if(i % j == 0) {
                    for(int k = j; k < N; k += j) {
                        arr[i][k] = 0;
                    }
                }
            }
        }
    }
    int arr[N][N];
};

constexpr Table<101> table;

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