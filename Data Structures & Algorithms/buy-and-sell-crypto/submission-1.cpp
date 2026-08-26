class Solution {
public:
    //optimal solution
    int maxProfit(vector<int>& prices) {
        int minPrice = prices[0];
        int maxPro = 0;
        
        for(int i=1;i<prices.size();i++){
            maxPro = max(maxPro, prices[i] - minPrice);
            minPrice = min(minPrice, prices[i]);
        }
        return maxPro;
    }
};
