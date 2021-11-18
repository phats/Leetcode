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
    int findNumofRotated(vector<int> nums){
        int temp=-1;
        for (int i=nums.size()-1;i>0;i--){
            if (nums[i]<nums[0]){
                temp=i;
            }
            else {
                break;
            }
        }
        return temp;
    }
    int search(vector<int>& nums, int target) {
        if (findNumofRotated(nums)==-1){
            return binarySearch(nums,target,0,nums.size()-1);
        }
        else if (nums[0]>target){
            return binarySearch(nums,target,findNumofRotated(nums),nums.size()-1);
        }
        else {
            return binarySearch(nums,target,0,findNumofRotated(nums)-1);
        }
    }
};