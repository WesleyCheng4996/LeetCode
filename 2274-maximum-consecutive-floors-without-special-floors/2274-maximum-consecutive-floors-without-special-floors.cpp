class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& special) {
        int ret = 0;
        special.push_back(bottom - 1);
        special.push_back(top + 1);
        sort(special.begin(), special.end());
        for(int i = 0, end = special.size() - 1; i < end; ++i) {
            int diff = special[i + 1] - special[i];
            if(ret < diff) {
                ret = diff;
            }
        }
        return ret - 1;
    }
};