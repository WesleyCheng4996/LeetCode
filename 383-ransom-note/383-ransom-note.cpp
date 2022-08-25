class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int count[26] = {0};
        for(char ch: magazine){
            ++count[ch - 'a'];
        }
        for(char ch:ransomNote){
            --count[ch - 'a'];
            if(count[ch - 'a'] == -1){
                return false;
            }
        }
        return true;
    }
};