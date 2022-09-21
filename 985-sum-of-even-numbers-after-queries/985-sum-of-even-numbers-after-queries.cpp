class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int>ret;
        int s = accumulate(nums.begin(), nums.end(), 0, [](int x, int y) {return ((y & 1) == 0? x + y: x);});
        ret.reserve(queries.size());
        for(vector<int> &vec: queries) {
            if((nums[vec[1]] & 1) == 0) {
                s -= nums[vec[1]];
            }
            nums[vec[1]] += vec[0];
            if((nums[vec[1]] & 1) == 0) {
                s += nums[vec[1]];
            }
            ret.push_back(s);
        }
        return (ret);
    }
};