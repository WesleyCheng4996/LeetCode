class FreqStack {
    unordered_map<int, int> f;
    unordered_map<int, stack<int>> st;
    int maxf = 0;
public:
    void push(int val) {
        maxf = max(maxf, ++f[val]);
        st[f[val]].push(val);
        
    }
    
    int pop() {
        int val = st[maxf].top();
        st[maxf].pop();
        if(st[maxf].empty()) {
            --maxf;
        }
        --f[val];
        return val;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */