class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,pair<int,int>> myMap;
        // pair: first: index, second: number of occurrences
        for (int i=0;i<s.length();i++){
            auto got=myMap.find(s[i]);
            if (got!=myMap.end()){
                got->second.second++;
            }
            else{
                myMap.insert({s[i],{i,1}});
            }
        }
        int res=s.length();
        for (auto i=myMap.begin();i!=myMap.end();i++){
            if (i->second.second==1){
                res=min(res,i->second.first);
            }
        }
        if (res!=s.length()){
            return res;
        }
        else{
            return -1;
        }
    }
};