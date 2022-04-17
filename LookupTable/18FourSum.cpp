//
// Created by liuchen on 2022/2/11.
//

#include "vector"
#include "iostream"
#include "algorithm"
using namespace std;
/*
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target){
        vector<vector<int>> res;
        //先进行排序
        sort(nums.begin(), nums.end());
        int size = nums.size();
        if (size < 4)
            return res;
        for (int i = 0; i < nums.size() - 3; ++i) {
        //如果如果有重复元素，进行下一次遍历
            if(i > 0 && nums[i] == nums[i - 1])
                continue;
        //如果前面四个数的和大于目标，则后面也无法找到，退出循环
            if(nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target)
                break;
        //如果前面的一个数和后面的三个数之和小于目标函数则进行下一次循环
            if(nums[i] + nums[size - 1] + nums[size - 2] + nums[size - 3] < target)
                continue;
            for (int j = i + 1; j < nums.size() - 2; ++j) {
                if(j > i + 1 && nums[j] == nums[j - 1])
                    continue;
                if (nums[j] + nums[j + 1] + nums[j + 2] > target - nums[i])
                    break;
                if(nums[j] + nums[size - 1] + nums[size - 2] < target - nums[i])
                    continue;
                int left = j + 1, right = size - 1;
                while (left < right){
                    if (nums[left] + nums[right] > target - nums[i] - nums[j])
                        right--;
                    else if (nums[left] + nums[right] < target - nums[i] - nums[j])
                        left++;
                    else{
                        res.push_back(vector<int>{nums[i], nums[j], nums[left], nums[right]});
                        while (left < right && nums[left] == nums[left + 1])
                            left++;
                        while (left < right && nums[right] == nums[right - 1])
                            right--;
                        left++;
                        right--;
                    }
                }
            }
        }
        return res;
    }

};
*/
class Solution {
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target) {
        vector<vector<int>> res;
        for (int i = 0; i < ; ++i) {
            
        }
    }
};
int main(){

}