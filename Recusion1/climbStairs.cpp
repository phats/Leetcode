class Solution {
public:
    int climbStairs(int n) {
        vector<int> arr={1,2};
        for (int i=2;i<n;i++){
            arr.push_back(arr[i-1]+arr[i-2]);
        }
        return arr[n-1];
    }
};