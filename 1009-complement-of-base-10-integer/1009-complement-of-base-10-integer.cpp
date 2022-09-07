template<int N>
struct bit_num {
    constexpr bit_num() :
        arr() 
    {
        for(int i = 0; i < N; ++i) {
            arr[i] = 1 << i;
        }
    }
    
    int arr[N];
};

constexpr bit_num<32> b;

class Solution {
public:
    int bitwiseComplement(int n) {
        int x = ~n;
        for(int i = 31; i >= 0; --i) {
            if(x & b.arr[i]) {
                x &= ~(b.arr[i]);
            }
            else {
                return x;
            }
        }
        return 1;
    }
};