class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        
        if(tokens.size() == 1){
            return stoi(tokens.back());
        }
        
        vector<int>stack;
        reverse(tokens.begin(), tokens.end());
        
        constexpr void* labels[] = {&&ISOPERATOR, &&ISDIGIT, &&DONE};
        
        while(!tokens.empty()){
            int a, b;
            goto *labels[isNumber(tokens.back())];
        ISDIGIT:
            stack.push_back(stoi(tokens.back()));
            goto DONE;
        ISOPERATOR:
            b = stack.back();
            stack.pop_back();
            a = stack.back();
            stack.pop_back();
            switch(tokens.back().back()){
                case '+':
                    a += b;
                    break;
                case '-':
                    a -= b;
                    break;
                case '*':
                    a *= b;
                    break;
                case '/':
                    a /= b;
                    break;
            }
            stack.push_back(a);
        DONE:
            tokens.pop_back();

        }
        
        return stack.back();
    }
                            
    bool isNumber(const string& str){
        return str.size() > 1 || (str.size() == 1 && isdigit(str.back())) ;
    }
};