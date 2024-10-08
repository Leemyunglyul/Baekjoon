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

int num[310000];
int parent[310000];

int find(int x){
    if(parent[x]==x) return x;
    else return parent[x]=find(parent[x]);
}

void unionn(int x, int y){
    x=find(x);
    y=find(y);
    num[x]+=num[y];
    parent[y]=x;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int n, i, j,k, x, y;
    cin>>k>>n;
    for(i=1;i<=n;i++) parent[i]=i;
    fill_n(&num[0], 310000, 1);
    for(i=1;i<=k;i++){
        cin>>x>>y;
        if(find(x)==find(y)){
            if(num[find(x)]>0){
                num[find(x)]--;
                cout<<"LADICA\n";
            }
            else cout<<"SMECE\n";
        }
        else{
            if(num[find(x)]+num[find(y)]>0){
                unionn(x,y);
                num[find(x)]--;
                cout<<"LADICA\n";
            }
            else cout<<"SMECE\n";
        }
    }
    
    
}
