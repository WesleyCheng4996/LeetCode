template<int N>
struct Array {
    bool count[N];
    Array() :
    count() {
        for(int i = 1; i < N; ++i) {
            switch(__builtin_popcount(i)) {
                case 2:
                case 3:
                case 5:
                case 7:
                case 11:
                case 13:
                case 17:
                case 19:
                case 23:
                case 29:
                case 31:
                    count[i] = true;
            }
        }
    }
};
Array<1000001> a;
class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        return accumulate(a.count + left, a.count + right + 1, 0);
    }
};