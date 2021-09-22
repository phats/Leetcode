class Solution {
public:
    int thirdMax(vector<int>& nums) {
        vector<long long> find{ INT64_MIN , INT64_MIN, INT64_MIN };
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] >= find[1]) {
                if (nums[i] > find[0]) {
                    if (find[1] != find[0]){
                        find[2] = find[1];
                        find[1] = find[0];
                        }
                    find[0] = nums[i];

                }
                else if ((nums[i] > find[1]) && (nums[i] != find[0])) {
                    find[2] = find[1];
                    find[1] = nums[i];
                }
            }
            else if (nums[i]>find[2]) find[2]=nums[i];
        }
        if (find[2]==INT64_MIN ) return (int)find[0];
        return (int)find[2];
}

};