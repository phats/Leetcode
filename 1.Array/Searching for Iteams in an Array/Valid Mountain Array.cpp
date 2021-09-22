class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int max_arr=arr[0];
        for (int i=0;i<arr.size();i++){
            max_arr=max(arr[i],max_arr);
        }
        if (arr[0]==max_arr || arr[arr.size()-1]==max_arr) return 0;
        int i_max;
        for (int i=0;i<arr.size();i++){
            if (arr[i]==max_arr) {
                i_max=i;
                continue;
            }
            if (arr[i]==max_arr) return 0;
        }
        for (int i=0;i<i_max;i++){
            if (arr[i]>=arr[i+1]) return 0;
        }
        for (int i=i_max+1;i<arr.size();i++){
            if (arr[i]>=arr[i-1]) return 0;
        }
        return 1;
    }
};