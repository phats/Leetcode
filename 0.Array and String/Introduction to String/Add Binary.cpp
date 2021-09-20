class Solution {
public:
    string addBinary(string a, string b) {
        if (a.size() < b.size()) {
            string temp = b;
            b = a;
            a = temp;
        }
        while (b.size() < a.size()) {
            b = "0" + b;
        }
        string result;
        int sum=0;
        int nho=0;
        for (int i=a.size();i>=0;i--){
            sum=(a[i]-'0')+(b[i]-'0')+nho;
            if (sum==2){
                result="0"+result;
                nho=1;
            }
            else if (sum==3){
                result="1"+result;
                nho=1;
            }
            else if (sum==0){
                result="0"+result;
                nho=0;
            }
            else if (sum==1){
                result="1"+result;
                nho=0;
            }
        }
        if (nho==1) {
            result="1"+result;
        }
        return result;
    }
};