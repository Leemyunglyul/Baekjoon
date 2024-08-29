#include <iostream>
#include <cmath>
#include <queue>
#include <vector>
#include <tuple>
#include <stack>
#include <set>
#include <algorithm>
#include <string>

using namespace std;

int parent[100100];
int cmp[100100];

int find(int x){
    if(parent[x]==x) return parent[x];
    else{
        int tmp=find(parent[x]);
        cmp[x]+=cmp[parent[x]];
        return parent[x]=tmp;
    }
}

bool sameparent(int x, int y){
    x=find(x);
    y=find(y);
    return x==y;
}

void uni(int x, int y, int z){
    int tx=find(x);
    int ty=find(y);
    cmp[ty]=-cmp[y]+cmp[x]+z;
    parent[ty]=tx;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int n, m, i, j, x, y, z;
    char c;
    while(1){
        cin>>n>>m;
        if(n+m==0) return 0;

        for(i=1;i<=n;i++) parent[i]=i;
        fill_n(&cmp[0], 100100, 0);

        for(i=1;i<=m;i++){
            cin>>c;
            if(c=='!'){
                cin>>x>>y>>z;
                if(!sameparent(x, y)){
                    uni(x,y,z);
                    //cout<<x<<":"<<parent[x].first<<" + "<<parent[x].second<<"\n";
                    //cout<<y<<":"<<parent[y].first<<" + "<<parent[y].second<<"\n";
                }
            }
            else{
                cin>>x>>y;
                if(!sameparent(x, y)){
                    cout<< "UNKNOWN\n";
                }
                else{
                    //cout<<x<<" &&& "<<y<<endl;
                    cout<<cmp[y]-cmp[x]<<"\n";
                }
            }
        }
    }

}