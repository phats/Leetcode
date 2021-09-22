#include<iostream>
#include<vector>
using namespace std;
int thirdMax(vector<int>& nums) {
    vector<int> find{ INT_MIN , INT_MIN, INT_MIN };
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] >= find[1]) {
            if (nums[i] > find[0]) {
                find[2] = find[1];
                find[1] = find[0];
                find[0] = nums[i];
            }
            else if (nums[i] > find[1]) {
                find[2] = find[1];
                find[1] = nums[i];
            }
        }
        else find[2] = max(find[2], nums[i]);
    }
    if (nums.size() < 3) return find[0];
    return find[2];
}
int main() {
    vector<int> a{ 2,2,3,1 };
    cout << thirdMax(a);
}