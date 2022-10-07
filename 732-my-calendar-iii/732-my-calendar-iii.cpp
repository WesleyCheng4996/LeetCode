class MyCalendarThree {
    map<int, int> mp;
public:
    int book(int start, int end) {
        mp[start]++;
        mp[end]--;
        int ongoing = 0, ret = 0;
        for (auto &[s, e] : mp) {
            ret = max(ret, ongoing += e);
        }
        return ret;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */