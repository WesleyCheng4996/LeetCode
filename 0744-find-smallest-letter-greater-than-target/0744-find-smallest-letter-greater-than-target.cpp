class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        return (upper_bound(letters.begin(), letters.end(), target) == letters.end() ? letters.front() : *upper_bound(letters.begin(), letters.end(), target));
    }
};