#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <string>
#include <stack>
#include <map>
#include <regex>
#include <queue>

using namespace std;

int arr[10][10];
int dp[10][10];

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

struct ant{
    int x, y, hp, time;
};



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int r, c, i, j, i1, i2, e1, e2, x, y, hp, t, anw, next_hp;

    while(1){
        cin>>c>>r;
        if(r==0 && c==0) break;

        queue<ant> q;

        fill_n(&dp[0][0], 100, 0);
        anw = -1;
        for(i=1;i<=r;i++){
            for(j=1;j<=c;j++){
                cin>>arr[i][j];
                if(arr[i][j]==2){
                    i1 = i, i2 = j;
                    dp[i][j] = 0;
                }
            }
        }

        q.push({i1, i2, 6, 0});
        dp[i1][i2] = 6;

        while(!q.empty()){
            x = q.front().x;
            y = q.front().y;
            hp = q.front().hp;
            t = q.front().time;
            q.pop();

            if(arr[x][y]==3){
                anw = t;
                break;
            }

            if(hp <= 1) continue;
            
            for(i=0;i<4;i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                next_hp = hp - 1;

                if(nx<1 || nx>r || ny<1 || ny>c) continue;

                //웅덩이
                if(arr[nx][ny]==0) continue;

                if(arr[nx][ny]==4){
                    next_hp = 6;
                }

                // 갱신
                if(next_hp > dp[nx][ny]){
                    dp[nx][ny] = next_hp;
                    q.push({nx, ny, next_hp, t+1});
                }
            }

        }

        cout<<anw<<"\n";

    }
    
    return 0;
}