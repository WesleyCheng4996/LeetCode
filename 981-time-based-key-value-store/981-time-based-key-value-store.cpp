class TimeMap {
public:
  std::unordered_map<std::string, std::vector<std::pair<int,std::string>>> m;

  TimeMap() {
    // *** need this constructor to boost the speed ***  
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
  }
  
  void set(string key, string value, int timestamp) {
    m[key].push_back({timestamp,value});
  }
  
  string get(string key, int timestamp) {
    std::vector<std::pair<int,std::string>> &v = m[key];
    
    /**
    std::cout << "get " << key << ", " << timestamp << std::endl;
    for (auto &a : v) {
      std::cout << a.first << ", " << a.second << std::endl;
    }
    std::cout << std::endl;
    /**/

    if (v.empty()) {
      return "";
    }
    if (v[0].first > timestamp) {
      return "";
    }
    //if (v.back().first <= timestamp) {
      //return v.back().second;
    //}

    return std::lower_bound(v.rbegin(),v.rend(),std::pair<int,std::string>{timestamp,""},
				      [](const std::pair<int,std::string> &a, const std::pair<int,std::string> &b) { return (a.first > b.first); })->second;
  }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */