class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int remain=1;
        
        for (int i=digits.size()-1;i>=0;--i){
            digits[i]+=remain;
            remain=digits[i]/10;
            digits[i] =digits[i] %10;
        }
        
        if (remain){
            digits.push_back(0);
            digits[0]=remain;
        }
        
        return digits;
    }
};