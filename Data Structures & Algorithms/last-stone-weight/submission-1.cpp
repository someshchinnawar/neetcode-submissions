class Solution {
public:
    //optimal solution
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> maxHeap;

        for(int num : stones){
            maxHeap.push(num);
        }

        while(maxHeap.size() > 1){
            int x = maxHeap.top();
            maxHeap.pop();

            int y = maxHeap.top();
            maxHeap.pop();

            //if x and y are not equal
            if(x != y){
                maxHeap.push(x-y);
            }
        }
        if(maxHeap.empty()){
            return 0;
        }
        return maxHeap.top();
    }
};
