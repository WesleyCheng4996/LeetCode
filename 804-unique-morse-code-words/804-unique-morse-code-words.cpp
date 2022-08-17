class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string>morse{".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        int ans(0);
        set<string>dict;
        string str = "";
        for(auto word: words){
            for(char alpha: word){
                str += morse[alpha - 'a'];
            }
            dict.insert(str);
            str = "";
        }
        return dict.size();
    }
};