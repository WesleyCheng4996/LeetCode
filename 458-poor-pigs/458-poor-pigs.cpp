class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        return std::ceil(std::log(buckets) / std::log((minutesToTest / minutesToDie) + 1));
    }
};