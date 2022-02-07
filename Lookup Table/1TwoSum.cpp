//
// Created by liuchen on 2022/2/6.
//
#include "vector"
#include "unordered_map"
#include <iostream>
using namespace std;
class Solution{
public:
    vector<int> twoSum(vector<int>& nums, int target){
        unordered_map<int, int> table;
        for (int i = 0; i < nums.size() ; ++i) {
            int complete = target - nums[i];
            if(table.find(complete) != table.end()){
                vector<int> res = {i,table[complete]};
                return res;
            }
            table[nums[i]] = i;
        }
    }

};

int main(){
    vector<int> nums = { 2, 7 , 11 , 15};
    vector<int> res;
    res = Solution().twoSum(nums, 9);
    for (int a : res) {
        cout<<a<<',';
    }
}
