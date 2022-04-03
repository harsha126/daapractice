#include<iostream>
#include<cstring>
using namespace std;
#define SIZE 10

bool isValid(char board[10][10],int x,int y,int n){
    for(int i=0;i<n;i++) if(board[x][i]=='q') return false;
    for(int i=0;i<n;i++) if(board[i][y]=='q') return false;
    int a = x;
    int b = y;
    while(a>0&&b>0) if(board[--a][--b]=='q') return false;
    a = x;
    b = y;
    while(a<n-1&&b<n-1) if(board[--a][++b]=='q') return false;
    a = x;
    b = y;
    while(a>0&&b<n) if(board[--a][++b]=='q') return false;
    a = x;
    b = y;
    while(a<n&&b>0) if(board[++a][--b]=='q') return false;
    return true;
}

// int* findnext(char board[10][10],int n){
//     int arr[2];
//     for(int i=0;i<n;i++){
//         for(int j=0;j<n;j++){
//             if(board[i][j]!='q'){
//                 arr[0]=i;
//                 arr[1]=j;
//                 return arr;
//             }
//         }
//     }
//     return NULL;
// }

bool fillboard(char board[10][10],int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            board[i][j]='_';
        }
    }
    return true;
}

void printBoard(char board[10][10],int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++) cout<<board[i][j]+" ";
        cout<<"\n";
    }
}

bool solve(char board[10][10],int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(isValid(board,i,j,n)){
                board[i][j]='q';
                if (solve(board,n)){
                    return true;
                }
                board[i][j]='_';
            }  
        }
    }
    return true;
    
}

int main(){
    char board[SIZE][SIZE];
    int arr,n;
    cout<<"Enter the no of queens";
    cin>>n;
    bool s = fillboard(board,n);
    // memset( board, 'b', sizeof(board[0][0]) * n * n );
    // for(int i=0;i<n;i++){
    //     memset(board[i],'_',sizeof(board[0][0])*n);
    // }
    printBoard(board,n);
    solve(board,n);
    // printBoard(board,n);
    return 0;
}