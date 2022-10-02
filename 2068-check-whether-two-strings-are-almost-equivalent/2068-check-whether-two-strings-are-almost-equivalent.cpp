class Solution {
public:
    bool checkAlmostEquivalent(string word1, string word2) {
        int count[26] = { 0 };
        for(char ch : word1) {
            ++count[ch - 'a'];
        } 
        for(char ch : word2) {
            --count[ch - 'a'];
        }
        for(int x : count) {
            if(abs(x) > 3) {
                return false;
            }
        }
        return true;
    }
};