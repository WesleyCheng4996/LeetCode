class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        sort(properties.begin(), properties.end(), [](vector<int> &x, vector<int> &y){
            return (x[0] < y[0]) ||  ((x[0] == y[0]) && (x[1] > y[1]));
        });
        int mtn = 0;
        int ans = 0;

        for (int i = properties.size() - 1; i >= 0; i--) {
            if (properties[i][1] < mtn) {
                ans++;
            }
            mtn = max(mtn, properties[i][1]);
        }
        return ans;   
        
    }
};