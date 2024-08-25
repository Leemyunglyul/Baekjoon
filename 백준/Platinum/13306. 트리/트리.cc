#include <iostream>
#include <cmath>
#include <queue>
#include <vector>
#include <tuple>
#include <stack>
#include <set>

using namespace std;

set<int> del;
int edge[200100];
int parent[200100];
stack<bool> st;
stack<tuple<int,int,int>> query;

int find(int x){
    if(parent[x]==x) return x;
    else return parent[x]=find(parent[x]);
}

bool sameparent(int x, int y){
    return find(x)==find(y);
}

void unionn(int x, int y){
    x=find(x);
    y=find(y);
    parent[y]=x;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int n, q,i, x, y, z;
    cin>>n>>q;
    for(i=1;i<=n-1;i++){
        cin>>x;
        edge[i+1]=x;
    }
    for(i=1;i<=n;i++){
        parent[i]=i;
    }
    for(i=1;i<=n-1+q;i++){
        cin>>x;
        if(x==0){
            cin>>y;
            z=1;
        }
        else{
            cin>>y>>z;
        }
        query.push({x, y, z});
    }
    while(!query.empty()){
        x=get<0>(query.top());
        y=get<1>(query.top());
        z=get<2>(query.top());
        query.pop();

        if(x==0){
            parent[y]=find(edge[y]);
        }
        else{
            if(sameparent(y, z)) st.push(true);
            else st.push(false);
        }
    }
    while(!st.empty()){
        bool anw=st.top();
        st.pop();
        if(anw) cout<<"YES\n";
        else cout<<"NO\n";
    }
}