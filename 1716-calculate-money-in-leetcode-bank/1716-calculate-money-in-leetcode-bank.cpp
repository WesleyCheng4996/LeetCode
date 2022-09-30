class Solution {
public:
    int totalMoney(int n) {
        int week = n / 7;
        int day = n % 7;
        return (49 + 7 * week) * week / 2 + (2 * week + day + 1) * day / 2;
    }
};