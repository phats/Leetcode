// Minimum Size Subarray Sum.cpp
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        // Init default value
        int res = nums.size() + 1;
        
        if (!nums.empty()){
            // Control segment by two pointers
            int left = 0;
            int right = 0;
            int currentSum = 0;
            
            while (left < nums.size() && left <= right){
                while (currentSum < s && right < nums.size()){
                    currentSum += nums[right++];   
                }
                
                while (currentSum >= s){
                    res = min(res, right - left);
                    currentSum -= nums[left++];
                }
                
                if (right == nums.size()){
                    break;
                }
            }
        }
        
        return (res == nums.size() + 1) ? 0: res;
    }
};