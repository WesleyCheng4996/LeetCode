class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue <int, vector<int>, greater<int> > pq;
        for (int i = 1; i < heights.size(); ++i) {
            if (heights[i] > heights[i - 1]) {
                int diff = heights[i] - heights[i - 1];
                if (ladders) {
                    --ladders;
                    pq.push(diff);
                }
                else {
                    if (!pq.empty() && pq.top() < diff) {
                        bricks -= pq.top();
                        pq.pop();
                        pq.push(diff);
                    }
                    else {
                        bricks -= diff;
                    }
                    if (bricks < 0) {
                        return i - 1;
                    }
                }
            }
        }
        return heights.size() - 1;
    }
};