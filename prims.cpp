#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;

    vector<vector<vector<int>>>v(n+1);
    for (int i=0;i<m;i++){
        int p,q,wt;
        cin>>p>>q>>wt;
        v[p].push_back({q,wt});
        v[q].push_back({p,wt});
        // v[]

    }

    set<vector<int>>st;
    vector<int>vis(n+1,0);
    st.insert({0,1,0});//0 wt,1 node ,2 parent
    vector<int>parent(n+1,0);
    vector<int>dis(n+1,INT_MAX);
    dis[1]=0;
    int mst(0);
    while(!st.empty()){
        auto it=*st.begin();
        
        int wt=it[0];
        int p=it[1];
        int q=it[2];
          st.erase(st.begin());
           
           if(vis[p])continue;
        mst+=wt;
        parent[p]=q;
        // dis[p]
     
        vis[p]=1;
        for(auto child:v[p]){
            // if(!vis[child[0]]){  //child h wo basically vector ka {node,wt}  yaani child[0]=node child[1]=wt
            //     // int newt=wt+child[1];
            //  st.insert({child[1],child[0],p});
            // }
            //upar waala h prims ke liye 

            if(dis[child[0]]>=dis[child[1]]+wt){
                dis[child[0]]=dis[child[1]]+wt;
                st.insert({dis[child[0]],child[0],p});
            }
        }

    }
    // for(int i=1;i<=n;i++){
    //  cout<<parent[i]<<"-> "<<i<<" ";
    // } 
    for(int i=1;i<=n;i++){
        cout<<dis[i]<<"->"<<i;
    }
    
    cout<<endl;
    cout<<mst;   
}