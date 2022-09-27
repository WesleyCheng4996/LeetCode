class Solution {
public:
    int rand2() {
        int num = rand7();
        while (num == 7) {
            num = rand7();
        }
        
        return num <= 3;
    }
    
    int rand5() {
        int num = rand7();
        while (num > 5) {
            num = rand7();
        }
        
        return num;
    }
    
    int rand10() {
        return (rand2() * 5) + rand5();
    }
};