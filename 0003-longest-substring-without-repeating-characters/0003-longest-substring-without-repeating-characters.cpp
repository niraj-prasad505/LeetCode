class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left=0;
        int ans=0;
        set<int> s1;
        for(int right = 0; right < s.size(); right++){

            while(s1.find(s[right]) != s1.end()){
                
                s1.erase(s[left]);
                left++;
            }
            s1.insert(s[right]);
            ans=max(ans,right-left+1);
        }
        return ans;
    }
};