
struct Prime {
    Prime() :
    arr() {
        unsigned int isPrime[78125] = { 0 }, idx = 1;
        for (int i = 0; i < 78125; ++i) {
            --isPrime[i];
        }
        for (int i = 3; i < 2222; i += 2) {
            if ((isPrime[i >> 6]) & (1 << ((i & 63) >> 1))) {
                for (int j = i + i + i; j < 5000000; j += i + i) {
                    isPrime[j >> 6] &= ~(1 << ((j & 63) >> 1));
                }
            }
        }
        arr[0] = 2;
        for (int i = 3; i < 5000000; i += 2) {
            if (isPrime[i >> 6] & (1 << ((i & 63) >> 1))) {
                arr[idx++] = i;
            }
        }
    }
    unsigned int arr[348513];
};

Prime prime;

class Solution {
public:
    int countPrimes(int n) {
        return lower_bound(prime.arr, prime.arr + 348513, n) - prime.arr;
    }
};