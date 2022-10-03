class Solution {
public:
    long long smallestNumber(long long num) {
        if(num == 0) 
            return 0;
        bool sign = (num < 0);
        string ns;
        if(sign){
            num =~num + 1;
            ns = to_string(num);
            sort(ns.begin(), ns.end(), [](char c, char cc) { return c > cc; });
        } else {
            ns = to_string(num);
            sort(ns.begin(), ns.end());
            int idx = 0;
            while(ns[idx] == '0') {
                ++idx;
            }
            swap(ns[0], ns[idx]);
        }
        return sign ? - convert(ns) : convert(ns);
    }
    
    long long convert(string num) {
        long long ret = 0;
        for(char ch : num) {
            ret *= 10;
            ret += ch - '0';
        }
        return ret;
    }
};