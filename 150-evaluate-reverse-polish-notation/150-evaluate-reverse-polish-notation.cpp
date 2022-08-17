class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        
        if(tokens.size() == 1){
            return stoi(tokens.back());
        }
        
        vector<int>stack;
        reverse(tokens.begin(), tokens.end());
        
        constexpr void* labels[] = {&&ISOPERATOR, &&ISDIGIT, &&DONE};
        constexpr void* operators[] = {&&MUL, &&ADD, &&DONE, &&SUB, &&DONE, &&DIV};
        while(!tokens.empty()){
            int a, b;
            goto *labels[isNumber(tokens.back())];
        ISDIGIT:
            a = stoi(tokens.back());
            goto DONE;
        ISOPERATOR:
            b = stack.back();
            stack.pop_back();
            a = stack.back();
            stack.pop_back();
            goto *operators[tokens.back().back() - 42];
        ADD:
            a += b;
            goto DONE;
        SUB:
            a -=b ;
            goto DONE;
        MUL:
            a *= b;
            goto DONE;
        DIV: a /= b;
            goto DONE;

        DONE:
            stack.push_back(a);
            tokens.pop_back();
        }
        
        return stack.back();
    }
                            
    bool isNumber(const string& str){
        return str.size() > 1 || (str.size() == 1 && isdigit(str.back())) ;
    }
};