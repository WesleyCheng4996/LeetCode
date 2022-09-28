class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& special) {
        int ret = 0;
        special.push_back(bottom - 1);
        special.push_back(top + 1);
        sort(special.begin(), special.end());
        for(int i = 0, end = special.size() - 1; i < end; ++i) {
            if(ret < special[i + 1] - special[i]) {
                ret = special[i + 1] - special[i];
            }
        }
        return ret - 1;
    }
};