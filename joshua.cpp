#include<iostream>
#include<vector>
#include<map>
#include<cstdlib>
using namespace std;

int check(int n){
    int mod = 1000000000+7;
    int ans = ((n%mod)*(n+1)%mod)/2;
    return ans;
}

int solve(int N,string str){
    vector<int> vec1;
    int mod = 1000000000+7;
    int ans = 0;
    for(int i = 0; i < str.length();i++){
        if(str[i]=='1') vec1.push_back(i);
    }
    for(int i : vec1) cout<<i<<"\n";
    if(vec1.size()==0) return 0;
    for(int i = 0;i<vec1.size()-1;i++){
        if(vec1[i]==0){
            ans = ans + ((vec1[1]%mod)*(vec1[1]+1)%mod/2)%mod;
        }
        else {
            int p1 = vec1[i];
            int p2 = vec1[i+1];
            int k = (p1+p2)/2;
            ans = ans + (check(k-p1) + check(p2-k))%mod;
        }
    }
    return ans;
}

int main(){
    string str = "1010";
    cout<<solve(10,str);
}