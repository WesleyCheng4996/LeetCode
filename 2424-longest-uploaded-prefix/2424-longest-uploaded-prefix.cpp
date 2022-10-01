class LUPrefix {
public:
    LUPrefix(int n) {
        ++n;
        n_ = n;
        curr_ = 0;
        y_ = new bool[n]();
    }
    ~LUPrefix() {
        delete []y_;
    }
    void upload(int video) {
        y_[video] = 1;
        int ret = 0;
        for(int i = curr_ + 1; i < n_; ++i) {
            if(y_[i]) {
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
    int n_;
    int curr_;
    bool *y_;
};

/**
 * Your LUPrefix object will be instantiated and called as such:
 * LUPrefix* obj = new LUPrefix(n);
 * obj->upload(video);
 * int param_2 = obj->longest();
 */