#include <iostream>
#include <cmath>
#include <queue>
#include <vector>
#include <algorithm>
#include <tuple>
#include <string>
#include <map>

using namespace std;

int arr[11][11], n, m;
int anw = -1;

bool check(int x) {
    double y = sqrt(x);
    double z = int(y);
    if (y == z) return true;
    else return false;
}

void make(int lim1,int lim2, string x, int r, int c) {
    int i, j;
    if (r > n || c > m || r<1 || c<1) return;

    x += to_string(arr[r][c]);
    if(check(stoi(x))) anw = max(anw, stoi(x));
    //cout << stoi(x) << endl;
    if (r + lim1 == r && c + lim2==c) return;
    make(lim1, lim2, x, r + lim1, c + lim2);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    int i, j, lim, k, l;
    char x;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= m; j++) {
            cin >> x;
            arr[i][j] = x - 48;
        }
    }
    string y = "";
    for (i = -(n-1); i <= n-1; i++) {
        for (l = -(m-1); l <= m - 1; l++) {
            for (j = 1; j <= n; j++) {
                for (k = 1; k <= m; k++) {
                    make(i, l, "", j, k);
                }
            }
        }
    }
    cout << anw;


    return 0;
}