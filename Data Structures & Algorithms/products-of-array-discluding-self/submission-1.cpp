class Solution {
public:
    //Better Solution
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 0);
        int product = 1;
        int countZero = 0;
        // Count zeroes and multiply only non-zero numbers
        for (int i = 0; i < n; i++) {
            if (nums[i] != 0) {
                product *= nums[i];
            } else {
                countZero++;
            }
        }
        // Case 1: More than one zero
        // All products will be zero
        if (countZero > 1) {
            return ans;
        }
        // Case 2 and Case 3
        for (int i = 0; i < n; i++) {
            if (countZero == 1) {
                if (nums[i] == 0) {
                    ans[i] = product;
                } else {
                    ans[i] = 0;
                }
            } else {
                ans[i] = product / nums[i];
            }
        }
        return ans;
    }
};