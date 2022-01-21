//
// Created by liuchen on 2021/3/25.
//

#include <iostream>
#include "vector"
using namespace std;
class Solution{
public:
    void moveZeroes(vector<int> &nums) {
        int j = 0;
        for(int i = 0; i < nums.size(); i++)
            if(nums[i] != 0)
                nums[j++] = nums[i];
        while(j < nums.size())
            nums[j++] = 0;
    }
};

int main(){
    vector<int> nums = {0,1,0,3,12};
    Solution().moveZeroes(nums);
    for(int a : nums)
        cout<<a<<" ";

}