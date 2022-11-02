class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        sort(intervals.begin(), intervals.end());
        vector<vector<int>>ret;
        stack<int>stk;
        int begin = intervals[0][0];
        stk.push(intervals[0][1]);
        for(int i = 1; i < intervals.size(); ++i) {
            int end;
            if(!stk.empty() && intervals[i][0] > stk.top()) {
                end = stk.top();
            }
            while(!stk.empty() && intervals[i][0] > stk.top()) {
                end = max(end, stk.top());
                stk.pop();
            }
            if(stk.empty()) {
                ret.push_back(vector<int>{begin, end});
                begin = intervals[i][0];
            }
            stk.push(intervals[i][1]);
        }
        if(!stk.empty()) {
            int end = stk.top();
             while(!stk.empty()) {
                end = max(end, stk.top());
                stk.pop();
            }
            ret.push_back(vector<int>{begin, end});
        }
        return ret;
    }
};