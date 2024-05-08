#include <bits/stdc++.h>
// const N=1e5;
using namespace std;

const int N = 1e5; // Correct declaration of the constant

int pr[N];
int sz[N];
void make(int n){
    for(int i=0;i<n;i++){
        pr[i]=i;
        sz[i]=1;
    }
}
int  find(int node){
    if(pr[node]==node)return node;
    return pr[node]=find(pr[node]);
}
void unin(int a,int b){
    a=find(a);
    b=find(b);
    if(a!=b){
        if(sz[a]<sz[b])swap(a,b);
        pr[b]=a;
        sz[a]+=sz[b];
    }
}
int main(){

int n,m;
cin>>n>>m;
vector<vector<int>>v;
// (n,vector<int>());
for(int i=0;i<m;i++){
    int p,q,wt;
    cin>>p>>q>>wt;
    v.push_back({wt,p,q});
}
make(n);
int mswt(0);
sort(v.begin(),v.end());
for(auto &it:v){
    int wt=it[0];
    int p=it[1];
    int q=it[2];
    if(find(p)!=find(q)){
        cout<<p<<"->"<<q;
        cout<<endl;
        unin(p,q);
        mswt+=wt;
    }

}
cout<<"total weight for minimum spanning tree"<<mswt<<endl;







    return 0;
}