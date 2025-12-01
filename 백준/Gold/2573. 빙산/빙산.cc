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

int arr[310][310];
int go[310][310];
int n, m;

void calc(){
    int i,j;
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            go[i][j]= 0;
            if(i>1 && arr[i-1][j]==0) go[i][j]--;
            if(i<n && arr[i+1][j]==0) go[i][j]--;
            if(j>1 && arr[i][j-1]==0) go[i][j]--;
            if(j<m && arr[i][j+1]==0) go[i][j]--;
        }
    } 
}

void melt(){
    calc();
    int i,j;
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            arr[i][j]+=go[i][j];
            if(arr[i][j]<0) arr[i][j]=0;
        }
    }
}

int check(){
    int i, j;
    queue<pair<int, int>> q;
    bool visited[310][310]={false,};
    int cnt=0;

    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            if(arr[i][j]>0 && visited[i][j]==false){
                cnt++;
                q.push({i,j});
                visited[i][j]=true;

                while(!q.empty()){
                    pair<int, int> cur= q.front();
                    q.pop();

                    int x= cur.first;
                    int y= cur.second;

                    if(x>1 && arr[x-1][y]>0 && visited[x-1][y]==false){
                        visited[x-1][y]=true;
                        q.push({x-1, y});
                    }
                    if(x<n && arr[x+1][y]>0 && visited[x+1][y]==false){
                        visited[x+1][y]=true;
                        q.push({x+1, y});
                    }
                    if(y>1 && arr[x][y-1]>0 && visited[x][y-1]==false){
                        visited[x][y-1]=true;
                        q.push({x, y-1});
                    }
                    if(y<m && arr[x][y+1]>0 && visited[x][y+1]==false){
                        visited[x][y+1]=true;
                        q.push({x, y+1});
                    }
                }
            }
        }
    }
    return cnt;
}

void solve(){
 
    int i, j;
    cin>>n>>m;

    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            cin>>arr[i][j];
        }
    }

    int year=0;
    while(1){
        year++;
        melt();
        int parts= check();
        if(parts>=2){
            cout<<year<<"\n";
            break;
        }
        else if(parts==0){
            cout<<"0\n";
            break;
        }
    }

}


int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);

    solve();
    
    return 0;
}