class Solution {
public:
    //Optimal Solution
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> preCount;
        preCount[0] = 1;
        int prefixSum = 0;
        int count = 0;
        for(int i=0;i<nums.size();i++){
            //calculating prefixSum
            prefixSum += nums[i];
            
            //formula to calculate the remaining 
            int needed = prefixSum - k;

            //check in the map if yes then increase the count
            if(preCount.find(needed) != preCount.end()){
                count += preCount[needed];
            }
            //if not add the prefixSum with count
            preCount[prefixSum]++;
        }
        return count;
    }
};