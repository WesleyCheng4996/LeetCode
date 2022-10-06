struct Time_Value {
    Time_Value(int t, string v) : time(t), value(v) {}
    int time;
    string value;
    bool operator<(Time_Value& other) { return this->time < other.time; }
    bool operator>(Time_Value& other) { return this->time > other.time; }
    bool operator<=(Time_Value& other) { return this->time <= other.time; }
    bool operator>=(Time_Value& other) { return this->time >= other.time; }
    operator int() const { return time; }
};
class TimeMap {
    unordered_map<string, vector<Time_Value>> mp;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back(Time_Value{timestamp, value});
    }
    
    string get(string key, int timestamp) {
        vector<Time_Value>& vec = mp[key];
        if(vec.empty()) {
            return "";
        }
        vector<Time_Value>::iterator it = (upper_bound(vec.begin(), vec.end(), timestamp) - 1);
        return it < vec.begin() ? "" : it->value;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */