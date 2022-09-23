class Solution {
public:
    vector<int> circularPermutation(int n, int start) {
        int count = pow(2, n);
        vector<int>ret(1, start);
        bool *record = new bool[count]();
        record[start] = true;
        ret.reserve(count);
        
        while(ret.size() < count) {
            for(int i = 0; i < 32; ++i) {
                if(record[start ^ (1 << i)] == false) {
                    start ^= (1 << i);
                    record[start] = true;
                    ret.push_back(start);
                    break;
                }
            }
        }
        
        return ret;
    }
};