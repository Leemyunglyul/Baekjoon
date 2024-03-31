#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <climits>
#include <cmath>
#include <algorithm>

using namespace std;

int arr[200010];

int check(int x) {
    while (x % 2 == 0) x = x / 2;
    return x;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int i, j, n, pre, sum, temp;
    cin >> n;
    for (i = 1; i <= n; i++) {
        cin >> arr[i];
        arr[i] = check(arr[i]);
    }
    sort(arr + 1, arr + n + 1);
    for (i = 1, sum=1; i <= n+1; i++) {
        if (i == 1) {
            temp = 1;
            pre = arr[i];
        }
        else if (i == n + 1) {
            sum = max(sum, temp);
        }
        else if (arr[i] == pre) {
            temp++;
        }
        else {
            sum = max(sum, temp);
            temp = 1;
            pre = arr[i];
        }
    }
    cout << sum;
}