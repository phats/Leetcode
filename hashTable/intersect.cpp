class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> myMap;
        for (int i=0;i<nums1.size();i++){
            auto got=myMap.find(nums1[i]);
            if (got!=myMap.end()){
                got->second++;
            }
            else{
                myMap.insert({nums1[i],1});
            }
        }
        vector<int> res;
        for (int i=0;i<nums2.size();i++){
            auto got=myMap.find(nums2[i]);
            if(got!=myMap.end() && got->second>0){
                res.push_back(got->first);
                --got->second;
            }
        }
        return res;
    }
};