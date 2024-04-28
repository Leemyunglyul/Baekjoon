#include <iostream>
#include <cmath>
#include <queue>
#include <vector>
#include <algorithm>
#include <tuple>
#include <string>
#include <map>
#include <set>
#include <numeric>

using namespace std;

int arr[3002], n;

int gcd(int x, int y) {
    if (y == 0) return x;
    else return gcd(y, x % y);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int i, x, j, k, cmp;
    cin >> n;
    for (i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    
    for (i = 1; i <= n; i++) {
        cmp = i;
        for (j = i-1; j >=1; j--) {
            if (gcd(max(arr[j], arr[i]), min(arr[j], arr[i])) != 1) break;
            if (arr[j] > arr[i]) cmp = j;
        }
        if (cmp == i) continue;
        int temp = arr[i];
        for (j = i-1; j>=cmp; j--) {
            arr[j + 1] = arr[j];
        }
        arr[cmp] = temp;
    }   
    for (i = 1; i <= n; i++) cout << arr[i] << " ";

    return 0;
}