class Solution {
public:
    int convertTime(string current, string correct) {
        int hour1 = stoll(current.substr(0, 2)), min1 = stoll(current.substr(3, 5));
        int hour2 = stoll(correct.substr(0, 2)), min2 = stoll(correct.substr(3, 5));
        int ret = 0;
        if(min1 > min2) {
            --hour2;
            min2 += 60;
        }
        ret += min2 - min1;
        ret = ret / 15 + ret % 15 / 5 + ret % 5;
        ret += hour2 - hour1;

        return ret;
    }
};