class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum_nums = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum_nums += nums[i];
        }
        if (sum_nums < target) return 0;
        if (sum_nums == target) return nums.size();
        int result = INT_MAX;
        int sum = 0;
        if (nums[nums.size() - 1] >= target) return 1;
        for (int i = 0; i < nums.size(); i++) {

            for (int j = i; j < nums.size(); j++) {
                sum += nums[j];
                if (sum >= target) {
                    result = min(result, j - i + 1);
                    break;
                }
            }
            sum = 0;
        }
        return result;
}
};