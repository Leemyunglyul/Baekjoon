#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <string>
#include <stack>
#include <map>
#include <regex>

using namespace std;

void solve() {
    string s;
    cin >> s;
    int n = s.length();

    if (n == 1) {
        cout << "1 2\n";
        return;
    }

    long long count = 2; 

    bool allSame = true;
    for (int i = 1; i < n; i++) {
        if (s[i] != s[0]) {
            allSame = false;
            break;
        }
    }

    if (allSame) {
        count += 2;
    }

    if (n == 2) {
        count += 4;
    }

    cout << "2 " << count << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int q;
    cin >> q;
    while (q--) {
        solve();
    }
    
    return 0;
}