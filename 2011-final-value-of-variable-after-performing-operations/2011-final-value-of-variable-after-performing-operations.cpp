class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int count = 0;
        for(auto& x : operations) {
            count += x[1] == '+' ? 1 : -1;
        }
        return count;
    }
};