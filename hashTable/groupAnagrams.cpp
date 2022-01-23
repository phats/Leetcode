class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string,int> myMap;
        // first: strs[i] | second: index in Result array
        int index=0;
        for (int i=0;i<strs.size();i++){
            string curr=strs[i];
            sort(curr.begin(),curr.end());
            auto got=myMap.find(curr);
            if (got == myMap.end()){
                myMap.insert({curr,index++});
                vector<string> temp;
                temp.push_back(strs[i]);
                res.push_back(temp);
            }
            else{
                res[got->second].push_back(strs[i]);
            }
        }
        return res;
    }
};