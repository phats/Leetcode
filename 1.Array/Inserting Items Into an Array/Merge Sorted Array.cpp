class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if (nums2.size()==0) return ;
        if (m==0){
            nums1.erase(nums1.end()-n,nums1.end());
            for (int i=0;i<n;i++){
                nums1.push_back(nums2[i]);
            }
            return;
        }
        nums1.erase(nums1.end()-n,nums1.end());
        for (int i=0;i<n;i++){
            nums1.push_back(nums2[i]);
        }
        sort(nums1.begin(),nums1.end());
    }
};