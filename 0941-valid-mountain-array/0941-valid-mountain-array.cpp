class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        auto max_it = max_element(arr.begin(), arr.end());
        return max_it != arr.begin() & max_it != arr.end() - 1 & all_of(arr.begin(), max_it, [](int& i) { return i < *(&i + 1); }) & all_of(max_it, arr.end() - 1, [](int& i) { return i > *(&i + 1); });
    }
};