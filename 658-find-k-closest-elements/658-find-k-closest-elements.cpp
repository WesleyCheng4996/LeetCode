class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int>::iterator b = arr.begin(), e = arr.end();
        vector<int>::iterator first_it = b;
        for(vector<int>::iterator it(b); it < e; ++it) {
            if(abs(*it - x) < abs(*first_it - x)) {
                first_it = it;
            }
        }
        vector<int>::iterator last_it = first_it + 1;
        while(last_it - first_it < k) {
            if(first_it == b) {
                last_it += k - (last_it - first_it);
                break;
            } 
            if(last_it == e) {
                first_it -= k - (last_it - first_it);
                break;
            }
            int m = abs(*(first_it - 1) - x);
            int n = abs(*(last_it) - x);
            if(m <= n) {
                --first_it;
            } else if(m > n) {
                ++last_it;
            } 
        }
        return vector<int>(first_it, last_it);
    }
};