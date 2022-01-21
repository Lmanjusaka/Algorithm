//
// Created by liuchen on 2021/3/25.
//

#include <iostream>
#include "vector"
using namespace std;
/* 优化前
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
*/

class Solution{
public:
    void moveZeroes(vector<int> &nums) {
        int j = 0;
        for(int i = 0; i < nums.size(); i++)
            if(nums[i] ){
                if(i != j)
                    swap(nums[j++],nums[i]);
                else
                    j++;
            }

    }
};

int main(){
    vector<int> nums = {0,1,0,3,12};
    Solution().moveZeroes(nums);
    for(int a : nums)
        cout<<a<<" ";

}