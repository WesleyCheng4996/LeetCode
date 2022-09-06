
class Solution {
public:
    int longestBeautifulSubstring(string word) {
        int curr_len = 0, max_len = 0;
        char check = 0;
        for(int i = 0, end = word.size(); i < end; ++i) {
            switch(word[i]) {
                case 'a':
                    if((check & 0b01111) == 0) {
                        check |= 0b10000;
                        ++curr_len;
                    } else {
                        if(curr_len > max_len && check == 0b11111) {
                            max_len = curr_len;
                        }
                        curr_len = 1;
                        check = 0b10000;
                    }
                    break;
                case 'e':
                    if((check & 0b10111) == 0b10000) {
                        check |= 0b01000;
                        ++curr_len;
                    } else {
                        if(curr_len > max_len && check == 0b11111) {
                            max_len = curr_len;
                        }
                        curr_len = 0;
                        check = 0;
                    }
                    break;
                case 'i':
                    if((check & 0b11011) == 0b11000) {
                        check |= 0b00100;
                        ++curr_len;
                    } else {
                        if(curr_len > max_len && check == 0b11111) {
                            max_len = curr_len;
                        }
                        curr_len = 0;
                        check = 0;
                    }
                    break;
                case 'o':
                    if((check & 0b11101) == 0b11100) {
                        check |= 0b00010;
                        ++curr_len;
                    } else {
                        if(curr_len > max_len && check == 0b11111) {
                            max_len = curr_len;
                        }
                        curr_len = 0;
                        check = 0;
                    }
                    break;
                case 'u':
                    if((check & 0b11110) == 0b11110) {
                        check |= 0b00001;
                        ++curr_len;
                    } else {
                        if(curr_len > max_len && check == 0b11111) {
                            max_len = curr_len;
                        }
                        curr_len = 0;
                        check = 0;
                    }
                    break;
                default:
                    ++curr_len;
            }
        }
        if(curr_len > max_len && check == 0b11111) {
            max_len = curr_len;
        }
        return max_len;
    }
};