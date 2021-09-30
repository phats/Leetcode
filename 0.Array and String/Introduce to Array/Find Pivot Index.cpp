class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        vector<int> preFixSum;
        //Create PreFixSum
        preFixSum.push_back(nums[0]);
        for (int i=1;i<nums.size();i++){
            preFixSum.push_back(nums[i]+preFixSum[i-1]);
        }
        //Find Pivot Index
        int sumLeft;
        int sumRight;
        for (int i=0;i<nums.size();i++){
            if (i==0){
                sumLeft=0;
            }
            else{
                sumLeft=preFixSum[i-1];
            }
            sumRight=preFixSum[preFixSum.size()-1]-sumLeft-nums[i];
            if (sumLeft==sumRight){
                return i;
            }
        }
        //Not found Pivot Index 
        return -1;
 }
};