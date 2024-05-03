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

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, a, b;
    cin >> n;
    a = 0;
    while (n % 2 == 0) {
        n /= 2;
        a++;
    }
    cout << n << " " << a;
}