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
    string x;
    int i, sum;
    cin >> x;
    for (i = 0, sum=0; i < x.size(); i++) {
        if (i == 0) sum += 10;
        else if (x[i] == x[i - 1]) sum += 5;
        else sum += 10;
    }
    cout << sum;

    return 0;
}