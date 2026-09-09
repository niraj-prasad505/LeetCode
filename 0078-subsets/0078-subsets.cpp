class Solution {
public:
    vector<vector<int>> result;
    void backtrack(vector<int> nums,vector<int> current, int index) {
        result.push_back(current);

        for(int i = index; i < nums.size();i++){
            current.push_back(nums[i]);
            backtrack(nums, current,i + 1);
            current.pop_back();
        }


    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> current;
        
        backtrack(nums,current,0);
        return result;
    }
};