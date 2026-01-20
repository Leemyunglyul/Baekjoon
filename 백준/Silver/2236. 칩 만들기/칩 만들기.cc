#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <string>

using namespace std;

int arr[52];
vector<pair<int, int>> vp;
bool visited[52];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k, i, j;
    fill_n(&visited[0], 52, false);

    cin>> n >> k;
    for(i = 0; i < n; i++) {
        cin >> arr[i];
        vp.push_back({arr[i], i + 1});
    }
    sort(vp.begin(), vp.end(), greater<pair<int, int>>());
    for(i = 0; i < k; i++) {
        cout << vp[i].second << "\n";
        visited[vp[i].second] = true;
    }
    for(i = 1; i <= n; i++) {
        if(visited[i]) {
            cout << i << "\n";
        }
        else cout<<0<<"\n";
    }
    


    return 0;
}