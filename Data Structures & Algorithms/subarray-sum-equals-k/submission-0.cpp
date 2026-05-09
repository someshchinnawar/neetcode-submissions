class Solution {
public:
    //Brute Force
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int total;
        int count = 0;
        for(int i=0;i<n;i++){
            total = 0;
            for(int j=i;j<n;j++){
                total += nums[j];
                if(total == k){
                    count++;
                }
            }   
        }
        return count;
    }
};