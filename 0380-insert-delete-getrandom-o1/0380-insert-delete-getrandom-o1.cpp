class RandomizedSet {
public:
    RandomizedSet() {
        srand(time(0));
    }
    
    bool insert(int val) {
        return st.insert(val).second;
    }
    
    bool remove(int val) {
        if(st.count(val)) {
            st.erase(val);
            return true;
        }
        return false;
    }
    
    int getRandom() {
        unordered_set<int>::const_iterator it(st.begin());
        advance(it, rand() % st.size());
        return *it;
    }
    unordered_set<int>st;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */