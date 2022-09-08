class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int size = heights.size(), ans = 0;
        vector<int>::iterator b = heights.begin(), e = heights.end();
        vector<int>last(size);
        last[size - 1] = size;
        stack<pair<int, int>>idx_val;
        idx_val.push({ 0, heights[0] });
        for (int i = 1; i < size; ++i) {
            while (!idx_val.empty() && idx_val.top().second > heights[i]) {
                last[idx_val.top().first] = i;
                idx_val.pop();
            }
            idx_val.push({ i, heights[i] });
        }
        while (!idx_val.empty()) {
            last[idx_val.top().first] = size;
            idx_val.pop();
        }

        idx_val.push({ size - 1, heights[size - 1] });
        for (int i = size - 2; i >= 0; --i) {
            while (!idx_val.empty() && idx_val.top().second > heights[i]) {
                int area = (last[idx_val.top().first] - i - 1) * heights[idx_val.top().first];
                if (ans < area) {
                    ans = area;
                }
                idx_val.pop();
            }
            idx_val.push({ i, heights[i] });
        }
        while (!idx_val.empty()) {
            int area = (last[idx_val.top().first]) * heights[idx_val.top().first];
            if (ans < area) {
                ans = area;
            }
            idx_val.pop();
        }
        return ans;
    }
};