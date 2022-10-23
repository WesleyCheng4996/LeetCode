class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());
        int idx1 = 0, idx2 = 0, ret = 0;
        while(idx1 < players.size() && idx2 < trainers.size()) {
            if(players[idx1] <= trainers[idx2]) {
                ++ret;
                ++idx1;
                ++idx2;
            } else {
                ++idx2;
            }
        }
        return ret;
    }
};