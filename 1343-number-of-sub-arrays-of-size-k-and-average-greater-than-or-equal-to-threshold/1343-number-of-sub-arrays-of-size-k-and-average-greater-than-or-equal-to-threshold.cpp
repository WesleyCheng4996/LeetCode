class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int sum = accumulate(arr.begin(), arr.begin() + k, 0), ret = 0;
        threshold *= k;
        for(int i = 0; k < arr.size(); ++i, ++k) {
            ret += (sum >= threshold);
            sum += arr[k] - arr[i];
        }
        return ret += (sum >= threshold);
    }
};