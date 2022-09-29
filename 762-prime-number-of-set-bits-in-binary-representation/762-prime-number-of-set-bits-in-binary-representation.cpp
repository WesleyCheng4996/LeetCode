template<int N>
struct Array {
    int count[N];
    Array() :
    count() {
        int arr[30] = { 0 };
        arr[2] = 1;
        arr[3] = 1;
        arr[5] = 1;
        arr[7] = 1;
        arr[11] = 1;
        arr[13] = 1;
        arr[17] = 1;
        arr[19] = 1;
        arr[23] = 1;
        arr[29] = 1;
        for(int i = 1; i < N; ++i) {
            count[i] = count[i - 1] + arr[__builtin_popcount(i)];
        }
    }
};
Array<1000001> a;
class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        return a.count[right] - a.count[left - 1];
    }
};