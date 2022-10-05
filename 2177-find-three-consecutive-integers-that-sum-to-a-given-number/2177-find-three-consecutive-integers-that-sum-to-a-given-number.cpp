class Solution {
public:
    vector<long long> sumOfThree(long long num) {
       if(num % 3) {
           return vector<long long>();
       } else {
           num /= 3;
           return vector<long long>{ num - 1, num, num + 1 };
       }
    }
};