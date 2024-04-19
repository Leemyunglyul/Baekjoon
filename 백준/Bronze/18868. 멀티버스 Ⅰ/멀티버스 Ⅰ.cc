#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int arr[13][101];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, m, i, j, k, l;
    cin >> n >> m;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= m; j++) {
            cin >> arr[i][j];
        }
    }
    int sum = 0;
    for (i = 1; i <= n; i++) {
        for (j = i+1; j <= n; j++) {
            bool anw = true;
            for (k = 1; k <= m; k++) {
                for (l = k + 1; l <= m; l++) {
                    if (arr[i][k] > arr[i][l] && arr[j][k] > arr[j][l]);
                    else if (arr[i][k] == arr[i][l] && arr[j][k] == arr[j][l]);
                    else if (arr[i][k] < arr[i][l] && arr[j][k] < arr[j][l]);
                    else {
                        anw = false;
                        break;
                    }
                }
                if (!anw) break;
            }
            if (anw) sum++;
        }
    }
    cout << sum;
}