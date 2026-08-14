class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        while(n--){
            ans^=nums[n];
        }
        return ans;
    }
};