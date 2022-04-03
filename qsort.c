 #include<stdio.h>
#include<conio.h>
int part(int a[],int low,int high);
void swapi(int *i,int *j);
void qsort(int a[],int low,int high){
    int pi;
    if(low<high){
        pi=part(a,low,high);
        qsort(a,low,pi-1);
        qsort(a,pi+1,high);
    }
}

int part(int a[], int low,int high){
    int pivot = a[high],i=low-1,j;
    for(j=low;j<high;j++){
        if(a[j]<pivot){
            i++;
            swapi(a+i,a+j);
        }
    }
    swapi(a+i+1,a+high);
    return i+1;
}

void swapi(int *i,int*j){
    int temp = *i;
    *i=*j;
    *j=temp;
}

void main(){
    int n,i,a[100];
    printf("Enter the size of the array :");
    scanf("%d",&n);
    for ( i = 0; i < n; i++)
    {
        scanf("%d",&a[i]);
    }
    printf("\nbefore sorting.......\n");
    for ( i = 0; i < n; i++)
    {
        printf("%d,",a[i]);
    }
    qsort(a,0,n-1);
    printf("\nAfter sorting.......\n");
    for ( i = 0; i < n; i++)
    {   
        printf("%d,",a[i]);
    }
    // getch();
    

}