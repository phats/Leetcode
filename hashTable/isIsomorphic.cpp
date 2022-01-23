class Solution {
public:
    unordered_map<char,char> myMapS;
    unordered_map<char,char> myMapT;
    bool isIsomorphic(string s, string t) {
        for (int i=0;i<s.length();i++){
            auto gotS=myMapS.find(s[i]);
            auto gotT=myMapT.find(t[i]);
            if (gotS!=myMapS.end() &&gotS->second!=t[i]|| (gotT!=myMapT.end()&& gotT->second!=s[i])){
                return false;
            }
            else {
                myMapS.insert({s[i],t[i]});
                myMapT.insert({t[i],s[i]});
            }
            
        }
        
        return true;
    }
};