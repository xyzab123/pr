#include<bits/stdc++.h>
using namespace std;


void print( vector<vector<char>>board){
    cout<<endl;
    for(auto it:board){
        for(auto t:it){
            cout<<t<<" ";
        }
        cout<<endl;
    }

}

bool safe(vector<vector<char>> & board ,int row,int col){
    for(int i=0;i<row;i++){
        if(board[i][col]=='Q')return false;
    }
    for(int i=row-1,j=col-1;i>=0 && j>=0;i--,j--){
        if(board[i][j]=='Q')return false;
    }
    for(int i=row-1,j=col+1;i>=0 && j<board.size();i--,j++){
        if(board[i][j]=='Q')return false;
    }
    return true;
}

void nqueen(vector<vector<char>> & board ,int row){
    if(row==board.size()){
        print(board);
        
    }
    for(int col=0;col<board.size();col++){
        if(safe(board,row,col)){
            board[row][col]='Q';
            nqueen(board,row+1);
            board[row][col]='.';
        }
    }
}


int main(){
    int n;
    cin>>n;
    vector<vector<char>>board(n,vector<char>(n,'.'));
    // print(board);
    nqueen(board,0);

}