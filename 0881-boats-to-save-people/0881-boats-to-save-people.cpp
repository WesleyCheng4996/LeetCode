class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int ret = 0;
        int idx1 = 0, idx2 = people.size() - 1;
        while(idx1 <= idx2) {
            if(people[idx1] + people[idx2] <= limit) {
                ++idx1;
            }
            --idx2;
            ++ret;
        }
        return ret;
    }
};

static auto s = ios_base::sync_with_stdio(false);
static auto ss = cin.tie(nullptr);
static auto sss = cout.tie(nullptr);
