#include "vector"
#include "algorithm"
#include <iostream>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target){
        sort(nums.begin(), nums.end());
        int closest =  target - nums[0] - nums[1] - nums[2],distance = 0;

        for (int i = 0; i < nums.size(); ++i) {

            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            int left = i + 1,right = nums.size() - 1;
            while (left < right){
                distance = target - nums[left] - nums[right] - nums[i];
                if (abs(distance) < abs(closest))
                    closest = distance;
                if (nums[left] + nums[right] + nums[i] < target)
                    left++;
                else if (nums[left] + nums[right] + nums[i] > target)
                    right--;
                else
                    return target;
            }

        }
        return target - closest;
    }

};
int main(){
    vector<int> nums = {-1, 2, 1, -4};
    int res = Solution().threeSumClosest(nums, 1);
    cout<<res;

}

