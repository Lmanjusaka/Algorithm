//
// Created by liuchen on 2022/2/27.
//
#include "vector"
#include "string"
#include "iostream"
#include "unordered_map"
#include "algorithm"

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs) {
        vector<vector<string>> res;
        vector<string > str_list;
        unordered_map<string, vector<string>> res_map;
        for (int i = 0; i < strs.size(); ++i) {
            string key = strs[i];
            sort(key.begin(),key.end());        //对字符串进行排序
            res_map[key].push_back(strs[i]);    //以排序后的字符串为键添加相同元素
        }
        for (auto iter = res_map.begin(); iter!=res_map.end(); iter++) {
            res.push_back(iter->second);
        }

        return res;
    }
};

int main() {
//    cout<<"123";
    vector<vector<string>> res;
    vector<string> a = {"eat", "tea", "tan", "ate", "nat", "bat"};
    res = Solution().groupAnagrams(a);
    cout<<'[';
    for (int i = 0; i < res.size(); ++i) {
        cout<<'[';
        for (int j = 0; j < res[i].size(); ++j) {
            if (j != res[i].size() - 1)
                cout<<res[i][j]<<',';
            else
                cout<<res[i][j];
        }
        if (i != res.size() - 1)
            cout<<"],";
        else
            cout<<']';
    }
    cout<<']';


}