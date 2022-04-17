//
// Created by liuchen on 2022/2/8.
//
#include <iostream>
#include "vector"
#include "unordered_map"
#include "algorithm"
using namespace std;
class Solution{
public:
    vector<vector<int>> threeSum(vector<int>& nums){

        vector<vector<int>> res;

        sort(nums.begin(),nums.end());           //递增排序
        for (int i = 0; i < nums.size(); ++i) {
            if(nums[i] > 0)
                return res;
            if(i > 0 && nums[i] == nums[i - 1])     //排除重复
                continue;
            int left = i + 1, right = nums.size() - 1;
            while(left < right) {
                if ( nums[left] + nums[right] < -nums[i])
                    left++;
                else if ( nums[left] + nums[right] > -nums[i])
                    right--;
                else {
                    res.push_back(vector<int>{nums[i], nums[left], nums[right]});
                    while(left < right && nums[left] == nums[left + 1])
                        left++;
                    while (left < right && nums[right] == nums[right - 1])
                        right--;
                    left++;
                    right--;
                }
            }

        }
        return res;
    }
};
int main(){
    vector<int> nums = { -1, 0, 1, 2, -1, -4};
    vector<vector<int>> res;
    res = Solution().threeSum(nums);
    cout<<'[';
    int i = 0;
    for (i = 0; i < res.size(); ++i) {
        cout<<'[';
        for (int j = 0; j < res[i].size(); ++j) {
            if(j != res[i].size() - 1)
                cout<<res[i][j]<<',';
            else
                cout<<res[i][j];
        }
        if(i != res.size() - 1)
            cout<<']'<<',';
        else
            cout<<']';
    }
    cout<<']';
}