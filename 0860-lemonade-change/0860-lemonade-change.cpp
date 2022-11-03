class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        vector<int>dollar(2, 0);
        for(int x : bills) {
            if(x == 5) {
                ++dollar[0];
            } else if(x == 10) {
                if(dollar[0] == 0) {
                    return false;
                } else {
                    --dollar[0];
                    ++dollar[1];
                }
            } else {
                if(dollar[1] == 0) {
                    if(dollar[0] < 3) {
                        return false;
                    } else {
                        dollar[0] -= 3;
                    }
                } else {
                    if(dollar[0] == 0) {
                        return false;
                    } else {
                        --dollar[0];
                        --dollar[1];
                    }
                }
            }
        }
        return true;
    }
};

static auto s = ios_base::sync_with_stdio(false);
static auto ss = cin.tie(nullptr);
static auto sss = cout.tie(nullptr);