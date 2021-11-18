class Solution {
public:
    int binarySearch(vector<int>& nums, int target, int left, int right){
        int mid=(left+right)/2;
        if ((left==0 && right==0 && nums[0] != target) || left>right){
            return -1;
        }
        if (target==nums[mid]){
            return mid;
        }
        else if (target>nums[mid]){
            return binarySearch(nums,target,mid+1,right);
        }
        else{
            return binarySearch(nums,target,left,mid-1);
        }
    }
    int search(vector<int>& nums, int target) {
        return binarySearch(nums,target,0,nums.size()-1);
    }
};