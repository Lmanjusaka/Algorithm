//
// Created by liuchen on 2020/3/5.
//
#include <iostream>

using namespace std;
int main(){
    int min = 0;
    int a[10] = {10,9,8,7,6,5,4,3,2,1};
    for (int i = 0; i < 10; ++i) {
        min = i;
        for (int j = i + 1; j <10 ; ++j) {
            if (a[j ] < a[min]){
                min = j ;
            }
        }
        swap(a[i],a[min]);
    }
    for (int k = 0; k < 10; ++k) {
        cout<<a[k];
    }

}

