#include<iostream>
using namespace std;
int arr[] = {12,45,32,15,19,8};
void swap(int i,int j){
    int temp=arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
}
int main(){
    int j,k;
    for(int i=1;i<6;i++){
        j=i-1;
        k=i;
        while(arr[k]<=arr[j]&&k>=0&&j>=0){
            swap(k,j);
            k--;
            j--;
        }
    }   
    for(auto i : arr) cout<< i <<',';
    return 0;
}