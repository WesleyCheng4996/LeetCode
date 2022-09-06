
class Solution {
public:
    int longestBeautifulSubstring(string word) {
        void* labels[26];
        labels['a' - 'a'] = &&_label_A;
        labels['e' - 'a'] = &&_label_E;
        labels['i' - 'a'] = &&_label_I;
        labels['o' - 'a'] = &&_label_O;
        labels['u' - 'a'] = &&_label_U;
        int curr_len = 0, max_len = 0;
        char check = 0;
        
        auto func = [&]() {
            if(curr_len > max_len && check == 0b11111) {
                    max_len = curr_len;
                }
            curr_len = 0;
            check = 0b00000;
        };
        
        for(int i = 0, end = word.size(); i < end; ++i) {
            goto *labels[word[i] - 'a'];
        _label_A:
            if((check & 0b01111) == 0) {
                check = 0b10000;
                ++curr_len;
            } else {
                func();
                ++curr_len;
                check = 0b10000;
            } continue;
        _label_E:
            if((check & 0b10111) == 0b10000) {
                check = 0b11000;
                ++curr_len;
            } else {
                func();
            } continue;
        _label_I:
            if((check & 0b11011) == 0b11000) {
                check = 0b11100;
                ++curr_len;
            } else {
                func();
            } continue;
        _label_O:
            if((check & 0b11101) == 0b11100) {
                check = 0b11110;
                ++curr_len;
            } else {
                func();
            } continue;
        _label_U: 
            if((check & 0b11110) == 0b11110) {
                check = 0b11111;
                ++curr_len;
            } else {
                func();
            } continue;
        }
        if(curr_len > max_len && check == 0b11111) {
            max_len = curr_len;
        }
        return max_len;
    }
};