class Solution {
public:
    vector<string> split(string s) {
        vector<string>ret;
        int idx = s.find('[');
        while(idx != string::npos) {
            ret.push_back(s.substr(0, idx));
            s.erase(0, idx + 1);
            idx = s.find(']');
            ret.push_back(s.substr(0, idx));
            s.erase(0, idx + 1);
            idx = s.find('[');
        }
        return ret;
    }
    string decodeString(string s) {
        stack<string>stk;
        stack<int>nums;
        stk.push("");
        nums.push(0);
        for(int i = 0; i < s.size(); ++i) {
            if(isalpha(s[i])) {
                stk.top().push_back(s[i]);
            } else if(isdigit(s[i])) {
                nums.top() *= 10;
                nums.top() += s[i] - '0';
            } else if(s[i] == '[') {
                stk.push("");
                nums.push(0);
            } else {
                string str = stk.top();
                stk.pop();
                nums.pop();
                for(int i = 0; i < nums.top(); ++i) {
                    stk.top() += str;
                }
                nums.top() = 0;
            }
        }
        return stk.top();
    }
};