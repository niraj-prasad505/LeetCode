class Solution {
public:
    int addDigits(int num) {
        long long x = num;
        int digit = 0;
        while (x >= 10) {
            long long sum = 0;
            while (x > 0) {
                digit = x % 10;
                sum += digit;
                x = x / 10;
            }
            x=sum;
        }
        return x;
    }
};