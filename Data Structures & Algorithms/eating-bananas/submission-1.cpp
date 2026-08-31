class Solution {
public:
    //Optimal solution
    int findMax(vector<int> &h){
        int maxi = INT_MIN;
        int n = h.size();
        for(int i=0;i<n;i++){
            maxi = max(maxi,h[i]);
        }
        return maxi;
    }
    long long calTotal(vector<int> &h, int mid){
        long long totalH = 0;
        int n = h.size();
        for(int i=0;i<h.size();i++){
            totalH += (h[i] + mid - 1 ) / mid;
        }
        return totalH;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1; 
        int high = findMax(piles);

        while(low <= high){
            int mid = low + (high - low) / 2;
            long long totalH = calTotal(piles, mid);

            if(totalH <= h){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return low;
    }
};
