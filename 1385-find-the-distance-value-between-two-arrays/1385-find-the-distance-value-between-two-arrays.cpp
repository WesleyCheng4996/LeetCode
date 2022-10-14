class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int ret = 0;
        sort(arr2.begin(), arr2.end());
        for(int x : arr1) {
            vector<int>::iterator it = lower_bound(arr2.begin(), arr2.end(), x);
            if(it != arr2.end() && abs(x - *it) <= d) {
                ++ret;
            } else if(it != arr2.begin() && abs(x - *(it - 1)) <= d){
                ++ret;
            }
        }
        return arr1.size() - ret;
    }
};