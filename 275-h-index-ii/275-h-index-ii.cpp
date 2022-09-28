class Solution {
public:
    int hIndex(vector<int> citations) {
        int n = citations.size();
        int min = 0, max = citations.size() - 1, ret = 0;
        int mid;
        while (min <= max) {
            mid = (min + max) >> 1;
            if (citations[mid] >= n - mid) {
                ret = n - mid;
                max = mid - 1;
            }
            else {
                min = mid + 1;
            }
        }
        return ret;
    }
};