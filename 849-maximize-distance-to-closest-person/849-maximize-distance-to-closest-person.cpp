class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int maxx = 0;
        for(int i = 0; i < seats.size(); ++i){
            if(seats[i] == 0){
                int count = 0;
                for(; i < seats.size() && seats[i] == 0; ++i, ++count);
                maxx = max(maxx, count);
            }
        }
        int count = 0;
        for(int i = 0; seats[i] == 0; ++i, ++count);
        maxx = max(maxx + 1 >> 1, count);
        count = 0;
        for(int i = seats.size() - 1; seats[i] == 0; --i, ++count);
        maxx = max(maxx, count);
        return maxx;
    }
};