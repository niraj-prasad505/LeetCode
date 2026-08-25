class Solution {
private:
int maxval(vector<int> piles){
    int ans =piles[0];
    for( int i: piles ){
        ans=max(ans, i);
    }
    return ans;
}

long long tatalHfinder(vector<int> piles, int mid) {
    long long totalH = 0;
    for (int i = 0; i < piles.size(); i++) {
        totalH += ceil(piles[i] / (double)mid);
    }
    return totalH;
}

public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int start=1; 
        int end=maxval(piles);
        while(start<=end){
            int mid= (start+end)/2;
            long long totalH= tatalHfinder(piles, mid);
            if (totalH<=h){
                end= mid-1;
            }else{
                start=mid+1;
                
            }
        }
        return start;
    }
};