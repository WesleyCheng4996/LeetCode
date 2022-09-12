class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int ret = 0, count = 0, idx1 = 0, idx2 = tokens.size() - 1;
        sort(tokens.begin(), tokens.end());
        while(idx1 <= idx2) {
            if(power >= tokens[idx1]) {
                power -= tokens[idx1++];
                ++count;
            } else {
                if(count == 0) {
                    return ret;
                } else {
                     power += tokens[idx2--];
                    if(ret < count) {
                        ret = count;
                    }
                    --count;
                }
            }
        }
        if(ret < count) {
            ret = count;
        }
        return ret;
    }
};