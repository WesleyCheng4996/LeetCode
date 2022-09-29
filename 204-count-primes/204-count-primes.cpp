
struct Prime {
    Prime() :
    arr() {
        unsigned int isPrime[78126] = { 0 }, idx = 1;
        for (int i = 0; i < 78126; ++i) {
            --isPrime[i];
        }
        for (int i = 3; i < 2237; i += 2) {
            if ((isPrime[i >> 6]) & (1 << ((i % 64) >> 1))) {
                for (int j = i + i + i; j < 5000000; j += i + i) {
                    isPrime[j >> 6] &= ~(1 << ((j % 64) >> 1));
                }
            }
        }
        arr[0] = 2;
        for (int i = 3; i < 5000000; i += 2) {
            if (isPrime[i >> 6] & (1 << ((i % 64) >> 1))) {
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