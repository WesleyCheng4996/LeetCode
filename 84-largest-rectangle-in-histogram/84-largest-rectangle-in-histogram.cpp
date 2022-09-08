class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int size = heights.size(), ans = 0;
        vector<int>::iterator b = heights.begin(), e = heights.end();
        vector<vector<int>::iterator>lastit(size);
        lastit[size - 1] = e;
        stack<pair<int, int>>idx_val;
        idx_val.push({ 0, heights[0] });
        for (int i = 1; i < size; ++i) {
            while (!idx_val.empty() && idx_val.top().second > heights[i]) {
                lastit[idx_val.top().first] = b + i;
                idx_val.pop();
            }
            idx_val.push({ i, heights[i] });
        }
        while (!idx_val.empty()) {
            lastit[idx_val.top().first] = e;
            idx_val.pop();
        }

        idx_val.push({ size - 1, heights[size - 1] });
        for (int i = size - 2; i >= 0; --i) {
            while (!idx_val.empty() && idx_val.top().second > heights[i]) {
                int area = (lastit[idx_val.top().first] - (b + i + 1)) * heights[idx_val.top().first];
                if (ans < area) {
                    ans = area;
                }
                idx_val.pop();
            }
            idx_val.push({ i, heights[i] });
        }
        while (!idx_val.empty()) {
            int area = (lastit[idx_val.top().first] - b) * heights[idx_val.top().first];
            if (ans < area) {
                ans = area;
            }
            idx_val.pop();
        }
        return ans;
    }
};