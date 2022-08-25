class Solution {
public:
    void Multiply(int arr[4], int brr[4]) {
        int ans[4] = { arr[0] * brr[0] + arr[1] * brr[2],
                        arr[0] * brr[1] + arr[1] * brr[3],
                        arr[2] * brr[0] + arr[3] * brr[2],
                        arr[2] * brr[1] + arr[3] * brr[3]
        };
        arr[0] = ans[0];
        arr[1] = ans[1];
        arr[2] = ans[2];
        arr[3] = ans[3];

    }

    int fib(int n) {

        if (n < 2) {
            return n;
        }

        int arr[4] = { 1, 1, 1, 0 };
        int base[4] = { 1, 1, 1, 0 };
        n -= 2;
        for (;;) {
            if (n & 1) {
                Multiply(arr, base);
            }
            n >>= 1;
            Multiply(base, base);
            if (n <= 0) {
                break;
            }
        }

        return arr[0];
    }

};