class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int>ret;
        int s = 0;
        for(int i = 0, end = queries.size(); i < end; ++i) {
            if((nums[i] & 1) == 0) {
                s += nums[i];
            }
        }
        ret.reserve(queries.size());
        for(vector<int> &vec: queries) {
            int &x = nums[vec[1]];
            if((x & 1) == 0) {
                s -= nums[vec[1]];
            }
            x += vec[0];
            if((x & 1) == 0) {
                s += x;
            }
            ret.push_back(s);
        }
        return (ret);
    }
};