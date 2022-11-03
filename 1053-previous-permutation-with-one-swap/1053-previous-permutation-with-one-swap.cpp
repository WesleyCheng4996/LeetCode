class Solution {
public:
    vector<int>::iterator findMaxLessThanX(vector<int>::iterator begin, vector<int>::iterator end, int x) {
        vector<int>::iterator ret = begin;
        while(begin < end) {
            if(*begin < x && *begin > *ret) {
                ret = begin;
            }
            ++begin;
        }
        return ret;
    }
    vector<int> prevPermOpt1(vector<int>& arr) {
        int idx = -1;
        for(int i = arr.size() - 1; i > 0; --i) {
            if(arr[i] < arr[i - 1]) {
                idx = i - 1;
                break;
            }
        }
        if(idx != -1) {
            swap(arr[idx], *findMaxLessThanX(arr.begin() + idx + 1, arr.end(), arr[idx]));
        }
        return arr;
    }
};

static auto s = ios_base::sync_with_stdio(false);
static auto ss = cin.tie(nullptr);
static auto sss = cout.tie(nullptr);