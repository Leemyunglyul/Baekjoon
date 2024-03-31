#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <climits>
#include <cmath>
#include <algorithm>

using namespace std;

int arr[3][2];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int health, i, j;
    for (i = 0; i < 3; i++) {
        cin >> arr[i][0] >> arr[i][1];
    }
    cin >> health;
    int t = 0;
    while (1) {
        if (t % arr[0][0] == 0) health -= arr[0][1];
        if (t % arr[1][0] == 0) health -= arr[1][1];
        if (t % arr[2][0] == 0) health -= arr[2][1];

        if (health <= 0) break;
        t++;
    }
    cout << t;
}