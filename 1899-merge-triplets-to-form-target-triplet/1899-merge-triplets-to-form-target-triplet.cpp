class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        int target_0 = -1, target_1 = -1, target_2 = -1;
        for(vector<int> &vec: triplets) {
            if(vec[0] == target[0] && vec[1] <= target[1] && vec[2] <= target[2]) {
                target_0 = target[0], target_1 = max(target_1, vec[1]), target_2 = max(target_2, vec[2]);
            }  if(vec[0] <= target[0] && vec[1] == target[1] && vec[2] <= target[2]) {
                target_0 = max(target_0, vec[0]), target_1 = target[1], target_2 = max(target_2, vec[2]);
            }  if(vec[0] <= target[0] && vec[1] <= target[1] && vec[2] == target[2]) {
                target_0 = max(target_0, vec[0]), target_1 = max(target_1, vec[1]), target_2 = target[2];
            }
        }
        return target_0 == target[0] && target_1 == target[1] && target_2 == target[2];
    }
};