class Solution {
public:
    string reorganizeString(string s) {
        priority_queue<pair<int, char>> pq;
        vector<int>count(26, 0);
        string ret = "";
        for (char c : s) {
            ++count[c - 'a'];
        }
        for (int i = 0; i < 26; ++i) {
            if (count[i] != 0) {
                pq.push(make_pair(count[i], i + 'a'));
            }
        }
        if ((pq.top().first) <= ((s.size() + 1) >> 1)) {
            ret.push_back(pq.top().second);
            --(*const_cast<int*>(&pq.top().first));
            if (pq.top().first == 0) {
                pq.pop();
            }
            for (int i = 0; i < s.size() - 1; ++i) {
                if (ret.back() == pq.top().second) {
                    pair<int, char>temp = pq.top();
                    pq.pop();
                    ret.push_back(pq.top().second);
                    --(*const_cast<int*>(&pq.top().first));
                    if (pq.top().first == 0) {
                        pq.pop();
                    }
                    pq.push(temp);
                }
                else {
                    ret.push_back(pq.top().second);
                    --(*const_cast<int*>(&pq.top().first));
                    if (pq.top().first == 0) {
                        pq.pop();
                    }
                }
            }
        }
        return ret;
    }
};