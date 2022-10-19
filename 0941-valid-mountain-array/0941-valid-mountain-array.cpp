class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        return max_element(arr.begin(), arr.end()) != arr.begin() && max_element(arr.begin(), arr.end()) != arr.end() - 1 && all_of(arr.begin(), max_element(arr.begin(), arr.end()), [](int& i) { return i < *(&i + 1); }) && all_of(max_element(arr.begin(), arr.end()), arr.end() - 1, [](int& i) { return i > *(&i + 1); });
    }
};