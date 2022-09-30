class Solution {
public:
    int numSteps(string s) {
        int ret = 0;
        while (s.size() > 1) {
            if (s.back()  == '0') {
                s.pop_back();
                ++ret;
            }
            else {
                string::iterator itt = s.end() - 1;
                while (*itt == '1') {
                    --(*itt);
                    if (itt == s.begin()) {
                        s.insert(s.begin(), '0');
                        break;
                    }
                    --itt;
                }
                ++(*itt);
                ++ret;
            }
        }
        return ret;
    }
};