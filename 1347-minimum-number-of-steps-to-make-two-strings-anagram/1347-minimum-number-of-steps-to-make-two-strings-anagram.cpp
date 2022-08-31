class Solution {
public:
    int minSteps(string s, string t) {
        int words[26] = { 0 };
        int sum = 0;
        for(int i = 0, end = s.size(); i < end; ++i) { 
            ++words[s[i] - 'a'];
            --words[t[i] - 'a'];
        }
        for(int i = 0; i < 26; ++i) {
            sum += (words[i] ^ (words[i] >> 31)) - (words[i] >> 31);

        }
        return (sum >> 1);
    }
};