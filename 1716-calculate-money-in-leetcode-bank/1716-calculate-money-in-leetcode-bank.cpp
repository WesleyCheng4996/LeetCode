class Solution {
public:
    int totalMoney(int n) {
        int week = n / 7;
        int day = n % 7;
        return week * 28 + ((week - 1) * week / 2) * 7 + ((day + 1) * day) / 2 + day * week;
    }
};