struct Table{
    int arr[100001];
    constexpr Table() : 
        arr()
    {
        int val = 0;
        for(int i = 0; i < 100001; ++i) {
            arr[i] = val ^= i;
        }
    }
};
constexpr Table t;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        bitset<100001>st;
        for(int x : nums) {
            if(st[x] == 1) {
                return x;
            }
            st[x] = 1;
        }
        return 0;
    }
};