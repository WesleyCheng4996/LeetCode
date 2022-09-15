class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        int count[100001] = { 0 };
        vector<int> ret;
        int size = changed.size();
    
        ret.reserve(size);
        for (int x : changed) {
            ++count[x];
        }
        
        if((count[0] & 1) == 1) {
            return ret;
        } else {
            ret.insert(ret.end(), count[0] >> 1, 0);

        }
        
        for(int i = 0; i < 50001; ++i) {
            if(count[i] == 0) {
                continue;
            }
            if(count[i] > count[i << 1]) {
                return vector<int>();
            } else {
                count[i << 1] -= count[i];
                ret.insert(ret.end(), count[i], i);
            }
        }
        return ret;
    }
};

