#include <iostream>
#include <cmath>
#include <queue>
#include <vector>
#include <tuple>
#include <stack>
#include <set>
#include <algorithm>

using namespace std;

set<int> list[100100];
int edge[100100];
int parent[100100];
int color[100100];
stack<int> st;
stack<pair<int,int>> query;

int find(int x){
    if(parent[x]==x) return x;
    else return parent[x]=find(parent[x]);
}

/*bool sameparent(int x, int y){
    return find(x)==find(y);
}

void unionn(int x, int y){
    x=find(x);
    y=find(y);
    parent[y]=x;
}*/

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int n, q,i, x, y, z;
    cin>>n>>q;
    for(i=1;i<=n-1;i++){
        cin>>x;
        edge[i+1]=x;
    }
    for(i=1;i<=n;i++){
        cin>>color[i];
        list[i].insert(color[i]);
    }
    for(i=1;i<=n;i++){
        parent[i]=i;
    }
    for(i=1;i<=n-1+q;i++){
        cin>>x>>y;
        query.push({x, y});
    }
    while(!query.empty()){
        x=query.top().first;
        y=query.top().second;
        query.pop();

        if(x==1){
            int t1=find(y); int t2=find(edge[y]);
            if(list[t2].size()>list[t1].size()) swap(t1, t2);
            parent[t2]=t1;
            for(auto it=list[t2].begin();it!=list[t2].end();it++)
                list[t1].insert(*it);
            list[t2].clear();
        }
        else{
            st.push(list[find(y)].size());
        }
    }
    while(!st.empty()){
        cout<<st.top()<<"\n";
        st.pop();
    }
}