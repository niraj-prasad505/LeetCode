class Solution {
private:
    bool solve(string s, int start, int end){
        while(start<end){
            if (s[start]!=s[end]){
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
public:
    bool validPalindrome(string s) {
        int start=0;
        int end=s.size()-1;
        int count=0;

        while(start<end){
            if (s[start]!=s[end]){
                return solve(s, start+1, end) ||solve(s, start, end-1);
            }
            start++;
            end--;
        }
        return true;
    }
};