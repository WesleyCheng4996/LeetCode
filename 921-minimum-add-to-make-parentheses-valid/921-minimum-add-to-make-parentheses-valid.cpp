class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char>stk;
        for (auto x : s) {
            if (x == '(') {
                stk.push('(');
            }
            else {
                if (stk.empty() || stk.top() != '(') {
                    stk.push(')');
                }
                else {
                    if (!stk.empty())
                        stk.pop();
                }
            }
        }
        return stk.size();
    }
};