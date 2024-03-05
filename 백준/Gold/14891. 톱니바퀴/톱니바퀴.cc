#include <iostream>
#include<math.h>
#include<stack>

using namespace std;

string x[5];
bool visited[5];

void rot(int now, int clock) {
    int i;
    string temp;
    visited[now] = true;
    if (clock == 1) {
        for (i = 0, temp = x[now][7]; i < 7; i++) {
            temp += x[now][i];
        }
    }
    else {
        for (i = 1, temp = ""; i < 8; i++) {
            temp += x[now][i];
        }
        temp += x[now][0];
    }
    if (now > 1 && x[now - 1][2] != x[now][6] &&!visited[now-1]) {
        rot(now-1, clock * (-1));
    }
    if (now < 4 && x[now + 1][6] != x[now][2] && !visited[now + 1]) {
        rot(now+1, clock * (-1));
    }
    x[now] = temp;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> x[1] >> x[2] >> x[3] >> x[4];
    int n, i, what, how;
    cin >> n;
    for (i = 0; i < n; i++) {
        cin >> what >> how;
        fill_n(&visited[0], 5, false);
        rot(what, how);
        //cout<<i << "번째" << endl;
        //cout << x[1] << endl;
        //cout << x[2] << endl;
        //cout << x[3] << endl;
        //cout << x[4] << endl;
    }
    int sum = 0;
    if (x[1][0] == '1') sum++;
    if (x[2][0] == '1') sum += 2;
    if (x[3][0] == '1') sum += 4;
    if (x[4][0] == '1') sum += 8;
    cout << sum;
}
