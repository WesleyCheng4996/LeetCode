struct isSqure {
    constexpr isSqure() :
    a() {
        bool arr[10001] = { 0 };
        for(int i = 2; i < 101; ++i) {
            if(arr[i] == false) {
                for(int num = i + i; num < 10001; num += i) {
                    arr[num] = true;
                }
                a[i * i] = true;
            }
        }
    }
    bool a[10001];
};
constexpr isSqure s;

class Solution {
public:
    bool isThree(int n) {
        return s.a[n];
    }
};