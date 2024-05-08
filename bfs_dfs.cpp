#include <bits/stdc++.h>
using namespace std;
void bfs(){
  queue<int>q;
  q.push(node);
  vi[node]=1;
  while(!q.empty()){
    int f=q.front();
    q.pop();
    cout<<f<<" ";
    for(auto it:v[f]){
        if(!vi[it]){
            q.push(it);

        }
    }
  }
}
void dfs(vector<int>&vi,vector<vector<int>>&v,int node){
    vi[node]=1;
    cout<<node<<" ";
    for(auto it:v[node]){
        if(!vi[it]){
            dfs(vi,v,it);
    }
}
}
int main(){
int n,m;
cin>>n>>m;
vector<vector<int>>v(n,vector<int>());
// vector<int>v[n];
for(int i=0;i<m;i++){
    int x,y;
    cin>>x>>y;
    v[x].push_back(y);
    v[y].push_back(x);
}
for(int i=0;i<n;i++){
  for(auto it:v[i]){
    cout<<it<<" "<<i;
  }
}

vector<int>vi(n,0);
for(int i=0;i<n;i++){
    if(!vi[i])
dfs(vi,v,i);
}







    return 0;
}