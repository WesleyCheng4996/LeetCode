class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int *count = new int[bank.size()]();
        for(int i = 0, end = bank.size(); i < end; ++i) {
            count[i] = accumulate(bank[i].begin(), bank[i].end(), 0, 
                                  [](int sum, int x)
                                  {
                                      return sum + (x == '1'); 
                                  }
                                 );
        }
        int last = 0;
        return accumulate(count, count + bank.size(), 0, 
                          [&](int sum, int x)
                          { 
                              if(x != 0) {
                                  sum += (last * x);
                                  last = x;
                              }
                              return sum;
                          });
    }
};