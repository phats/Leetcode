class Solution {
public:
    string addBinary(string a, string b) {
        int i=a.length()-1,j=b.length()-1;
        int temp=0;
        string result;
        while(i>=0 &&j>=0){
            temp += (a[i]-'0')+(b[j]-'0');
            result=to_string(temp%2)+result;
            temp /=2;
            --j;
            --i;
        }
        while (i>=0){
            temp += (a[i]-'0');
            result=to_string(temp%2)+result;
            temp /=2;
            --i;
        }
        while (j>=0){
            temp += (b[j]-'0');
            result=to_string(temp%2)+result;
            temp /=2;
            --j;
        }
        if (temp){
            result=to_string(temp)+result;
        }
        return result;
        }
};