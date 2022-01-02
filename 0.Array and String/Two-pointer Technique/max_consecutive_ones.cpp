class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int left = 0;
        int right = 0;
        int res = 0;
    //khoi tao bien
        if (nums.size() == 0)
            return res;
        else{
                // Find left of consecutive one
                while (left < nums.size()){
                    while (left < nums.size() && nums[left] == 0)
                        left += 1;
                    
                    if (left < nums.size()){
                        right = left;
                        // Find right of consecutive one
                        while (right < nums.size() && nums[right] == 1)
                            right += 1;
                        res = max(res, right - left);
                        left = right;
                    }
                }
            return res;
        }
    }
};