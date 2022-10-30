class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_map<char, int>count, countt;
        int A = 0, B = 0;
        for(int i = 0; i < secret.size(); ++i) {
            if(secret[i] == guess[i]) {
                ++A;
            } else {
                ++count[secret[i]];
                ++countt[guess[i]];
            }
        }
        for(char c = '0'; c <= '9'; ++c) {
            B += min(count[c], countt[c]);
        }
        return to_string(A) + "A" + to_string(B) + "B";
    }
};