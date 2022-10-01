class LUPrefix {
public:
    LUPrefix(int n) {
        ++n;
        len_ = n;
        curr_ = 0;
        arr_ = new bool[n]();
    }
    ~LUPrefix() {
        delete []arr_;
    }
    void upload(int video) {
        arr_[video] = true;
        for(int i = curr_ + 1; i < len_; ++i) {
            if(arr_[i]) {
                ++curr_;
            } else {
                break;
            }
        }
    }
    
    int longest() {
        return curr_;
    }
private:
    int len_;
    int curr_;
    bool *arr_;
};

/**
 * Your LUPrefix object will be instantiated and called as such:
 * LUPrefix* obj = new LUPrefix(n);
 * obj->upload(video);
 * int param_2 = obj->longest();
 */