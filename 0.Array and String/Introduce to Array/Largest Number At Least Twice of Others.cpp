class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int index = 0;
        int nums_max = nums[0];
        if (nums.size() == 1) return 0;
        for (int i = 0; i < nums.size(); i++) {
            nums_max = max(nums_max, nums[i]);
        }
        bool check_first = true;
        int second_max;
        if (nums_max == nums[0]) {
            second_max = nums[1];
        }
        else {
            second_max = nums[0];
        }
        for (int i = 0; i < nums.size(); i++) {
            if (nums_max == nums[i] && check_first) {
                check_first = false;
                index = i;
                //continue;
            }
            else {
                second_max = max(second_max, nums[i]);
            }
        }
        if (nums_max >= second_max * 2) {
            return index;
        }
        return -1;
    }
};