class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        int count=0;
        unordered_set<char> Jewelry;
        for (int i=0;i<jewels.length();i++){
            Jewelry.insert(jewels[i]);
        }
        for (int i=0;i<stones.length();i++){
            if (Jewelry.find(stones[i])!=Jewelry.end()){
                ++count;
            }
        }
        return count;
    }
};