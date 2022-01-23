class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int lengthLongest=-1;
        //truong hop s=""
        int count=-1;
        unordered_map<char,int> character;
        int save=-1;
        // luu lan gap chu cai trung gan nhat
        for (int i=0;i<s.size();i++){
            auto got=character.find(s[i]);
            if (character.find(s[i])!=character.end()){
                lengthLongest=max(lengthLongest,count);
                save=max(save,got->second);
                // tim vi tri trung gan nhat
                count=i-save-1;
                got->second=i;
            }
            else{
                character.insert({s[i],i});
                ++count;
            }
        }
        lengthLongest=max(lengthLongest,count);
        return lengthLongest+1;
    }
};