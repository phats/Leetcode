// Remove Element.cpp
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int count = 0;
        int left = 0,right = nums.size()-1;
        
        while(left<= right){
            while (right >= 0 && nums[right]==val){
                --right;
                ++count;
            }
            while (left < nums.size() && nums[left] != val) {
                ++left;
            }

            if (left <= right){
                swap(nums[left++],nums[right--]);
                ++count;
            }        
        }
        if (count){
            nums.erase(nums.end()-count,nums.end());
        }
        return nums.size();
    }
};