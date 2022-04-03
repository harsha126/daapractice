#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;    
int main(){
    vector<int> arr{1,2,3,4,5};
    vector<int> arr2(5);
    for(auto i : arr) cout << i << ",";
    copy(arr.begin(),arr.end(),arr2.begin());
    for(auto i : arr2) cout << i << " ";
    return 0;
}