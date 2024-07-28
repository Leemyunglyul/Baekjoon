#include <iostream>
#include <cmath>
#include <queue>
#include <vector>
#include <tuple>
#include <stack>
#include <algorithm>
#include <map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    long long sum, n, i, j;
    cin >> n;
    for (i = 1, sum=0; i <= n; i++) {
        sum += i;
    }
    cout << sum << endl << sum * sum << endl;
    for (i = 1, sum = 0; i <= n; i++) {
        sum += i*i*i;
    }
    cout << sum;
}