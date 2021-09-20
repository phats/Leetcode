class Solution {
public:
    vector<string> StringtoVector(string s){
        vector<string> result;
        string tam;
        for (int i=0;i<s.size();i++){
            if (s[i] !=' ') tam=tam+s[i];
            if (tam !="" && (s[i]==' ' || i==s.size()-1)){
                result.push_back(tam);
                tam="";
            }
        }
        return result;
    }
    string reverseWords(string s) {
        string result;
        vector<string> result_arr=StringtoVector(s);
        reverse(result_arr.begin(), result_arr.end());
        for (int i=0;i<result_arr.size();i++){
            result=result+result_arr[i]+" ";
        }
        result.pop_back();
        return result;
    }
};