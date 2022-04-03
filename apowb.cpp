#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    long long int t=0,a=0,b=0,m=1000000007;
    cin>>t;
    while(t--){
        cin>>a>>b;
        long long int r = 1;
        // cout<<"helloworld"<<endl;
        while(b>0){
            if((b&1)==1) r=(r%m)*(a%m)%m;
            a=(a%m*a%m)%m;
            b=b>>1;
        }
        cout<<r<<endl;
    }
    return 0;
}
