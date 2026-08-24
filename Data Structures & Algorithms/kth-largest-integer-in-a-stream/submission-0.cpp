class KthLargest {
public:
    //brute force
    int k;
    vector<int> ans;
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        this->ans = nums;
    }
    
    int add(int val) {  
        ans.push_back(val);
        sort(ans.begin(),ans.end(),greater<int>());

        return ans[k-1];
    }
};
