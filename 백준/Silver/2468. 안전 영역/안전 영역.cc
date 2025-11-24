#include <iostream>
#include <cstdio>
#include <cmath>
#include <queue>
#include <stack>
#include <algorithm>
#include <vector>

using namespace std;

int arr[110][110];
bool visited[110][110];
bool safe[110][110];
int n;
queue<pair<int, int>> q;

void down(int x){
    int i, j;
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            if(arr[i][j]<=x) safe[i][j]=false;
        }   
    }
}

void bfs(){
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        if(x>1 && safe[x-1][y] && !visited[x-1][y]){
            q.push({x-1, y});
            visited[x-1][y]=true;
        }
        if(y>1 && safe[x][y-1] && !visited[x][y-1]){
            q.push({x, y-1});
            visited[x][y-1]=true;
        }
        if(x<n && safe[x+1][y] && !visited[x+1][y]){
            q.push({x+1, y});
            visited[x+1][y]=true;
        }
        if(y<n && safe[x][y+1] && !visited[x][y+1]){
            q.push({x, y+1});
            visited[x][y+1]=true;
        }
    }
}

int check(){
    fill_n(&visited[0][0], 110*110, false);
    int i, j, k;
    int anw=1;
    int p;
    for(i=1;i<=100;i++){
        p=0;
        down(i);
        fill_n(&visited[0][0], 110*110, false);
        for(j=1;j<=n;j++){
            for(k=1;k<=n;k++){
                if(safe[j][k] && !visited[j][k]){
                    q.push({j, k});
                    visited[j][k]=true;
                    bfs();
                    p++;
                }
            }
        }
        anw=max(p, anw);
    }
    return anw;
}

void solve(){
    cin>>n;

    int i, j;
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            cin>>arr[i][j];
        }
    }
    fill_n(&visited[0][0], 110*110, false);
    fill_n(&safe[0][0], 110*110, true);

    cout<<check();
}


int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

    solve();
    
}