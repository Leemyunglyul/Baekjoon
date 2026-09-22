#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;
using ll = long long;

void solve() {
    int n, m, i, j;
    string s[3];
    int same, diff;
    int num[3];

    cin >> n;

    for(i=0;i<=2;i++){
        cin>>s[i];
        num[i] = 0;
    }

    

    for(i=0, same=0, diff=0;i<n;i++){
        if(s[0][i] == s[1][i] && s[1][i] == s[2][i]) same++;
        else if(s[0][i] == s[1][i]) num[2]++;
        else if(s[0][i] == s[2][i]) num[1]++;
        else if(s[2][i] == s[1][i]) num[0]++;
        else diff++;
    }

    int sum = num[0] + num[1] + num[2];
    int least = min({num[0], num[1], num[2]});

    int answer = same + min(
        (2 * sum + diff) / 3,
        (sum + least + diff) / 2
    );


    cout << answer << '\n';

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    for (int tc = 1; tc <= T; ++tc) {
        cout << "#" << tc << " ";
        solve();
    }

    return 0;
}