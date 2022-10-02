class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int>result(arr.size() + 1);
        result.back() = accumulate(arr.begin(), arr.end(), 0, [](int sum, int x) { return sum ^ x; });
        for(int i = arr.size() - 1; i >= 0; --i) {
            result[i] = result[i + 1] ^ arr[i];
        }
        vector<int>ret;
        ret.reserve(queries.size());
        for(vector<int> &vec : queries) {
            ret.push_back(result[vec[0]] ^ result[vec[1] + 1]);
        }
        return ret;
    }
};