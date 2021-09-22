class Solution {
public:
    int findMax_right(int index,vector<int> arr){
        if (index==arr.size()-1) return arr[arr.size()-1];
        int result=arr[index+1];
        for (int i=index+1;i<arr.size();i++){
            result=max(result,arr[i]);
        }
        return result;
    }
    vector<int> replaceElements(vector<int>& arr) {
        vector<int> result;
        if (arr.size()==1) {
            result.push_back(-1);
            return result;
        }
        int temp=findMax_right(0,arr);
        result.push_back(temp);
        for (int i=1;i<arr.size()-1;i++){
            if (temp ==arr[i]){
                temp=findMax_right(i,arr);   
            }
            result.push_back(temp);
        }
        result.push_back(-1);
        return result;
    }
};