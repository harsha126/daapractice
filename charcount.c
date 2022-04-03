#include<stdio.h>
#include<conio.h>
#include<string.h>
void main(){
    char in[50],out[50],c[20][20],ch;
    int inlen,outlen,i,j,count=-1,k=0,count1=0,row,col,z;
    for(i=0;i<50;i++){ in[i]='\0'; out[i]='\0';}
    for(i=0;i<50;i++) for(j=0;j<50;j++) c[i][j]=='\0';
    // clrscr();
    printf("\nenter thr string : "); gets(in);
    printf("\nentered string is %s:",in);
    inlen=strlen(in);
    printf("\nlength of  string is %d:", inlen);
    for(i=0,ch=in[i];ch!='\0';++i,ch=in[i]){
        if(ch==' '){
            count++;
            if(count==0) for(j=0;j<=i;j++) c[count][j]=in[j];
            else{
                while (count1<=count)
                {
                    k=k+strlen(c[count1]);
                    count1++;
                }
                for(j=0;k<=i;j++,k++) c[count][j]=in[k];
                
            }
        }
    }

    printf("\n\t before changing");
    for(i=0;i<=count;i++){
        printf("\n%s\tlen: %d",c[i],strlen(c[i]));
    }
    printf("\n\t after changing");
    for (i = 0; i <= count; i++)
    {
        for(j=strlen(c[i]);j>0;j--) c[i][j]=c[i][j-1];
        c[i][0]=strlen(c[i])+48;
    }
    for(i=0;i<=count;i++){
        printf("\n%s\tlen: %d",c[i],strlen(c[i]));
    }
    printf("\noutput array");
    for(row=0,z=0;row<=count;row++){
        for(col=0,ch=c[row][col];ch!='\0';col++,ch=c[row][col],z++) out[z]=ch;
    }
    printf("%s",out);
    outlen=strlen(out);
    printf("\nlength: %d",outlen);
    // getch();
}