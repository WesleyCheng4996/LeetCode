struct Table{
    Table() :arr() {
        for(int i = 0; i < 10000; ++i) {
            if(i % 3 == 0 && i % 5 == 0) {
                arr[i] = "FizzBuzz";
            } else if(i % 3 == 0) {
                arr[i] = "Fizz";
            } else if(i % 5 == 0) {
                arr[i] = "Buzz";
            } else {
                arr[i] = to_string(i);
            }
        }
    }
    string arr[10001];
};
Table t;
class Solution {
public:
    vector<string> fizzBuzz(int n) {
        return vector<string>(t.arr + 1, t.arr + n + 1);
    }
};