//
// Created by liuchen on 2022/4/16.
//

#include "unordered_set"
#include <iostream>
#include "vector"
using namespace std;
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> record;
        int j = 0;
        for(int i = 0; i < nums.size(); i++){
            if(record.find(nums[i]) != record.end())
                return true;
            record.insert(nums[i]);
            if(record.size() == k+1)
                record.erase(nums[i - k]);
        }
        return false;
    }
};

int main(){
    vector<int> num = {1, 2, 3, 1, 2, 3};
    Solution solution = Solution();
    cout<<solution.containsNearbyDuplicate(num, 2);
}