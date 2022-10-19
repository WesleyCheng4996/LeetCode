class Solution {
public:
    string removeOccurrences(string s, string part) {
        int len = 0;
        do {
            len = s.size();
            int idx = s.find(part);
            if(idx != string::npos) {
                s.erase(idx, part.size());
            }
        } while(len != s.size());
        return s;
    }   
};