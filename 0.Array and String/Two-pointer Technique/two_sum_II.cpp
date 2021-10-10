// Two Sum II - Input array is sorted.cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> res;
        int left = 0;
        int right = numbers.size()-1;

        while(numbers[left] + numbers[right] != target){
            if (numbers[left] + numbers[right] > target)
                right--;
            else
                left++;     
        }
        res.push_back(left+1);
        res.push_back(right+1);
        return res;
    }
};