#include <iostream>
#include <cmath>
#include <queue>
#include <vector>
#include <tuple>
#include <stack>
#include <set>
#include <algorithm>
#include <string>
#include <map>
#include <unordered_map>
typedef long long ll;

using namespace std;

int out[310000];
bool go[310000];
int parent[310000];
vector<pair<int, int>> query;
stack<int> print;

int find(int x){
    if(parent[x]==x) return x;
    else return parent[x]=find(parent[x]);
}

void unionn(int x, int y){
    x=find(x);
    y=find(y);
    parent[y]=x;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int n, i, j,k, x, y, a, b;
    cin>>n;
    for(i=1;i<=n;i++) cin>>out[i];
    for(i=1;i<=n;i++) parent[i]=i;
    cin>>k;
    fill_n(&go[0], 310000, true);
    for(i=0;i<k;i++){
        cin>>x>>y;
        query.push_back({x,y});
        if(x==2) go[y]=false;
    }
    for(i=1;i<=n;i++){
        if(go[i] && out[i]>0){
            x=i;
            y=out[i];
            if(find(y)==find(x)){
                parent[x]=0;
            }
            else unionn(y, x);
                
        }
    }
    for(i=k-1;i>=0;i--){
        a=query[i].first;
        b=query[i].second;
        if(a==1)print.push(find(b));
        else{
            if(out[b]==0) continue;
            x=b;
            y=out[b];
            if(find(y)==find(x)){
                parent[x]=0;
            }
            else unionn(y, x);
        }
    }
    while(!print.empty()){
        if(print.top()==0) cout<<"CIKLUS\n";
        else cout<<print.top()<<"\n";
        print.pop();
    }
}
