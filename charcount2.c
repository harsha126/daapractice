#include <stdio.h>
#include <conio.h>
#include<string.h>
int main(){
    char a[100];
    int j,i;
    for(int i=0;i<100;i++) a[i]='\0';
    printf("Enter the string:") ;
    gets(a) ;
    int lrn=strlen(a);
    int n1=lrn;
    int size=0;

    while(lrn>0){
        size++;
        lrn = lrn / 10;
    }
    n1=n1+size;
    printf("\nsize: %d",size);
    for (i = 0; i<size; i++)
    {
        puts(a);
        for (j = strlen(a) - 1 ; j >= 0; j--)
        {
            a[j + 1] = a[j];
        }
        a[0] = (n1 % 10) + '0';
        n1 /= 10;
    }
    // a[strlen(a)] = '\0';
    printf("\nsize: %d\n", strlen(a));
    puts(a);
}
