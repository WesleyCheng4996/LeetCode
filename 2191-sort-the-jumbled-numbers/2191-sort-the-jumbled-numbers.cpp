class Solution {
public:
    int Map(int n, vector<int>& mapping) {
        int value=0,t=1;
        if(n==0)
            return mapping[0];
        while(n!=0){
            int temp=n%10;            
            value=mapping[temp]*t+value;
            t=t*10, n=n/10;
        }
        return value;
    }
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<pair<int, int>>vec;
        vector<int>ret;
        vec.reserve(nums.size());
        ret.reserve(nums.size());
        for(int num : nums) {
            vec.push_back({Map(num, mapping), num});
        }
        stable_sort(vec.begin(), vec.end(), [](pair<int, int>p, pair<int, int>pp){return p.first < pp.first;});
        for(auto& [_, val] : vec) {
            ret.push_back(val);
        }
        return ret;
    }
};

static auto s = ios_base::sync_with_stdio(false);
static auto ss = cin.tie(nullptr);
static auto sss = cout.tie(nullptr);