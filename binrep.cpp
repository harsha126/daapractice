#include<iostream>
using namespace std;

int main(){
    int n,arr[1000],c=0,k=0;
    cin>>n;
    while(n>0){
        arr[c++]=(n&1);
        n=n>>1;
    }
    for(int i=c-1;i>=0;i--) cout<<arr[i];
    return 0;
}