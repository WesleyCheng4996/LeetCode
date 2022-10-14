class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int>record;
        for(string s : operations) {
            if(s == "+") {
                record.push_back(record.back() + record[record.size() - 2]);
            } else if(s == "D") {
                record.push_back(record.back() * 2);
            } else if(s == "C") {
                record.pop_back();
            } else {
                record.push_back(stoi(s));
            }
        }
        return accumulate(record.begin(), record.end(), 0);
    }
};