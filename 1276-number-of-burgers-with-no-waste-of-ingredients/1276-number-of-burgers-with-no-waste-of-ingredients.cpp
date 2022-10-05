class Solution {
public:
    vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices) {
        if((tomatoSlices & 1) || tomatoSlices < (cheeseSlices << 1) || tomatoSlices > (cheeseSlices << 2)) {
            return vector<int>();
        }
        int diff = tomatoSlices - (cheeseSlices << 1);
        int jburger = diff >> 1;
        int sburger = cheeseSlices - jburger;
        return vector<int> { jburger, sburger };
    }
};