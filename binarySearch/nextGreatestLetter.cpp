class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int left=0;
        int right=letters.size()-1;
        while(left<=right){
            int mid =(left+right)/2;
            cout<<mid<<" ";
            if (mid>0 && letters[mid]>target &&target>=letters[mid-1] ){
                return letters[mid];
            }
            else  if (letters[mid]>target){
                right=mid-1;
            }
            else {
                left=mid+1;
            }
        }
        return letters[0];
    }
};