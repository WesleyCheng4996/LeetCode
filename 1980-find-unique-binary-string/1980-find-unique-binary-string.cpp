string itos2(int num, int k) {
    string ret(k--, '0');
    while(k > -1) {
        ret[k--] = (num & 1) + '0';
        num >>= 1;
    }
    return ret;
}

class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int num = (1 << nums.size()) - 1;
    LOOP:
        string str(itos2(num--, nums.size()));
        for(string s : nums) {
            if(s == str) {
                goto LOOP;
            }
        }
        return str;
    }
};