

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        
        static constexpr void* labels[] = {&&ISOPERATOR, &&ISDIGIT, &&DONE};
        static constexpr void* operators[] = {&&MUL, &&ADD, &&DONE, &&SUB, &&DONE, &&DIV};
        
        stack<int>st;

        reverse(tokens.begin(), tokens.end());
        
        
        while(!tokens.empty()){
            int a, b;
            goto *labels[isNumber(tokens.back())];
        ISDIGIT:
            a = stoi(tokens.back());
            goto DONE;
        ISOPERATOR:
            b = st.top();
            st.pop();
            a = st.top();
            st.pop();
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
            st.push(a);
            tokens.pop_back();
        }
        
        return st.top();
    }
                            
    bool isNumber(const string& str){
        return str.size() > 1 || (str.size() == 1 && isdigit(str.back())) ;
    }
};