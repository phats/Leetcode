class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> result;
        int min_pos=-1;
        //find minium positive number
        for (int i=0;i<nums.size();i++){
            if (nums[i] >=0){
                min_pos=i;
                break;
            }
        }
        if (min_pos==-1 ){
            for (int i=nums.size()-1;i>=0;i--){
                result.push_back(nums[i]*nums[i]);
            }
            return result;
        }
        int i=min_pos-1;
        int j=min_pos;
         //Split nums into 2 array: negative and positive 
        while(result.size() != nums.size()){
            if (i==-1){
                for (int k=j;k<nums.size();k++){
                    result.push_back(nums[k]*nums[k]);
                }
                break;
            }
            else if (j==nums.size()) {
                for (int k=i;k>=0;k--){
                    result.push_back(nums[k]*nums[k]);
                }
                break;
            }
            if ((-1)*nums[i]>nums[j]){
                result.push_back(nums[j]*nums[j]);
                j++;
            }
            else{
                result.push_back(nums[i]*nums[i]);
                i--;
            }
        }
        return result;
    }
};