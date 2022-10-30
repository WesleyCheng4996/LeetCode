class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, char>seats;
        int ret = 0;
        for(vector<int>& vec : reservedSeats) {
            if(vec[1] > 1 && vec[1] < 10)
                seats[vec[0]]  |= (1 << (vec[1] - 2));
        }
        for(auto& [row, seat] : seats) {
            if((seat & 0b1111) == 0 || (seat & 0b111100) == 0 || (seat & 0b11110000) == 0)
                ++ret;
        }
        return ret + (n - seats.size()) * 2;
    }
};