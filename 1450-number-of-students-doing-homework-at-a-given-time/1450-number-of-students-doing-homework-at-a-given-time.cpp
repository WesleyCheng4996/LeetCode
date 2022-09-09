class Solution {
public:
    int busyStudent(vector<int>& startTime, vector<int>& endTime, int queryTime) {
        int ret = 0;
        for(int i = 0, end = startTime.size(); i < end; ++i) {
            ret += (startTime[i] <= queryTime && queryTime <= endTime[i]);
        }
        return ret;
    }
};