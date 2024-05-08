#include<bits/stdc++.h>
using namespace std;
int main(){
int n,m;
cin>>n>>m;
vector<int>v[n];
for(int i=0;i<m;i++){
    int p,q;
    cin>>p>>q;
    v[p].push_back(q);
    v[q].push_back(p);
}

set<int>st;
vector<int>re(n,-1);
vector<int>us(n,0);
re[0]=0;
// us[0]=1;
st.insert(0);
for(int i=1;i<n;i++){
    for(auto it:v[i]){
        if(re[it]!=-1)us[re[it]]=1;
    }
    int col;
    for(col=0;col<n;col++){
        if(!us[col])break;

    }
    re[i]=col;
    u[i]=1;
    st.insert(col);
      for(auto it:v[i]){
        if(re[it]!=-1)us[re[it]]=0;
    }

}
for(int i=0;i<n;i++){
    cout<<i<<"-> "<<re[i];
}
cout<<endl;
cout<<"min"<<endl;
cout<<st.size();
}