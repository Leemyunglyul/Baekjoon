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

int team[1010000];
int edge[1010000][32];
int parent[110000];
int num[110000];
queue<int> qq;

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
    
    int n, i,k, x, y, anw, a, b,q,z, j;
    cin>>n>>q>>k;
    for(i=1;i<=n;i++){
        parent[i]=i;
        num[i]=1;
        team[i]=i;
        edge[i][i%q]=i;
    }
    for(i=n+1;i<=1000000;i++) qq.push(i);
    for(i=1;i<=k;i++){
        cin>>z>>x;
        if(z==2){
            cin>>y;
            a=team[find(x)];
            if(edge[a][y]==0) continue;
            b=qq.front();
            qq.pop();
            edge[b][y]=edge[a][y];
            team[edge[b][y]]=b;
            edge[a][y]=0;
        }
        else if(z==1){
            cin>>y;
            a=team[find(x)];
            b=team[find(y)];
            if(a==b) continue;

            for(j=0;j<q;j++){
                if(edge[b][j]==0) continue;
                if(edge[a][j]==0){
                    edge[a][j]=edge[b][j];
                    team[edge[a][j]]=a;
                    edge[b][j]=0;
                }
                else{
                    num[edge[a][j]]+=num[edge[b][j]];
                    unionn(edge[a][j], edge[b][j]);
                    edge[b][j]=0;
                }
            }
            qq.push(b);

        }
        else{
            x=team[find(x)];
            for(j=0, anw=0;j<q;j++){
                if(edge[x][j]==0) continue;
                anw+=num[edge[x][j]];
            }
            cout<<anw<<"\n";
        }
        
    }
}
