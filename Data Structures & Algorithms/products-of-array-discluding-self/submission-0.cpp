class Solution {
public:
    //Brute Force
    vector<int> productExceptSelf(vector<int>& nums) {
        int product = 1;
        vector<int> res;
        int n = nums.size();
        for(int i=0;i<n;i++){
            product = 1;
            for(int j=0;j<n;j++){
                //Checking that if i and j are on both number then don't add that into the product
                if(i != j){
                    product *= nums[j];
                }
            }
            res.push_back(product);
        }
        return res;
    }
};
