class Solution {
public:
    int subtractProductAndSum(int n) {
        long long y = n;
        long long digit = 0;
        long long pro = 1;
        int sum = 0;
        while (y > 0) {
            digit = y % 10;
            // cout << "digit->"<< digit<<"\n";
            pro = pro * digit;
            // cout << "product"<< pro<<"\n";
            sum = sum + digit;
            y = y / 10;
        }
        return pro - sum;
    }
};