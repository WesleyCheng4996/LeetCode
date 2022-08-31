class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans = "";
        string::iterator word1_ite = word1.begin(), word1_end = word1.end(), word2_ite = word2.begin(), word2_end = word2.end();
        void* labels[] = { &&BOTH, &&WORD2, &&WORD1, &&DONE};
        for(;;) {
            goto *labels[((word1_ite == word1_end) << 0) | ((word2_ite == word2_end) << 1)];
    BOTH:
        ans.push_back(*word1_ite++);
        ans.push_back(*word2_ite++);
        continue;
    WORD1:
        ans.push_back(*word1_ite++);
        continue;
    WORD2:
        ans.push_back(*word2_ite++);
        continue;
        }
    DONE:
        return ans;
    }
    
};