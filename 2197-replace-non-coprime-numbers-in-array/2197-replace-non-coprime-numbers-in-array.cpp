class Solution {
public:
    int GCD(int a, int b) {
        return b == 0 ? a : GCD(b, a % b);
    }
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        int* stk = new int[nums.size()], * ptr = stk;
        *ptr++ = nums.front();
        for(int i = 1; i < nums.size(); ++i) {
            int gcd;
            while(stk != ptr && (gcd = GCD(*(ptr - 1), nums[i])) != 1) {
                nums[i] *= *(--ptr) / gcd;
            }
            *ptr++ = nums[i];
        }
        return vector<int>(stk, ptr);
    }
};

static auto s = ios_base::sync_with_stdio(false);
static auto ss = cin.tie(nullptr);
static auto sss = cout.tie(nullptr);