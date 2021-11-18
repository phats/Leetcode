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
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        for (int i=0;i<nums1.size();i++){
            if (binarySearch(nums2,nums1[i],0,nums2.size()-1) != -1 && binarySearch(res,nums1[i],0,res.size()-1) == -1){
                res.push_back(nums1[i]);
            }
        }
        return res;
    }
};