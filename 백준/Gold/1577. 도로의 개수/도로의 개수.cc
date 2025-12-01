#include <iostream>
#include <cstdio>
#include <cmath>
#include <queue>
#include <stack>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

using namespace std;

using ll = unsigned long long;

ll n, m, k;
set<pair<pair<ll, ll>, pair<ll, ll>>> no;
unsigned long long arr[110][110]={0};

void solve(){
    int i, j;

    cin>>n>>m>>k;

    for(i=0; i<k; i++){
        int u, v, w, x;
        cin>>u>>v>>w>>x;
        no.insert({{u, v}, {w, x}});
        no.insert({{w, x}, {u, v}});
    }

    // N 가로, M 세로 [M][N]
    arr[0][0]=1;
    for(j=0;j<=m;j++){
        for(i=0;i<=n;i++){
            if(j==0 && i==0) continue;

            if(i>0 && no.find({{i-1, j}, {i, j}})==no.end()){
                arr[j][i]+=arr[j][i-1];
            }
            if(j>0 && no.find({{i, j-1}, {i, j}})==no.end()){
                arr[j][i]+=arr[j-1][i];
            }
        }
    }
    cout<<arr[m][n]<<"\n";
}


int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);

    solve();
    
    return 0;
}