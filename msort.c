#include<stdio.h>
#include<conio.h>

void merge(int arr[],int low,int mid,int high){
    int i=low,j=mid+1,brr[high-low+1],k=0,m;
    while(i<=mid&&j<=high){
        if(arr[i]<=arr[j]) brr[k++]=arr[i++];
        else brr[k++]=arr[j++];
    }
    while(i<=mid) brr[k++]=arr[i++];
    while(j<=high) brr[k++]=arr[j++];
    for(m=low,k=0;m<=high;m++){
        arr[m]=brr[k++];
    }
    return;
}

void msort(int arr[],int low,int high){
    int mid=(low+high)/2;
    if(low<high){
        msort(arr,low,mid);
        msort(arr,mid+1,high);
        merge(arr,low,mid,high);
    }
    return;
}


void main(){
    int arr[]={23,54,-1,76,1,34,56,65,212,431,-231,5456,555,67,89};
    int len=15;
    printf("before sorting ");
    for(int i=0;i<len;i++) printf("%d,",arr[i]);
    printf("\nafter sorting");
    msort(arr,0,len-1);
    for(int i=0;i<len;i++) printf("%d,",arr[i]);
    return;
}