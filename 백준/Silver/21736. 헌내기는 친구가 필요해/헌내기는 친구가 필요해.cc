#include <iostream>
#include <cmath>
#include <queue>
#include <vector>
#include <string>

using namespace std;

int arr[610][610];
bool visited[610][610];
int row[4]={-1, 0, 1, 0};
int col[4]={0, -1, 0, 1};
queue<pair<int, int>> q;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n, m,i,j, a, b;
    char x;
    cin>>n>>m;
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            cin>>x;
            if(x=='O');
            else if(x=='P') arr[i][j]=1;
            else if(x=='X') arr[i][j]=-1;
            else{
                a=i;
                b=j;
            } 
        }
    }
    int sum=0;
    q.push({a, b});
    fill_n(&visited[0][0], 610*610, false);
    visited[a][b]=true;
    while(!q.empty()){
        int r=q.front().first;
        int c=q.front().second;
        q.pop();

        for(i=0;i<=3;i++){
            int r2=r+row[i];
            int c2=c+col[i];
            if(r2<1 || r2>n || c2<1 || c2>m) continue;
            if(arr[r2][c2]==-1 || visited[r2][c2]) continue;
            visited[r2][c2]=true;
            q.push({r2,c2});
            if(arr[r2][c2]==1) sum++;
        }
    }
    if(sum==0) cout<<"TT";
    else cout<<sum;
}