#include <iostream>
#include <cmath>

using namespace std;

int arr[10010][510];
int run[10010];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, m, i, j;
    cin >> n >> m;
    for (i = 1; i <= n; i++) {
        cin >> run[i];
    }
    fill_n(&arr[0][0], 10010 * 510, -1);
    for (i = 0, arr[0][0]=0; i <= n-1; i++) {
        for (j = 0; j <= m; j++) {
            //cout << arr[i][j] << " ";
            if (arr[i][j] == -1) continue;
            if (j==0) {
                arr[i + 1][0] = max(arr[i + 1][0], arr[i][j]);
            }
            else if (i + j <= n) {
                arr[i + j][0] = max(arr[i + j][0], arr[i][j]);
            }
            if (j < m) {
                arr[i+1][j+1]= max(arr[i + 1][j+1], arr[i][j]+run[i+1]);
            }

        }
        //cout << endl;
    }
    cout << arr[n][0];

    return 0;
}