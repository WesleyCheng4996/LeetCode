class Solution {
public:
    vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices) {
        if((tomatoSlices & 1) || tomatoSlices < (cheeseSlices << 1) || tomatoSlices > (cheeseSlices << 2)) {
            return vector<int>();
        }
        int jburger = (tomatoSlices - (cheeseSlices << 1)) >> 1;
        return vector<int> { jburger, cheeseSlices - jburger };
    }
};