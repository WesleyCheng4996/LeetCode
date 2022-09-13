class Solution {
public:
    int convertTime(string current, string correct) {
        int time1 = stoi(current.substr(0, 2)) * 60 + stoi(current.substr(3, 5));
        int time2 = stoi(correct.substr(0, 2)) * 60 + stoi(correct.substr(3, 5));
        int ret = time2 - time1;
        ret = ret / 60 + ret % 60 / 15 + ret % 15 / 5 + ret % 5;
        return ret;
    }
};