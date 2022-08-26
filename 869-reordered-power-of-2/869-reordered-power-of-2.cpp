class Solution {
public:
    bool reorderedPowerOf2(int num) {
        const short num_digits(recordDigits(num));

        for (int i(0); i < 32; ++i) {
            const short _2_power_of_i_digits(recordDigits(1 << i));
            if (recordDigits(1 << i) == num_digits) {
                return true;
            }
        }
        return false;
    }

    short recordDigits(unsigned int num) {
        short result(0);
        do {
            result += 1 << (num % 10);
            num /= 10;
        } while (num != 0);

        return result;
    }
};