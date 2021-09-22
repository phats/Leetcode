class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int temp=arr.size();
        for (int i=0;i<arr.size();i++){
            if (arr[i]==0) {
                arr.insert(arr.begin()+i+1,0);
                i++;
            }
        }
        arr.erase(arr.begin()+temp,arr.end());
    }
};