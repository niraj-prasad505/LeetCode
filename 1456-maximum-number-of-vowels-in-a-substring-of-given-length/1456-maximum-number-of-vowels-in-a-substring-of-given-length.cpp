class Solution {
public:
    int maxVowels(string s, int k) {
        int n = s.size();
        int ans = 0;
        for (int i = 0; i < k; i++) {
            char ch = s[i];
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
                ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U') 
            {
                ans+=1;
            }
        }

        if (ans >= k){
            return ans;
        }
        if(n==k &&ans >= k ){
            return ans;
        }
        int currentMax=ans;
        for (int i = k; i < n; i++) {
            char add = s[i];
            if (add == 'a' || add == 'e' || add == 'i' ||
                add == 'o' || add == 'u') {
                currentMax++;
            }
            char remove = s[i - k];

            if (remove == 'a' || remove == 'e' || remove == 'i' ||
                remove == 'o' || remove == 'u') {
                currentMax--;
            }
            ans = max(ans, currentMax);
        }
        return ans;
    }
};