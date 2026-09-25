class Solution {
public:
    int reverse(int x) {
        long long y = x;
        long long ans = 0;
        int digit = 0;
        bool negative = x < 0;
        if (x < 0){
            y = -y;
        }
    
        while (y > 0) {
            digit = y % 10;
            y = y / 10;
            ans = ans * 10 + digit;
        }
        if (negative){
            ans=-ans;
        }
        if (ans > INT_MAX || ans < INT_MIN){
            return 0;
        }
    
        return ans;
    }
};