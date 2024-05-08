#include <bits/stdc++.h>
using namespace std;
void print(vector<vector<char>>&bd){
    for(auto it:bd){
       for(auto t:it){
        cout<<t<<" ";
       }
       cout<<endl;
    }
    
}
int main(){
    int n;
    cin>>n;
    vector<vector<char>>bd(n,vector<char>(n,'.'));
    print(bd);
}