#include <iostream>
#include <cmath>
#include <string>
#include <vector>


using namespace std;

int ran[27] = { 0 };
int n, len;
vector<int> node[27];
int dp[27] = { 0 };
int big = 0;

int dfs(int x) {
    int i, sum;
    for (i = 0, sum=1; i < node[x].size(); i++) {
        if (dp[node[x][i]] > 0) sum = max(sum, dp[node[x][i]] + 1);
        else sum = max(sum, dfs(node[x][i]) + 1);
    }
    dp[x] = sum;
    return sum;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int  i, j, s, d, k, temp;
    string x, y;
    cin >> n>>len;
    int all = (1 << len) - 1 ;
    fill_n(&ran[0], 27, all);
    for (j = 0; j < n; j++) {
        cin >> x;
        for (i = 0, temp = all; i < len; i++) {
            temp &= ~(1 << (x[i] - 65));
            ran[x[i]-65] &= temp;
        }
    }
    for (i = 0; i < len; i++) {
        for (j = 0; j < len; j++) {
            temp = 1 << j;
            if (temp & ran[i]) {
                node[i].push_back(j);
            }
        }
    }
    for (i = 0; i < len; i++) {
        if (dp[i] == 0) dfs(i);
        big = max(big, dp[i]);
    }
    cout << big;
}