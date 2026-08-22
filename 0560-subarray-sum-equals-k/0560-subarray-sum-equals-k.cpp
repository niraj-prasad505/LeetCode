class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        mp[0]=1;
        int count=0;
        int preSum=0;
        for(int i=0; i<nums.size();i++){
            preSum += nums[i];
            int removel=preSum-k;
            count += mp[removel];
            mp[preSum]+=1;

        }
        return count;
    }
};