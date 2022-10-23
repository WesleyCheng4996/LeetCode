class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int>ret(n, 0);
        stack<int>stk;
        stack<int>diff;
        diff.push(0);

        for(string& log: logs) {
            int idx1 = log.find(':'), idx2 = log.find_last_of(':');
            int timestamp = stoi(log.substr(idx2 + 1));
            if(log[idx1 + 1] == 's') {
                stk.push(timestamp);
                diff.push(0);
            } else {
                ret[stoi(log.substr(0, idx1))] += ++timestamp - stk.top() - diff.top();
                diff.pop();
                diff.top() += timestamp - stk.top();
                stk.pop();
            }
        }
        return ret;
    }
};