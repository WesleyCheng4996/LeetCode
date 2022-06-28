class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int time) {
        int e = 0, count = 0;
        while (e < time) {
            int pre_e = e, max = 0;
            for (auto& x : clips) {
                if (x.front() <= e && x.back() > max) {
                    max = x.back();
                }
            }
            if (max == e) {
                return -1;
            }
            e = max;
            ++count;
        }
        return count;
    }
};