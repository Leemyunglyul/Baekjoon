#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <string>

using namespace std;

int arr[6][6];
set<string> st;

void dfs(int x, int y, int depth, string num) {
    if(depth == 6) {
        st.insert(num);
        return;
    }

    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    for(int dir=0; dir<4; dir++) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];

        if(nx >= 0 && nx < 5 && ny >= 0 && ny < 5) {
            dfs(nx, ny, depth + 1, num + to_string(arr[nx][ny]));
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, i, j, x,y;

    for(i=0;i<5;i++)
        for(j=0;j<5;j++)
            cin>>arr[i][j];

    for(i=0;i<5;i++) {
        for(j=0;j<5;j++) {
            dfs(i, j, 1, to_string(arr[i][j]));
        }
    }
    cout<<st.size()<<"\n";

    return 0;
}