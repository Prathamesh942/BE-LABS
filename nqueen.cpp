#include<bits/stdc++.h>
using namespace std;

void printBoard(vector<vector<int>> board){
    int n=board.size();
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(board[i][j]==0){
                cout<<" - ";
            }else{
                cout<<" Q ";
            }
        }
        cout<<"\n";
    }
    cout<<"\n";
}

bool safe(vector<vector<int>>& board, int x, int y){
    int n=board.size();
    for(int i=y+1; i<n; i++) if(board[x][i]) return false;
    for(int i=y-1; i>=0; i--) if(board[x][i]) return false;
    for(int i=x+1; i<n; i++) if(board[i][y]) return false;
    for(int i=x-1; i>=0; i--) if(board[i][y]) return false;

    int tx=x-1,ty=y+1;
    while(tx>=0 && ty<n){
        if(board[tx][ty]) return false;
        tx-=1;
        ty+=1;
    }
    tx=x+1,ty=y+1;
    while(tx<n && ty<n){
        if(board[tx][ty]) return false;
        tx+=1;
        ty+=1;
    }
    tx=x-1,ty=y-1;
    while(tx>=0 && ty>=0){
        if(board[tx][ty]) return false;
        tx-=1;
        ty-=1;
    }
    tx=x+1,ty=y-1;
    while(tx<n && ty>=0){
        if(board[tx][ty]) return false;
        tx+=1;
        ty-=1;
    }
    return true;
}

bool nqueen(vector<vector<int>>& board,int c,int x,int y){
    int n=board.size();
    if(c==n) return true;
    if(c==y){
        if(safe(board,x,y)){
            return nqueen(board,c+1,x,y);
        }else{
            return false;
        }
    }else{
        for(int i=0; i<n; i++){
            if(safe(board,i,c)){
                board[i][c] = 1;
                if(nqueen(board,c+1,x,y)) return true;
                board[i][c] = 0;
            }
        }
    }
    return false;
}

int main(){
    int n=4;
    vector<vector<int>> board(n, vector<int> (n,0));
    int x=0,y=2;
    board[x][y] = 1;
    printBoard(board);
    if(nqueen(board,0,x,y)){
        printBoard(board);
    }else{
        printBoard(board);
        cout<<"Not possible to place queen";
    }
}