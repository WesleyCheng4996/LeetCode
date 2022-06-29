class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), [](vector<int>& pre, vector<int>& post){
            return pre[1] < post[1] || (pre[1] == post[1] && pre[0] < post[0]);
        });
        vector<vector<int>>ans;
        ans.reserve(people.size());
        ans.push_back(people[0]);
        for(int i = 1; i < people.size(); ++i){
            int counter = people[i][1], k = 0;
            for(int j = 0; j < ans.size(); ++j, ++k){
                if(ans[j][0] >= people[i][0]){
                    --counter;
                    if(counter == -1){
                        break;
                    }
                }
            }
            ans.insert(ans.begin() + k, people[i]);
        }
        return ans;
    }
};