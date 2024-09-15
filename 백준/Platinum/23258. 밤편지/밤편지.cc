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

using namespace std;

int arr[302][302][302];
int big=987654321;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n, i, k, j, q, x, y, z;
    cin>>n>>q;
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            cin>>x;
            if(i==j) continue;
            arr[i][j][0]=(x==0)?big:x;
        }
    }
    for(k=1;k<=n;k++){
        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++){
                arr[i][j][k]=min(arr[i][j][k-1], arr[i][k][k-1]+arr[k][j][k-1]);
            }
        }
    }
    while(q--){
        cin>>x>>y>>z;
        if(arr[y][z][x-1]==big) cout<<"-1\n";
        else cout<<arr[y][z][x-1]<<"\n";
    }
}

/*
for(i=1;i<=n;i++){
        
}
*/