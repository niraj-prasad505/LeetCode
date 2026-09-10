class Solution {
public:
vector<vector<int>> result;
    void backtrack(vector<int> nums,vector<int> current, int index,int target) {
        if (target == 0) {
            result.push_back(current);
            return;
        }
        
        for(int i = index; i < nums.size();i++){
            if (i>index &&nums[i] == nums[i - 1] ){
                continue;
            }
            if (nums[i] > target){
                break;
            }
            current.push_back(nums[i]);
            backtrack(nums, current,i + 1,target-nums[i]);
            current.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> current;
        sort(candidates.begin(), candidates.end());
        backtrack(candidates,current,0,target);
        return result;
    }
};
