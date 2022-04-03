#include<iostream>
#include <bits/stdc++.h>
using namespace std;
int main(){
    int h=0,g=0;
    int arr[10];
    int n=10;
    for(int i=0;i<10;i++) arr[i]=rand();
    cout<<arr;
    sort(arr,arr+4);
    for(int i=0;i<n/2;i++) h+=arr[i];
    for(int i=n/2;i<n;i++) g+=arr[i];
    cout<<(g-h);
    return 0;
}