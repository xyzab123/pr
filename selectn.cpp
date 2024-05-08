#include <bits/stdc++.h>
using namespace std;
int main(){
int n;
cin>>n;
vector<int>v(n);

for(int i=0;i<n;i++)cin>>v[i];
int re(0);
for(int i=0;i<n;i++){
    int sm(INT_MAX);
    cout<<"sm"<<sm;
    for(int j=i;j<n;j++){
        if(v[j]<sm){
            sm=v[j];
            re=j;
        }
    }
    cout<<sm<<endl;
    swap(v[i],v[re]);
    // v[i]=sm;
}
for(int i=0;i<n;i++)cout<<v[i]<<" ";






}