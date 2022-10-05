class Solution {
public:
    bool makeEqual(vector<string>& words) {
        int count[128] = { 0 }, sz = words.size();
        for(string& vec : words) {
            for(char x : vec) {
                ++count[x];
            }
        }
        for(int i = 97; i < 123; ++i) {
            if(count[i] % sz) {
                return false;
            }
        }
        return true;
    }
};