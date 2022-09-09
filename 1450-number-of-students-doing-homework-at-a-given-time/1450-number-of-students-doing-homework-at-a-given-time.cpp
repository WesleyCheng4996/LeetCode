class Solution {
public:
    int busyStudent(vector<int>& startTime, vector<int>& endTime, int queryTime) {
        int ret = 0;
        for(vector<int>::iterator startit = startTime.begin(), endit = endTime.begin(), e = startTime.end(); startit < e; ++startit, ++endit) {
            if(*startit <= queryTime && *endit >= queryTime) {
                ++ret;
            }
        }
        return ret;
    }
};