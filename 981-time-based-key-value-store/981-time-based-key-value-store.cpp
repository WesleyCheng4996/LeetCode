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
    
    unordered_map<string, map<int, string>> m;
void set(string key, string value, int timestamp) {
  m[key].insert({ timestamp, value });
}
string get(string key, int timestamp) {
  auto it = m[key].upper_bound(timestamp);
  return it == m[key].begin() ? "" : prev(it)->second;
}
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */