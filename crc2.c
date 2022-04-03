#include<conio.h>
#include<string.h>
#include<stdio.h>
void main(){
    int i,j,inlen,genlen,msglen=0,flag=0,outlen=0;
    char in[50],gen[50],crc[50],msg[50],out[50];
    for(i=0;i<30;i++) { 
        crc[i]='\0';
        in[i] = '\0';
        gen[i] = '\0';
        msg[i] = '\0';
        out[i] = '\0';
    }
    printf("Enter the data bits :");
    gets(in);
    strcpy(msg,in);
    inlen=strlen(in);
    printf("\nEnter the generator bits :");
    gets(gen);
    genlen=strlen(gen);
    for(i=inlen;i<inlen+genlen-1;i++) in[i]='0';
    printf("\nThe data bits after appending 0s :");
    puts(in);
    inlen=strlen(in);
    for ( i = 0; i <=inlen-genlen;)
    {
        for(j=0;j<genlen;j++){
            in[i+j]=(in[i+j]==gen[j])?'0':'1';
        }
        while(in[i]=='0'&&i<inlen) i++;
    }
    for(i=inlen-genlen+1,j=0;i<inlen;i++,j++) crc[j]=in[i];
    printf("\nthe crc is : %s",crc);
    strcat(msg,crc);
    printf("\nThe data to be sent is : %s",msg);    
    printf("\n At the reciever side :");
    printf("\n Enter the data at the reciever side : ");
    gets(out);
    outlen=strlen(out);
    for (i = 0; i <= outlen - genlen;)
    {
        for (j = 0; j < genlen; j++)
        {
            out[i + j] = (out[i + j] == gen[j]) ? '0' : '1';
        }
        while (out[i] == '0' && i < outlen) i++;
    }
    for (i = outlen - genlen + 1, j = 0; i < outlen; i++, j++)
        {
            crc[j] = out[i];
            if(crc[j]==1) {flag = 1; break;}
        }
    if(!flag) printf("\nthe crc is : %s", crc);
    else printf("\nThere is an error");
}
