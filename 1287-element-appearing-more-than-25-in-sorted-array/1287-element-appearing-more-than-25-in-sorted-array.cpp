class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        vector<int>::iterator b = arr.begin(), e = arr.end();
        int size = (e - b) >> 2;
        for(vector<int>::iterator it = b, up_it; it < e; it = up_it) {
            up_it = upper_bound(it, e, *it);
            if(up_it - it > size) {
                return *it;
            }
        }
        return -1;
    }
};