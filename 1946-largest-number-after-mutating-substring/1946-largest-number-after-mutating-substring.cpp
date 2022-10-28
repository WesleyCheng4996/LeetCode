class Solution {
public:
    string maximumNumber(string num, vector<int>& change) {
        for(int i = 0; i < num.size(); ++i) {
            if(change[num[i] - '0'] > num[i] - '0') {
                do {
                    num[i] = change[num[i] - '0'] + '0';
                    ++i;
                } while(i < num.size() && change[num[i] - '0'] >= num[i] - '0');
                break;
            }
        }
        return num;
    }
};