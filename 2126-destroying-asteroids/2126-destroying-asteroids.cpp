class Solution {
public:
    bool asteroidsDestroyed(long long mass, vector<int>& asteroids) {
        sort(asteroids.begin(), asteroids.end());
        for(int i = 0, end = asteroids.size(); i < end; ++i) {
            if(mass < asteroids[i]) {
                return false;
            }
            mass += asteroids[i];
        }
        return true;
    }
};