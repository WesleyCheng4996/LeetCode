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
        map<int, vector<int>>mp;
        vector<int>ret;
        ret.reserve(nums.size());
        for(int num : nums) {
            mp[Map(num, mapping)].push_back(num);
        }
        for(auto& [_, vec] : mp) {
            for(int x : vec) {
                ret.push_back(x);
            }
        }
        return ret;
    }
};

static auto s = ios_base::sync_with_stdio(false);
static auto ss = cin.tie(nullptr);
static auto sss = cout.tie(nullptr);