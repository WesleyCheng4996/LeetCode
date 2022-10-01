class LUPrefix {
public:
    LUPrefix(int n) : arr_(new bool[n + 1]()) {
            
    }
    
    void upload(int video) {
        arr_[video - 1] = true;
    }
    
    int longest() {
        while (arr_[curr_]) {
            ++curr_;
        }
        return curr_;
    }
private:
    bool *arr_;
    int curr_ = 0;
};

/**
 * Your LUPrefix object will be instantiated and called as such:
 * LUPrefix* obj = new LUPrefix(n);
 * obj->upload(video);
 * int param_2 = obj->longest();
 */