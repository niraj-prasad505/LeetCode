class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int slow=0;
        int count=0;
        for (int i =0; i<nums.size(); i++){
            if (i == 0 || nums[i] != nums[i - 1]){
                count =0;
            }else{
                count ++;
            }

            if (count <= 1){
                nums[slow]=nums[i];
                slow++;
            }
        }
        return slow;
        
    }
};