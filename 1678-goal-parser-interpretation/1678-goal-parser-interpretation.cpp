class Solution {
public:
    string interpret(string command) {
        return regex_replace(regex_replace(command, regex("\\(al\\)"), "al"), regex("\\(\\)"), "o");;
    }
};