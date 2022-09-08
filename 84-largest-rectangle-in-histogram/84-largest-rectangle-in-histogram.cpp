class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int size = heights.size(), ans = 0;
        vector<int>::iterator b = heights.begin(), e = heights.end();
        vector<pair<vector<int>::iterator, vector<int>::iterator>>firstit_lastit(size);
        firstit_lastit[0].first = b;
        firstit_lastit[size - 1].second = e;
        stack<pair<int, int>>idx_val;
        idx_val.push({ 0, heights[0] });
        for (int i = 1; i < size; ++i) {
            while (!idx_val.empty() && idx_val.top().second > heights[i]) {
                firstit_lastit[idx_val.top().first].second = b + i;
                idx_val.pop();
            }
            idx_val.push({ i, heights[i] });
        }
        while (!idx_val.empty()) {
            firstit_lastit[idx_val.top().first].second = e;
            idx_val.pop();
        }

        idx_val.push({ size - 1, heights[size - 1] });
        for (int i = size - 2; i >= 0; --i) {
            while (!idx_val.empty() && idx_val.top().second > heights[i]) {
                firstit_lastit[idx_val.top().first].first = b + i + 1;
                idx_val.pop();
            }
            idx_val.push({ i, heights[i] });
        }
        while (!idx_val.empty()) {
            firstit_lastit[idx_val.top().first].first = b;
            idx_val.pop();
        }
        for (int i = 0; i < size; ++i) {
            if (ans < (firstit_lastit[i].second - firstit_lastit[i].first) * heights[i]) {
                ans = (firstit_lastit[i].second - firstit_lastit[i].first) * heights[i];
            }
        }


        return ans;
    }
};