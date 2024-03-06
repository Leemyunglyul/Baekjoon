#include <iostream>
#include<math.h>
#include<algorithm>
#include<queue>
#include<stack>

using namespace std;

int board[30][30], n, color;
bool visited[30][30];
int gr, gc, gnum, score, rb;

void bfs_find(int r, int c) {
    queue<pair<int, int>> q;
    q.push({ r, c });
    visited[r][c] = true;
    int gsum = 0;
    int resultr = n+2;
    int resultc = n+2;
    int rbn = 0;
    int cc = board[r][c];
    vector<pair<int, int>> visit0;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        
        q.pop();
        gsum++;
        if (board[x][y] == 0);
        else if (x < resultr || (x == resultr && y < resultc)) {
            resultr = x;
            resultc = y;
        }

        if (x > 1) {
            if (cc == board[x - 1][y] && !visited[x-1][y]) {
                visited[x - 1][y] = true;
                q.push({ x - 1, y });
            }
            else if (board[x - 1][y] == 0 && !visited[x - 1][y]) {
                visited[x - 1][y] = true;
                q.push({ x - 1, y });
                visit0.push_back({ x - 1,y });
            }
           
        }
        if (y > 1) {
            if (cc == board[x][y-1] && !visited[x ][y-1]) {
                visited[x][y-1] = true;
                q.push({ x, y - 1 });
            }
            else if (board[x][y-1] == 0 && !visited[x][y-1]) {
                visited[x][y-1] = true;
                q.push({ x, y-1 });
                visit0.push_back({ x,y-1 });
            }
        }
        if (x < n ) {
            if (cc == board[x +1][y] && !visited[x + 1][y]) {
                visited[x + 1][y] = true;
                q.push({ x + 1, y });
            }
            else if (board[x + 1][y] == 0 && !visited[x + 1][y]) {
                visited[x + 1][y] = true;
                q.push({ x + 1, y });
                visit0.push_back({ x + 1,y });
            }
        }
        if (y < n) {
            if (cc == board[x][y+1] && !visited[x][y + 1]) {
                visited[x][y+1] = true;
                q.push({ x , y + 1 });
            }
            else if (board[x][y + 1] == 0 && !visited[x][y + 1]) {
                visited[x][y + 1] = true;
                q.push({ x, y + 1 });
                visit0.push_back({ x,y + 1 });
            }
        }
    }
    int i;
    for (i = 0, rbn=visit0.size(); i < visit0.size(); i++) {
        visited[visit0[i].first][visit0[i].second] = false;
    }
    if (gsum > gnum || (gsum == gnum && rbn>rb ) || (gsum == gnum && rbn == rb && resultr>gr)
        || (gsum == gnum && rbn == rb && resultr == gr && resultc > gc)) {
        gnum = gsum;
        gr = resultr;
        gc = resultc;
        rb = rbn;
    }
}

void big_remove() {
    queue<pair<int, int>> q;
    fill_n(&visited[0][0], 30 * 30, false);
    q.push({ gr, gc });
    int cc = board[gr][gc];
    visited[gr][gc] = true;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        
        q.pop();

        if (x > 1) {
            if (cc == board[x - 1][y] && !visited[x - 1][y]) {
                visited[x - 1][y] = true;
                q.push({ x - 1, y });
            }
            else if (board[x - 1][y] == 0 && !visited[x - 1][y]) {
                visited[x - 1][y] = true;
                q.push({ x - 1, y });
            }

        }
        if (y > 1) {
            if (cc == board[x][y - 1] && !visited[x][y - 1]) {
                visited[x][y - 1] = true;
                q.push({ x, y - 1 });
            }
            else if (board[x][y - 1] == 0 && !visited[x][y - 1]) {
                visited[x][y - 1] = true;
                q.push({ x, y - 1 });
            }
        }
        if (x < n) {
            if (cc == board[x + 1][y] && !visited[x + 1][y]) {
                visited[x + 1][y] = true;
                q.push({ x + 1, y });
            }
            else if (board[x + 1][y] == 0 && !visited[x + 1][y]) {
                visited[x + 1][y] = true;
                q.push({ x + 1, y });
            }
        }
        if (y < n) {
            if (cc == board[x][y + 1] && !visited[x][y + 1]) {
                visited[x][y + 1] = true;
                q.push({ x , y + 1 });
            }
            else if (board[x][y + 1] == 0 && !visited[x][y + 1]) {
                visited[x][y + 1] = true;
                q.push({ x, y + 1 });
            }
        }
        board[x][y] = -2;
    }
}

bool big_group() {
    gr = n+1;
    gc = n+1;
    gnum = 1;
    rb = 0;
    int i, j;
    fill_n(&visited[0][0], 30 * 30, false);
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            if (visited[i][j] || board[i][j] <= 0) continue;
            bfs_find(i, j);
        }
    }
    if (gnum == 1 && gr == n+1 && gc == n+1) return false;
    else {
        score += gnum * gnum;
        return true;
    }
    
}

void gravity() {
    int i, j, brake, k;
    for (i = 1; i <= n; i++) {//열
        stack<int> st;
        for (j = 1, brake=1; j <= n; j++, brake++) {//행
            if (board[j][i] == -1) {
                for (k = brake - 1; !st.empty(); k--) {
                    board[k][i] = int(st.top());
                    st.pop();
                }
                continue;
            }
            if (board[j][i] == -2) continue;
            st.push(board[j][i]);
            board[j][i] = -2;
        }
        for (k = brake - 1; !st.empty(); k--) {
            board[k][i] = st.top();
            st.pop();
        }
    }
}

void rot() {
    int i, j;
    int temp[30][30];
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            temp[i][j] = board[i][j];
        }
    }
    for (j = n; j >= 1; j--) {//원래 열
        for (i = 1; i <= n; i++) {//원래 행
            board[n + 1 - j][i] = temp[i][j];
        }
    }
}

void print() {
    int i, j;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            if (board[i][j] == -2) cout << "_" << " ";
            else if (board[i][j] == -1) cout << "-1";
            else cout << board[i][j]<<" ";
        }cout << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> n >> color;
    int i, j;
    for (i = 1, score=0; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            cin >> board[i][j];
        }
    }
    i = 0;
    while (big_group()) {
        //cout << i << "없애기전" << endl;
        //print();
        big_remove();
        //cout << i<<"없앤 후" << endl;
        //print();
        gravity();
        //cout << i <<"중력" << endl;
        //print();
        rot();
        //cout << i << "회전" << endl;
       // print();
        gravity();
        //cout << i++<<"회전 후 중력" << endl;
        //print();
        //cout << endl << endl;
    }
    cout << score;
}
