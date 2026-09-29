class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maxCandies = candies[0];
        vector<bool> ans;

        for (int x : candies) {
            if (x > maxCandies){
                maxCandies = x;
            }
        }
        
        for (int candy : candies) {
            if(candy + extraCandies >= maxCandies){
                ans.push_back(true);
            }else{
                ans.push_back(false);
            }
        }
        return ans;
    }
};