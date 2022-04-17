//
// Created by liuchen on 2022/4/4.
//
incldue "vector"
class Solution{
public:
    //求最大公约数
    int gcd(int a, int b){
        return b ? gdc(b, a % b) : a;
    }
    int maxPoints(vector<vector<int>>& points){

    }
};