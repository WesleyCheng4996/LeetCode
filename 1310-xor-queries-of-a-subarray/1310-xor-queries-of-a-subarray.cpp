class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int *result = new int[arr.size() + 1]();
        for(int i = 0, end = arr.size(), k = 0; i < end; ++i) {
            result[i + 1] = k ^= arr[i];
        }
        vector<int>ret;
        ret.reserve(queries.size());
        for(vector<int> &vec : queries) {
            ret.push_back(result[vec[0]] ^ result[vec[1] + 1]);
        }
        return ret;
    }
};