class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> mergeArr;
        int index_nums1=0;
        int index_nums2=0;
        while(index_nums1<nums1.size()&& index_nums2<nums2.size()){
            if (nums1[index_nums1]<=nums2[index_nums2]){
                mergeArr.push_back(nums1[index_nums1++]);
            }
            else {
                mergeArr.push_back(nums2[index_nums2++]);
            }
        }
        while(index_nums1<nums1.size()){
             mergeArr.push_back(nums1[index_nums1++]);
        }
        while(index_nums2<nums2.size()){
            mergeArr.push_back(nums2[index_nums2++]);
        }
        if (mergeArr.size()%2==0){
            return double((mergeArr[mergeArr.size()/2]+mergeArr[mergeArr.size()/2-1]))/2;
            cout<<"1";
        }
        else return (mergeArr[mergeArr.size()/2]);
    }
};