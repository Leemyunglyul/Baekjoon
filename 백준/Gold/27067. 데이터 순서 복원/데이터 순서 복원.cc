#include <iostream>
#include <cmath>
#include <queue>
#include <vector>
#include <algorithm>
#include <tuple>
#include <string>
#include <map>
#include <set>

using namespace std;

int arr[3][3010];
int print[5010];
int list[3002][3002];
vector<pair<int, int>> v;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, i, x, j, k;
    //첫번째
    cin >> n;
    for (i = 0; i <3; i++) {
        for (j = 1; j <= n; j++) {
            cin >> arr[i][j];
        }
    }
    for (i = 0; i < 3; i++) {
        for (j = 1; j <= n; j++) {
            for (k = 1; k <j; k++) {
                list[arr[i][j]][arr[i][k]]--;
                list[arr[i][k]][arr[i][j]]++;
            }
        }
    }
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            if (list[i][j] > 0) print[i]++;
        }
        v.push_back({ print[i], i });
    }
    sort(v.begin(), v.end());
    for (i = n-1; i >=0; i--) {
        cout << v[i].second << " ";
    }

    return 0;
}