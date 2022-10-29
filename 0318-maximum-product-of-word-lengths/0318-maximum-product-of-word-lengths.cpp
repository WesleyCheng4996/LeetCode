class Solution {
public:
    int maxProduct(vector<string>& words) {
        int* arr = new int[words.size()](),* ptr = arr, ret = 0;
        for(string& s : words) {
            for(char c : s) {
                *ptr |= 1 << (c - 'a');
            }
            ++ptr;
        }
        for(int i = 0; i < words.size(); ++i) {
            for(int j = i + 1; j < words.size(); ++j) {
                if((arr[i] & arr[j]) == 0) {
                    ret = max(ret, (int)(words[i].size() * words[j].size()));
                }
            }
        }
        return ret;
    }
};

static auto s = ios_base::sync_with_stdio(false);
static auto ss = cin.tie(nullptr);
static auto sss = cout.tie(nullptr);