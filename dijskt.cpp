#include<bits/stdc++.h>
using namespace std;

int main(){
int n,m;
cin>>n>>m;
vector<vector<vector<int>>>v(n);
for(int i=0;i<m;i++){
    int p,q,wt;
    cin>>p>>q>>wt;
    v[p].push_back({wt,q});
    v[q].push_back({wt,p});
}
set<vector<int>>st;
st.insert({0,0,0});
vector<int>dis(n,INT_MAX);
dis[0]=0;
while(!st.empty()){
    int wt=it[0];
    int p=it[1];
    int q=it[2];
    st.erase(st.begin());
    for(auto it:v[p]){
        if(dis[it[1]]>=wt+it[0]){
            dis[it[1]]=wt+it[0];
            st.insert({dis[it[1]],it[1],p});
        }
    }
}
for(int i=0;i<n;i++){
    cout<<i<<"->"<<dis[i];
}






    return 0;
}