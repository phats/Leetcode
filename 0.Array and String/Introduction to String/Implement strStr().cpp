class Solution {
public:
    int strStr(string haystack, string needle) {
        if (haystack==""){
            if (needle=="") return 0;
            return -1;
        }
        if (haystack.size()<needle.size()) return -1;
        for (int i=0;i<haystack.size()-needle.size()+1;i++){
            if (haystack.substr(i,needle.size())==needle) return i;
        }
        return -1;
    }
};