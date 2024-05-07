#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
#include <map>

using namespace std;

bool arr[40010];
bool check[33][16000];
vector<int> w;
vector<int> wlist;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, i, j, x;
    cin >> n;
    w.push_back(0);
    for (i = 1; i <= n; i++) {
        cin >> x;
        w.push_back(x);
    }
    fill_n(&arr[0], 40010, false);
    fill_n(&check[0][0], 33 * 16000, false);
    for (i = 1, check[0][0]=true; i <= n; i++) {
        for (j = 0; j <= 15000; j++) {
            if (check[i - 1][j]) {
                check[i][j] = true;
                check[i][j + w[i]] = true;
            }
        }
    }
    for (i = 1; i <= 15000; i++) {
        if (check[n][i]) {
            wlist.push_back(i);
            arr[i] = true;
        }
    }
    for (i = wlist.size() - 1; i >= 0; i--) {
        for (j = i - 1; j >= 0; j--) {
            arr[wlist[i] - wlist[j]] = true;
        }
    }
    cin >> n;
    while (n--) {
        cin >> x;
        if (arr[x]) cout << "Y ";
        else cout << "N ";
    }
}