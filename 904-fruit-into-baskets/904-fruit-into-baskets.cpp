class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int a = 0, b = 0, a_last_idx = -1, b_last_idx = -1, count = 0, ret = 0;
        for(int i = 0, end = fruits.size(); i < end; ++i) {
            if(a_last_idx == -1) {
                a = fruits[i];
                a_last_idx = i; 
                ++count;
            } else if(fruits[i] == a) {
                ++count;
                a_last_idx = i;
            } else if(b_last_idx == -1) {
                b = fruits[i];
                b_last_idx = i;
                ++count;
            } else if(fruits[i] == b) {
                ++count;
                b_last_idx = i;
            } else {
                if(ret < count) {
                    ret = count;
                }
                i = min(a_last_idx, b_last_idx);
                a_last_idx = -1;
                b_last_idx = -1;
                count = 0;
            }
        }
        if(ret < count) {
            ret = count;
        }
        return ret;
    }
};

static bool     _foo = ios::sync_with_stdio(false);
static ostream* _bar = cin.tie(NULL);