class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int>ret;
        int* count = new int[nums.size() + 1]();
        for(int x : nums) {
            ++count[x];
        }
        for(int i = 1; i < nums.size() + 1; ++i) {
            if(count[i] == 0) {
                ret.push_back(i);
            } else if(count[i] == 2) {
                ret.insert(ret.begin(), i);
            }
        }
        return ret;
    }
};