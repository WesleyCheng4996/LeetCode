class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(-1);
        int ans = 0, sz = heights.size(), area = 0, h = 0, x = 0;
        int* ptr = new int[sz + 1](), * b = ptr;
        for (int i = 0; i < sz; ++i) {
            while (ptr > b && heights [*ptr]  > heights[i]) {
                h = heights[*ptr];
                --ptr;
                x = ptr > b ? (*ptr) + 1: 0;
                area = (i - x) * h;
                if (ans < area) {
                    ans = area;
                }
            }
            *(++ptr) = i;
        }
        return ans;
    }
};

static bool     _foo = ios::sync_with_stdio(false);
static ostream* _bar = cin.tie(NULL);