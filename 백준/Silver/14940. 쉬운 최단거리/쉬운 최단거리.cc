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

int arr[1010][1010];
int num[1010][1010];
int row[4]={-1, 0, 1, 0};
int col[4]={0, -1, 0, 1};
queue<tuple<int, int, int>> q;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int n, m, i, j;
    cin>>n>>m;
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            cin>>arr[i][j];
            if(arr[i][j]==2) q.push({0, i, j});
        }
    }
    while(!q.empty()){
        int nun=get<0>(q.front());
        int r=get<1>(q.front());
        int c=get<2>(q.front());
        q.pop();
        
        for(i=0;i<=3;i++){
            int r2=r+row[i];
            int c2=c+col[i];

            if(arr[r2][c2]!=1 || num[r2][c2]>0) continue;
            num[r2][c2]=nun+1;
            q.push({nun+1, r2, c2});
        }
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            if(arr[i][j]==1 && num[i][j]==0) cout<<"-1 ";
            else cout<<num[i][j]<<" ";
        }
        cout<<"\n";
    }
}
