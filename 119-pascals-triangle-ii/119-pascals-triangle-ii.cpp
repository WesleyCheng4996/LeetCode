class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans(1, 1);
        for(int i = 1; i < rowIndex; ++i){
            ans.push_back((long long)ans.back()*(rowIndex-i+1) /i);
        }
        if(rowIndex >= 1)
            ans.push_back(1);
        return ans;
    }
};