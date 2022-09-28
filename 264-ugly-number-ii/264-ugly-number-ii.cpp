struct ugly {
    constexpr ugly() :
        arr() {
        arr[0] = 1;
        int i = 0, j = 0, k = 0, idx = 1;
        while (idx < 1691) {
            int num1 = arr[i] << 1, num2 = arr[j] * 3, num3 = arr[k] * 5;
            arr[idx] = min(num1, min(num2, num3));
            if (arr[idx] == num1) ++i;
            if (arr[idx] == num2) ++j;
            if (arr[idx] == num3) ++k;
            ++idx;
        }
    }
    int arr[1691];
};

constexpr ugly u;

class Solution {
public:
    int nthUglyNumber(int n) {
        return u.arr[n - 1];
    }
};