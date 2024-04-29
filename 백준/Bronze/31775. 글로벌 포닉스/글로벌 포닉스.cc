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

bool arr[3] = { false, false, false };

void find(string x) {
    if (x[0] == 'k') arr[0] = true;
    else if (x[0] == 'l') arr[1] = true;
    else if (x[0] == 'p')arr[2] = true;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    string x, y, z;
    cin >> x >> y >> z;
    find(x); find(y); find(z);
    bool anw = arr[0] && arr[1] && arr[2];
    if (anw) cout << "GLOBAL";
    else cout << "PONIX";

    return 0;
}