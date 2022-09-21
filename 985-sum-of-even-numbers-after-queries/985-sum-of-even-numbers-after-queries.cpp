class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int>ret;
        int s = accumulate(nums.begin(), nums.end(), 0, [](int x, int y) {return ((y & 1) == 0? x + y: x);});
        ret.reserve(queries.size());
        for(vector<int> &vec: queries) {
            int &x = nums[vec[1]];
            if((x & 1) == 0) {
                s -= x;
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